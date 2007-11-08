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
ulint process_ibrec(page_t *page, rec_t *rec, table_def_t *table, ulint *offsets) {
	ulint info_bits, data_size;
	int fields_number, i;

	// Print table name
//	printf("%s\t", table->name);
	printf("Processing record %p from table '%s'\n", rec, table->name);

	data_size = rec_offs_data_size(offsets);

/*	
	fields_number = rec_get_n_fields(rec);
	printf("Fields number: %lu\n", fields_number);
	

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
*/
	return data_size; // point to the next possible record's start
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
	if (year < 1980 || year > 2099) return FALSE;

	return TRUE;
}

//FIXME: need to check more data ranges

/*******************************************************************/
static ibool check_constraints(rec_t *rec, table_def_t* table, ulint* offsets) {
	int i;
	
	// Check every field
	for(i = 0; i < table->fields_count; i++) {
		// Get field value pointer and field length
		ulint len;
		byte *field = rec_get_nth_field(rec, offsets, i, &len);
		
		// Validate date fields
		if (table->fields[i].type == FT_DATETIME || table->fields[i].type == FT_DATE) {
			if (!check_datetime(make_longlong(mach_read_from_8(field)))) return FALSE;
		}
	}
	
	return TRUE;
}

/*******************************************************************/
ibool check_fields_sizes(rec_t *rec, table_def_t *table, ulint *offsets) {
	int i;
	
	// check every field
	for(i = 0; i < table->fields_count; i++) {
		// Get field size
		ulint len = rec_offs_nth_size(offsets, i);
		
		// If field is null
		if (len == UNIV_SQL_NULL) {
			// Check if it can be null and jump to a next field if it is OK
			if (table->fields[i].can_be_null) continue;
			// Invalid record where non-nullable field is NULL
			return FALSE;
		} 
		
		// Check size of fixed-length field
		if (table->fields[i].fixed_length) {
			// Check if size is the same and jump to the next field if it is OK
			if (len == table->fields[i].fixed_length) continue;
			// Invalid fixed length field
			return FALSE;
		}
		
		// Check size limits for varlen fields
		if (len < table->fields[i].min_length || len > table->fields[i].max_length) return FALSE;
	}
	
	return TRUE;
}

/*******************************************************************/
static ibool ibrec_init_offsets(page_t *page, rec_t* rec, table_def_t* table, ulint* offsets) {
	ulint i = 0;
	ulint offs;
	const byte* nulls;
	const byte* lens;
	ulint null_mask;
	ulint status = rec_get_status(rec);

	// Skip non-ordinary records
	if (status != REC_STATUS_ORDINARY) return FALSE;
	
	// Init first bytes
	rec_offs_set_n_fields(offsets, table->fields_count);
	
	nulls = rec - (REC_N_NEW_EXTRA_BYTES + 1);
	lens = nulls - (table->n_nullable + 7) / 8;
	offs = 0;
	null_mask = 1;
	
	// First field is 0 bytes from origin point
	rec_offs_base(offsets)[0] = 0;
	
	/* read the lengths of fields 0..n */
	do {
		ulint	len;
		field_def_t *field = &(table->fields[i]);

		/* nullable field => read the null flag */
		if (field->can_be_null) {

			if (!(byte)null_mask) {
				nulls--;
				null_mask = 1;
			}

			if (*nulls & null_mask) {
				null_mask <<= 1;
				/* No length is stored for NULL fields.
				We do not advance offs, and we set
				the length to zero and enable the
				SQL NULL flag in offsets[]. */
				len = offs | REC_OFFS_SQL_NULL;
				goto resolved;
			}
			null_mask <<= 1;
		}

		if (!field->fixed_length) {
			/* Variable-length field: read the length */
			len = *lens--;

			if (field->max_length > 255 || field->type == FT_BLOB) {
				if (len & 0x80) {
					/* 1exxxxxxx xxxxxxxx */
					len <<= 8;
					len |= *lens--;

					offs += len & 0x3fff;
					if (len	& 0x4000) {
						len = offs | REC_OFFS_EXTERNAL;
					} else {
						len = offs;
					}

					goto resolved;
				}
			}

			len = offs += len;
		} else {
			len = offs += field->fixed_length;
		}
	resolved:
		rec_offs_base(offsets)[i + 1] = len;
	} while (++i < table->fields_count);
}



