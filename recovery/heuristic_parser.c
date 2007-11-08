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
#include "table_defs.h"

// Global flags from getopt
bool deleted_pages_only = 0;
bool deleted_records_only = 0;


/*******************************************************************/
void read_ibpage(char *file_name, page_t *page) {
	int fn;
	
	fn = open(file_name, O_RDONLY, 0);
	if (!fn) error("Can't open page file!");
	if (read(fn, page, UNIV_PAGE_SIZE) != UNIV_PAGE_SIZE) error("Can't read full page!");
}

/*******************************************************************/
inline ulonglong make_ulonglong(dulint x) {
	ulonglong lx = x.high;
	lx <<= 32;
	lx += x.low;
	return lx;
}

/*******************************************************************/
inline longlong make_longlong(dulint x) {
	longlong lx = x.high;
	lx <<= 32;
	lx += x.low;
	return lx;
}

/*******************************************************************/
void print_datetime(ulonglong ldate) {
	int year, month, day, hour, min, sec;
	
	ldate &= ~(1ULL << 63);
	
	sec = ldate % 100; ldate /= 100;
	min = ldate % 100; ldate /= 100;
	hour = ldate % 100; ldate /= 100;
	day = ldate % 100; ldate /= 100;
	month = ldate % 100; ldate /= 100;
	year = ldate % 10000;
	
	printf("\"%04u-%02u-%02u %02u:%02u:%02u\"", year, month, day, hour, min, sec);
}

/*******************************************************************/
void print_date(ulonglong ldate) {
	int year, month, day;

	ldate &= ~(1ULL << 63);
	
	ldate /= 100;
	ldate /= 100;
	ldate /= 100;
	day = ldate % 100; ldate /= 100;
	month = ldate % 100; ldate /= 100;
	year = ldate % 10000;
	
	printf("\"%04u-%02u-%02u\"", year, month, day);
}


/*******************************************************************/
void print_field_value(byte *value, ulint len, field_def_t *field) {
	int i;
	
//	printf("%s=", field->name);
	
	switch (field->type) {
		case FT_INTERNAL:
    		break;

		case FT_CHAR:
    		printf("\"");
		    for(i = 0; i < len; i++) {
				if (value[i] == '"') printf("\\\"");
				else if (value[i] == '\n') printf("\\n");
				else printf("%c", value[i]);
    		}
    		printf("\"");
			break;

		case FT_UINT:
			switch (field->max_length) {
				case 1: printf("%u", mach_read_from_1(value)); break;
				case 2: printf("%u", mach_read_from_2(value)); break;
				case 4: printf("%lu", mach_read_from_4(value)); break;
				case 8: printf("%llu", make_ulonglong(mach_read_from_8(value))); break;
				default: printf("uint_undef(%d)", field->max_length);
			}
			break;

		case FT_INT:
			switch (field->max_length) {
				case 1: printf("%d", mach_read_from_1(value) ^ 1<<7); break;
				case 2: printf("%i", mach_read_from_2(value) ^ 1<<15); break;
				case 4: printf("%li", mach_read_from_4(value) ^ 1L<<31); break;
				case 8: printf("%lli", make_longlong(mach_read_from_8(value)) ^ 1LL << 63); break;
				default: printf("int_undef(%d)", field->max_length);
			}
			break;

		case FT_FLOAT:
			printf("%f", mach_float_read(value)); break;
			break;

		case FT_DOUBLE:
			printf("%lf", mach_double_read(value)); break;
			break;

		case FT_DATETIME:
			print_datetime(make_longlong(mach_read_from_8(value)));
			break;

		case FT_DATE:
			print_date(make_longlong(mach_read_from_8(value)));
			break;

		default:
    		printf("undef(%d)", field->type);
	}

//	printf(" ("); ut_print_buf(stdout, value, len); printf(" )");
}

/*******************************************************************/
ulint process_ibrec(rec_t *rec, page_t *page, table_def_t *table) {
	ulint info_bits, data_size;
	int fields_number, i;

	// Print table name
	printf("%s\t", table->name);
	
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
		
		if (table->fields[i].type == FT_INTERNAL) continue;
		
		field = rec_get_nth_field(rec, i, &len);
		printf("Field #%i: length %lu\n", i, len);
		if (len == UNIV_SQL_NULL) {
			printf("NULL");
		} else {
			print_field_value(field, len, &(table->fields[i]));
		}
		
		if (i < fields_number - 1) printf("\t");
	}
	printf("\n");

	return data_size; //point to the next possible record's start
}

