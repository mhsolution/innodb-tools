#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#include "error.h"
#include "tables_dict.h"

static time_t timestamp = 0;

// Global flags from getopt
bool deleted_pages_only = 0;
bool debug = 0;
bool process_compact = 0;
bool process_redundant = 0;

/*******************************************************************/
void process_ibpage(page_t *page) {
    static ulint id = 0;
	ulint page_id;
	dulint index_id;
	char tmp[256];
	int fn;
	
	// Get page info
	page_id = mach_read_from_4(page + FIL_PAGE_OFFSET);
	index_id = mach_read_from_8(page + PAGE_HEADER + PAGE_INDEX_ID);
	
	// Skip empty pages
    //if (index_id.high == 0 && index_id.low == 0) return;
		
	// Create table directory
	sprintf(tmp, "pages-%u/%lu-%lu", timestamp, index_id.high, index_id.low);
	mkdir(tmp, 0755);
	
	// Compose page file_name
	sprintf(tmp, "pages-%u/%lu-%lu/%lu-%08lu.page", timestamp, index_id.high, index_id.low, id++, page_id);
	
	printf("Read page #%lu.. saving it to %s\n", page_id, tmp);

	// Save page data
	fn = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fn) error("Can't open file to save page!");
	write(fn, page, UNIV_PAGE_SIZE);
	close(fn);	
}

/*******************************************************************/
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
//	    if (deleted_pages_only) {
//    		free_offset = page_header_get_field(page, PAGE_FREE);
//    		if (page_header_get_field(page, PAGE_N_RECS) == 0 && free_offset == 0) continue;
//    		if (free_offset > 0 && page_header_get_field(page, PAGE_GARBAGE) == 0) continue;
//    		if (free_offset > UNIV_PAGE_SIZE) continue;
//    	}
		process_ibpage(page);
	}
}

/*******************************************************************/
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

/*******************************************************************/
void usage() {
	error(
	  "Usage: ./page_parser -4|-5 [-dDh] -f <innodb_datafile>\n"
	  "  Where\n"
	  "    -h  -- Print this help\n"
	  "    -d  -- Process only those pages which potentially could have deleted records (default = NO)\n"
	  "    -4  -- innodb_datafile is in REDUNDANT format\n"
	  "    -5  -- innodb_datafile is in COMPACT format\n"
	);
}

/*******************************************************************/
int main(int argc, char **argv) {
	int fn = 0, ch;

	while ((ch = getopt(argc, argv, "45Vhdf:")) != -1) {
		switch (ch) {
			case 'd':
				deleted_pages_only = 1;
				break;

			case 'f':
				fn = open_ibfile(optarg);
				break;

			case 'V':
				debug = 1;
				break;

            case '4':
                process_redundant = 1;
                break;

            case '5':
                process_compact = 1;
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

	if (!process_compact && !process_redundant) {
        printf("Error: Please, specify what format your datafile in. Use -4 for mysql 4.1 and below and -5 for 5.X+\n");
        usage();
	}
	
	process_ibfile(fn);
	close(fn);
	
	return 0;
}