/*******************************************************************/
ibool check_for_a_record(page_t *page, rec_t *rec, table_def_t *table, ulint *offsets) {
	ulint offset, data_size;
	ibool ok;

	// Check if given origin is valid
	offset = rec - page;
	if (offset < 5 + table->min_rec_header_len) return FALSE;
	printf("ORIGIN=OK ");

	// Skip if relative pointer to the next record is too large
	if (mach_read_from_2(rec-2) > UNIV_PAGE_SIZE - offset) return FALSE;
	printf("NEXT=OK ");

	// Get field offsets for current table
	if (!(ok = ibrec_init_offsets(page, rec, table, offsets))) return FALSE;
	printf("OFFSETS=OK ");
	
	// Skip non-deleted records
	if (deleted_records_only && !rec_get_deleted_flag(rec, page_is_comp(page))) return FALSE;
	printf("DELETED=OK ");

	// Check the record's data size
	data_size = rec_offs_data_size(offsets);
	if (data_size > table->data_max_size || data_size < table->data_min_size) return FALSE;
	printf("DATA_SIZE=OK ");

	// Check fields sizes
	if (!check_fields_sizes(rec, table, offsets)) return FALSE;
	printf("FIELD_SIZES=OK ");
	
	// This record could be valid and useful for us
	return TRUE;
}

/*******************************************************************/
void process_ibpage(page_t *page) {
	ulint page_id;
	rec_t *origin;
	ulint offsets[MAX_TABLE_FIELDS + 2];
	ulint offset, rec_size, i;
	
	// Read page id
	page_id = mach_read_from_4(page + FIL_PAGE_OFFSET);
	printf("Page id: %lu\n", page_id);

	// At this moment we support COMPACT pages only
	if (!page_is_comp(page)) {
		printf("Page is in old format - skipping\n");
		return;
	}

	// Find possible data area start point (at least 5 bytes of utility data)
	offset = 5;
	printf("Starting offset: %lu\n", offset);
	
	// Walk through all possible positions to the end of page 
	// (start of directory - extra bytes of the last rec)
	while (offset < UNIV_PAGE_SIZE - REC_N_NEW_EXTRA_BYTES - 1) {
		// Get record pointer
		origin = page + offset;
		printf("\nChecking offset: %lu: ", offset);
		
		// Check all tables
		for (i = 0; i < table_definitions_cnt; i++) {
			// Get table info
			table_def_t table = table_definitions[i];

			// Check if origin points to a valid record
			if (check_for_a_record(page, origin, &table, offsets) && check_constraints(origin, &table, offsets)) {
				printf("\n---------------------------------------------------\n"
				       "PAGE%lu: Found a table %s record: %p (offset = %lu)\n", page_id, table.name, origin, offset);
				offset += process_ibrec(page, origin, &table, offsets);
				break;
			}
		}

		// Check from next byte
		offset++;
	}
}

/*******************************************************************/
void init_table_defs() {
	int i, j;

	printf("Initializing table definitions...\n");
	
	for (i = 0; i < table_definitions_cnt; i++) {
		table_def_t *table = &(table_definitions[i]);
		printf("Processing table: %s\n", table->name);
		
		table->n_nullable = 0;
		table->min_rec_header_len = 0;
		
		for(j = 0; j < MAX_TABLE_FIELDS; j++) {
			if (table->fields[j].type == FT_NONE) {
				table->fields_count = j;
				break;
			}
			table->data_min_size += table->fields[j].min_length;
			table->data_max_size += table->fields[j].max_length;
			
			if (table->fields[j].can_be_null) {
				table->n_nullable++;
			} else {
				int size = (table->fields[j].fixed_length ? table->fields[j].fixed_length : table->fields[j].max_length);
				table->min_rec_header_len += (size > 255 ? 2 : 1);
			}
		}
		
		table->min_rec_header_len += (table->n_nullable + 7) / 8;
		
		printf(" - nullable fields: %i\n", table->n_nullable);
		printf(" - minimum header size: %i\n", table->min_rec_header_len);
		printf("\n");
	}
}

/*******************************************************************/
void process_ibfile(int fn) {
	int read_bytes;
	page_t *page = malloc(UNIV_PAGE_SIZE);
	char tmp[20];
	
	if (!page) error("Can't allocate page buffer!");

	init_table_defs();

	printf("Read data from fn=%d...\n", fn);

	// Read pages to the end of file
	while ((read_bytes = read(fn, page, UNIV_PAGE_SIZE)) == UNIV_PAGE_SIZE) {
		if (page_is_interesting(page)) process_ibpage(page);
	}
}

/*******************************************************************/
int open_ibfile(char *fname) {
	struct stat fstat;
	int fn;

	// Skip non-regular files
	printf("Opening file: %s\n", fname);
	if (stat(fname, &fstat) != 0 || (fstat.st_mode & S_IFREG) != S_IFREG) error("Invalid file specified!");
	fn = open(fname, O_RDONLY, 0);
	if (!fn) error("Can't open file!");
	
	return fn;
}

void usage() {
	error(
	  "Usage: ./constraints_parser [-dDh] -f <innodb_datafile>\n"
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