/*******************************************************************
Validates the consistency of a physical record. */

ibool ibrec_validate(page_t *page, rec_t* rec) {
	byte*	data;
	ulint	len;
	ulint	n_fields;
	ulint	len_sum	= 0;
	ulint	i;

	if (!rec) return FALSE;
	n_fields = rec_get_n_fields(rec);

	if ((n_fields == 0) || (n_fields > REC_MAX_N_FIELDS)) return FALSE;
	
	for (i = 0; i < n_fields; i++) {
		data = rec_get_nth_field(rec, i, &len);
		
		if (!((len < UNIV_PAGE_SIZE) || (len == UNIV_SQL_NULL))) return FALSE;

		if (len != UNIV_SQL_NULL) {
			len_sum += len;
			if (data + len - 1 > page + UNIV_PAGE_SIZE) return FALSE;
		} else {
			len_sum += rec_get_nth_field_size(rec, i);
		}
	}

	if (len_sum != (ulint)(rec_get_end(rec) - rec)) {
		return FALSE;
	}	
	
	return TRUE;
}

/*******************************************************************/
ibool check_datetime(ulonglong ldate) {
	int year, month, day, hour, min, sec;
	
	ldate &= ~(1ULL << 63);
	
	sec = ldate % 100; ldate /= 100;
	if (sec < 0 || sec > 59) return FALSE;
	
	min = ldate % 100; ldate /= 100;
	if (min < 0 || min > 59) return FALSE;
	
	hour = ldate % 100; ldate /= 100;
	if (hour < 0 || hour > 23) return FALSE;

	day = ldate % 100; ldate /= 100;
	if (day < 0 || day > 31) return FALSE;

	month = ldate % 100; ldate /= 100;
	if (month < 1 || month > 12) return FALSE;

	year = ldate % 10000;
	if (year < 0 || year > 2099) return FALSE;

	return TRUE;
}

/*******************************************************************/
ibool check_fields_sizes(rec_t *rec, table_def_t *table) {
	int i;
	
	// check every field
	for(i = 0; i < table->fields_count; i++) {
		ulint len;
		byte *field;
		
		field = rec_get_nth_field(rec, i, &len);
		printf("Checking field #%d/%d, %s[%lu, %lu] vs %lu...\n", i, table->fields_count, table->fields[i].name, table->fields[i].min_length, table->fields[i].max_length, len);
		if (len == UNIV_SQL_NULL && table->fields[i].min_length == 0) continue;
		if (len < table->fields[i].min_length || len > table->fields[i].max_length) return FALSE;

		//FIXME: need to check more data ranges
		if (table->fields[i].type == FT_DATETIME || table->fields[i].type == FT_DATE) {
			if (!check_datetime(make_longlong(mach_read_from_8(field)))) return FALSE;
		}
	}
	
	printf("\n");
	return TRUE;
}

/*******************************************************************/
rec_t* check_for_a_record(page_t *page, rec_t *rec_start, ulint offsets_size, table_def_t *table) {
	rec_t *rec;
	int data_size;

	// Get a possible record origin
	rec = rec_start + offsets_size * table->fields_count + REC_N_EXTRA_BYTES;
	if (rec-page == 138 && offsets_size == 2) return rec;

	// Check record bounds
	if (rec - page >= UNIV_PAGE_SIZE - table->data_min_size - 1) return FALSE;
	printf("0 ");

	// Skip if bit count flag is incorrect
	if (rec_get_1byte_offs_flag(rec) != (offsets_size == 1)) return FALSE;
	printf("1 ");

	// Check fields count
	if (rec_get_n_fields(rec) != table->fields_count) return FALSE;
	printf("2 ");
	
	// Skip non-deleted records
	if (deleted_records_only && !rec_get_deleted_flag(rec)) return FALSE;
	printf("3 ");

	// Check the record's data size
	data_size = rec_get_data_size(rec);
//	if (data_size > table->data_max_size || data_size < table->data_min_size) {
//		printf("Table '%s' record: size %lu is out of bounds [%lu, %lu]\n", table->name, data_size, table->data_min_size, table->data_max_size);
//		return FALSE;
//	}
//	printf("4 ");

	// Check the record for validity by innodb's function
//	if (!ibrec_validate(page, rec)) return FALSE;
//	printf("5 ");
	
	// Check fields sizes and (later) field values
	if (!check_fields_sizes(rec, table)) {
		printf("Table '%s' record: fields sizes check failed\n", table->name);
		return FALSE;
	}
	printf("6 ");
	
	// This record could be valid and useful
	return rec;
}

