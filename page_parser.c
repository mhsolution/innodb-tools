#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#include "univ.i"
#include "page0page.h"

#include "error.h"
#include "common.h"

static time_t timestamp = 0;

void process_ibpage(page_t *page) {
	ulint page_id;
	dulint index_id;
	char tmp[256];
	int fn;
	
	// Get page info
	page_id = mach_read_from_4(page + FIL_PAGE_OFFSET);
	index_id = mach_read_from_8(page + PAGE_HEADER + PAGE_INDEX_ID);
			
	// Create table directory
	sprintf(tmp, "pages-%u/%lu-%lu", timestamp, index_id.high, index_id.low);
	mkdir(tmp, 0755);
	
	// Compose page file_name
	sprintf(tmp, "pages-%u/%lu-%lu/%08lu.page", timestamp, index_id.high, index_id.low, page_id);
	
	printf("Read page #%lu.. saving it to %s\n", page_id, tmp);

	// Save page data
	fn = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fn) error("Can't open file to save page!");
	write(fn, page, UNIV_PAGE_SIZE);
	close(fn);	
}

void process_ibfile(int fn) {
	int read_bytes;
	page_t *page = malloc(UNIV_PAGE_SIZE);
	char tmp[20];
	
	if (!page) error("Can't allocate page buffer!");

	// Create pages directory
	timestamp = time(0);
	sprintf(tmp, "pages-%u", timestamp);
	mkdir(tmp, 0755);
	
	printf("Read data from fn=%d...\n", fn);

	// Read pages to the end of file
	while ((read_bytes = read(fn, page, UNIV_PAGE_SIZE)) == UNIV_PAGE_SIZE) {
		if (page_is_interesting(page)) process_ibpage(page);
	}
}

int open_ibfile(char *fname) {
	struct stat fstat;
	int fn;

	// Disallow Skip non-regular files
	printf("Opening file: %s\n", fname);
	if (stat(fname, &fstat) != 0 || (fstat.st_mode & S_IFREG) != S_IFREG) error("Invalid file specified!");
	fn = open(fname, O_RDONLY, 0);
	if (!fn) error("Can't open file!");
	
	return fn;
}

void usage() {
	error(
	  "Usage: ./page_parser [-dDh] -f <innodb_datafile>\n"
	  "  Where\n"
	  "    -h  -- Print this help\n"
	  "    -d  -- Process only those pages which potentially could have deleted records (default = NO)\n"
	  "    -D  -- Recover deleted rows only (default = NO)\n\n"
	);
}

// Global flags from getopt
bool deleted_pages_only = 0;
bool deleted_records_only = 0;

int main(int argc, char **argv) {
	int fn = 0, ch;

	while ((ch = getopt(argc, argv, "hdDf:")) != -1) {
		switch (ch) {
			case 'd':
				deleted_pages_only = 1;
				break;

			case 'D':
			    deleted_records_only = 1;
				break;

			case 'f':
				fn = open_ibfile(optarg);
				break;

			default:
			case '?':
			case 'h':
				usage();
		}
	}

	if (fn != 0) {
		process_ibfile(fn);
		close(fn);
	} else usage();
	
	process_ibfile(fn);
	close(fn);
	
	return 0;
}
