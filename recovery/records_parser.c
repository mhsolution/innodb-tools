#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <sys/dir.h>

#include "univ.i"
#include "page0page.h"
#include "rem0rec.h"

#include "error.h"
#include "common.h"

void read_ibpage(char *file_name, page_t *page) {
	int fn;
	
	fn = open(file_name, O_RDONLY, 0);
	if (!fn) error("Can't open page file!");
	if (read(fn, page, UNIV_PAGE_SIZE) != UNIV_PAGE_SIZE) error("Can't read full page!");
}

void process_ibrec(rec_t *rec, page_t *page) {
	ulint info_bits, data_size;
	int fields_number, i;
	
	printf("Processing record %p\n", rec);
	
	fields_number = rec_get_n_fields(rec);
	printf("Fields number: %lu\n", fields_number);
	
	data_size = rec_get_data_size(rec);
	printf("Data size: %lu\n", data_size);
	
	printf("Offset fields size: %d\n", rec_get_1byte_offs_flag(rec));
	printf("Deleted flag: %d\n", rec_get_deleted_flag(rec));
	
	info_bits = rec_get_info_bits(rec);
	for(i = 0; i < fields_number; i++) {
		ulint len;
		byte *field;
		
		field = rec_get_nth_field(rec, i, &len);
		if (len != UNIV_SQL_NULL) {
    		printf("- Field #%d. Size = %lu, Ptr = %p, Offset = %lu: ", i, len, field, field-page);
    		ut_print_buf(stdout, field, len);
		} else {
			printf("- Field #%d. Size = NULL, Ptr = NULL, Offset = NULL: NULL", i, len, field, field-page);
		}
		printf("\n");
	}
}

void process_ibpage(page_t *page) {
	ulint page_id;
	rec_t *free_rec;
	ulint offset;
	
	page_id = mach_read_from_4(page + FIL_PAGE_OFFSET);
	printf("Page id: %lu\n", page_id);

	if (!page_is_interesting(page)) {
		printf("Warning: not interesting page, skipping it.\n");
		return;
	}

	offset = page_header_get_field(page, PAGE_FREE);
	while(offset > 0) {
		// Get record pointer
		free_rec = page + offset;
		printf("\nPAGE%lu: Found free record: %p (offset = %lu)\n", page_id, free_rec, offset);

		// Process record found
		process_ibrec(free_rec, page);

		offset = rec_get_next_offs(free_rec);
	}
	
}

void process_pages_dir(char *dir_name) {
	DIR *dir;
	struct dirent *entry;
	char *ext;
	char full_name[250];
	page_t *page;

	// Alloc page buffer
	page = malloc(UNIV_PAGE_SIZE);
	if (!page) error("Can't alloc page buffer!");

	// Open table directory
	dir = opendir(dir_name);
	if (!dir) error("Can't open directory!");
	
	printf("Reading directory: %s\n", dir_name);

	// Scan the entire dir
	while ((entry = readdir(dir)) != NULL) {
		ext = strstr(entry->d_name, ".page");
		
		// Skip all files excape a files with .page extension
		if (entry->d_type != DT_REG || ext == NULL) {
			printf("Skipping dir entry: %s\n", entry->d_name);
			continue;
		}
		
		printf("Processing page file: %s\n", entry->d_name);

		// Compose full file path
		sprintf(full_name, "%s/%s", dir_name, entry->d_name);
		
		// Read and process the page
		read_ibpage(full_name, page);
		process_ibpage(page);
	}
	
	// Free resources
	closedir(dir);
	free(page);
}

bool deleted_pages_only = 0;

int main(int argc, char **argv) {
	if (argc < 2) error("Usage: ./records_parser <innodb_pages_dir>");

	process_pages_dir(argv[1]);
	
	return 0;
}