/*******************************************************************/
void process_ibpage(page_t *page) {
	ulint page_id;
	rec_t *rec, *rec_start;
	ulint offset, rec_size, i;
	
	page_id = mach_read_from_4(page + FIL_PAGE_OFFSET);
//	if (page_id != 514) return;
	printf("Page id: %lu\n", page_id);

	if (page_is_comp(page)) {
		printf("Page is compact!\n");
	} else {
		printf("Page is in old format\n");
	}
	return;

	// Find possible data area start point (end of supremum + 6 bytes of extra + at least 3 offsets)
	offset = 0; 
	printf("Starting offset: %lu\n", offset);
	
	// Walk through all possible positions to the end of page 
	// (start of directory - extra bytes of the last rec)
	while (offset < UNIV_PAGE_SIZE - REC_N_EXTRA_BYTES - 1) {
		// Get record pointer
		rec_start = page + offset;
		rec = 0;
		
		// Check all tables
		for (i = 0; i < table_definitions_cnt; i++) {
			table_def_t table = table_definitions[i];

			// check for a record with 1 byte offsets
			printf("%s@%lu[1]: ", table.name, offset);
			rec = check_for_a_record(page, rec_start, 1, &table);
			printf("\n");
			
			if (rec) {
				printf("---------------------------------------------------\n"
				       "PAGE%lu: Found a table %s record with 1-byte offsets: %p (offset = %lu)\n", page_id, table.name, rec, rec-page);
				offset += process_ibrec(rec, page, &table);
				break;
			}

			// check for a record with 2 byte offsets
			printf("%s@%lu[2]: ", table.name, offset);
			rec = check_for_a_record(page, rec_start, 2, &table);
			printf("\n");

			if (rec) {
				printf("---------------------------------------------------\n"
				       "PAGE%lu: Found a table %s record with 2-byte offsets: %p (offset = %lu)\n", page_id, table.name, rec, rec-page);
				offset += process_ibrec(rec, page, &table);
				break;
			}
		}

		// Check from next byte
		if (!rec) offset++;
	}
	
}

void init_table_defs() {
	int i, j;

	for (i = 0; i < table_definitions_cnt; i++) {
		table_def_t *table = &(table_definitions[i]);

		for(j = 0; j < MAX_TABLE_FIELDS; j++) {
			if (table->fields[j].type == FT_NONE) {
				table->fields_count = j;
				break;
			}
			table->data_min_size += table->fields[j].min_length;
			table->data_max_size += table->fields[j].max_length;
		}
	}
}

/*******************************************************************/
void process_ibfile(int fn) {
	int read_bytes;
	page_t *page = malloc(UNIV_PAGE_SIZE);
	char tmp[20];
	
	if (!page) error("Can't allocate page buffer!");

	init_table_defs();

//	printf("Read data from fn=%d...\n", fn);

	// Read pages to the end of file
	while ((read_bytes = read(fn, page, UNIV_PAGE_SIZE)) == UNIV_PAGE_SIZE) {
		if (page_is_interesting(page)) process_ibpage(page);
	}
}

/*******************************************************************/
int open_ibfile(char *fname) {
	struct stat fstat;
	int fn;

	// Disallow Skip non-regular files
//	printf("Opening file: %s\n", fname);
	if (stat(fname, &fstat) != 0 || (fstat.st_mode & S_IFREG) != S_IFREG) error("Invalid file specified!");
	fn = open(fname, O_RDONLY, 0);
	if (!fn) error("Can't open file!");
	
	return fn;
}

void usage() {
	error(
	  "Usage: ./heuristic_parser [-dDh] -f <innodb_datafile>\n"
	  "  Where\n"
	  "    -h  -- Print this help\n"
	  "    -d  -- Process only those pages which potentially could have deleted records (default = NO)\n"
	  "    -D  -- Recover deleted rows only (default = NO)\n\n"
	);
}

/*******************************************************************/
int main(int argc, char **argv) {
	int fn = 0, ch;

	setbuf(stdout, NULL);

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
	
	return 0;
}
