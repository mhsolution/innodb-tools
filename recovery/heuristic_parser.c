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

// Table definitions
typedef struct table_def {
	char *name;
	int fields_count;
	int data_min_size;
	int data_max_size;
} table_def_t;

table_def_t table_definitions[] = {
	{ "test_int", 3, 4+6+7, 4+6+7 },
	{ "test_string", 3+1, 6+6+7+32, 6+6+7+32 },
	{ "test_string2", 3+2, 6+6+7+10+5, 6+6+7+10+5 }
};

int table_definitions_cnt = 3;

/*******************************************************************/
void read_ibpage(char *file_name, page_t *page) {
	int fn;
	
	fn = open(file_name, O_RDONLY, 0);
	if (!fn) error("Can't open page file!");
	if (read(fn, page, UNIV_PAGE_SIZE) != UNIV_PAGE_SIZE) error("Can't read full page!");
}

/*******************************************************************/
ulint process_ibrec(rec_t *rec, page_t *page) {
	ulint info_bits, data_size;
	int fields_number, i;
	
	printf("Processing record %p\n", rec);
	
	fields_number = rec_get_n_fields(rec);
	printf("Fields number: %lu\n", fields_number);
	
	data_size = rec_get_data_size(rec);
	printf("Data size: %lu\n", data_size);

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

	return data_size; //point to the next possible record's start
}

/*******************************************************************
Validates the consistency of a physical record. */

ulint rec_dummy; // to prevent compiler warnings
ibool ibrec_validate(rec_t* rec) {
	byte*	data;
	ulint	len;
	ulint	n_fields;
	ulint	len_sum	= 0;
	ulint	sum	= 0;
	ulint	i;

	if (!rec) return FALSE;
	n_fields = rec_get_n_fields(rec);

	if ((n_fields == 0) || (n_fields > REC_MAX_N_FIELDS)) return FALSE;
	
	for (i = 0; i < n_fields; i++) {
		data = rec_get_nth_field(rec, i, &len);
		
		if (!((len < UNIV_PAGE_SIZE) || (len == UNIV_SQL_NULL))) return FALSE;

		if (len != UNIV_SQL_NULL) {
			len_sum += len;
			sum += *(data + len - 1);  // dereference the end of the field to cause a memory trap if possible
		} else {
			len_sum += rec_get_nth_field_size(rec, i);
		}
	}

	if (len_sum != (ulint)(rec_get_end(rec) - rec)) {
		return FALSE;
	}	
	
	rec_dummy = sum; // This is here only to fool the compiler 

	return TRUE;
}

/*******************************************************************/
rec_t* check_for_a_record(rec_t *rec_start, ulint offsets_size, table_def_t *table) {
	rec_t *rec;
	int data_size;

	// Get a possible record origin
	rec = rec_start + offsets_size * table->fields_count + REC_N_EXTRA_BYTES;

	// Skip if bit count flag is incorrect
	if (rec_get_1byte_offs_flag(rec) != (offsets_size == 1)) return FALSE;

	// Check fields count
	if (rec_get_n_fields(rec) != table->fields_count) return FALSE;
	
	// Skip non-deleted records
	if (!rec_get_deleted_flag(rec)) return FALSE;

	// Check the record's data size
	data_size = rec_get_data_size(rec);
	if (data_size > table->data_max_size || data_size < table->data_min_size) return FALSE;

	// Check the record for validity by innodb's function
	if (!ibrec_validate(rec)) return FALSE;
	
	// FIXME: do we need to check our field values?
	
	// This record could be valid and useful
	return rec;
}

/*******************************************************************/
void process_ibpage(page_t *page) {
	ulint page_id;
	rec_t *rec, *rec_start;
	ulint offset, rec_size, i;
	
	page_id = mach_read_from_4(page + FIL_PAGE_OFFSET);
	printf("Page id: %lu\n", page_id);

	// Find possible data area start point (end of supremum + 6 bytes of extra + at least 3 offsets)
	offset = 0; 
	printf("Starting offset: %lu\n", offset);
	
	// Walk through all possible positions to the end of page 
	// (start of directory - extra bytes of the last rec)
	while (offset < UNIV_PAGE_SIZE - 6 - 1) {
		// Get record pointer
		rec_start = page + offset;
		rec = 0;
		
		// Check all tables
		for (i = 0; i < table_definitions_cnt; i++) {
			table_def_t table = table_definitions[i];

			// check for a record with 1 byte offsets
			rec = check_for_a_record(rec_start, 1, &table);
			if (rec) {
				printf("PAGE%lu: Found a table %s record with 1-byte offsets: %p (offset = %lu)\n", page_id, table.name, rec, rec-page);
				offset += process_ibrec(rec, page);
				break;
			}

			// check for a record with 2 byte offsets
			rec = check_for_a_record(rec_start, 2, &table);
			if (rec) {
				printf("PAGE%lu: Found a table %s record with 2-byte offsets: %p (offset = %lu)\n", page_id, table.name, rec, rec-page);
				offset += process_ibrec(rec, page);
				break;
			}
		}

		// Check from next byte
		if (!rec) offset++;
	}
	
}

/*******************************************************************/
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
		if (entry->d_type != DT_REG || entry->d_name + entry->d_namlen - ext > 5) {
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

/*******************************************************************/
int main(int argc, char **argv) {
	if (argc < 2) error("Usage: ./records_parser <innodb_pages_dir>");

	process_pages_dir(argv[1]);
	
	printf("Processing finished successfully!\n\n");
	
	return 0;
}
