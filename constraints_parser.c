#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <sys/dir.h>

#include <univ.i>
#include <page0page.h>
#include <rem0rec.h>

#include "error.h"
#include "common.h"
#include "table_defs.h"
#include "print_data.h"
#include "check_data.h"

// Global flags from getopt
bool deleted_pages_only = 0;
bool deleted_records_only = 0;
bool debug = 0;
bool process_redundant = 0;
bool process_compact = 0;

/*******************************************************************/
ulint process_ibrec(page_t *page, rec_t *rec, table_def_t *table, ulint *offsets) {
	ulint info_bits, data_size;
	int i;

	// Print table name
	if (debug) {
		printf("Processing record %p from table '%s'\n", rec, table->name);
		rec_print_new(stdout, rec, offsets);
	} else {
		printf("%s\t", table->name);
	}

	data_size = rec_offs_data_size(offsets);

	for(i = 0; i < table->fields_count; i++) {
		ulint len;
		byte *field = rec_get_nth_field(rec, offsets, i, &len);
		
		if (table->fields[i].type == FT_INTERNAL) continue;
		
		if (debug) printf("Field #%i: length %lu, value: ", i, len);

		if (len == UNIV_SQL_NULL) {
			printf("NULL");
		} else {
			print_field_value(field, len, &(table->fields[i]));
		}
		
		if (i < table->fields_count - 1) printf("\t");
		if (debug) printf("\n");
	}

	printf("\n");
	return data_size; // point to the next possible record's start
}

/*******************************************************************/
static ibool check_constraints(rec_t *rec, table_def_t* table, ulint* offsets) {
	int i;
	
	if (debug) {
		printf("\nChecking constraints for a row (%s):", table->name);
		ut_print_buf(stdout, rec, 100);
	}
	
	// Check every field
	for(i = 0; i < table->fields_count; i++) {
		// Get field value pointer and field length
		ulint len;
		byte *field = rec_get_nth_field(rec, offsets, i, &len);
		if (debug) printf("\n - field %s(%lu):", table->fields[i].name, len);

		// Skip null fields from type checks and fail if null is not allowed by data limits
		if (len == UNIV_SQL_NULL) {
			if (table->fields[i].has_limits && !table->fields[i].limits.can_be_null) {
				if (debug) printf("data can't be NULL");
				return FALSE;
			}
			continue;
		}
		
		// Check limits
		if (!table->fields[i].has_limits) continue;
		if (!check_field_limits(&(table->fields[i]), field, len)) {
			if (debug) printf("LIMITS check failed!\n");
			return FALSE;
		}
	}

	if (debug) printf("\nRow looks OK!\n");
	return TRUE;
}

/*******************************************************************/
ibool check_fields_sizes(rec_t *rec, table_def_t *table, ulint *offsets) {
	int i;

	if (debug) {
		printf("\nChecking field lengths for a row (%s):", table->name);
		printf("OFFSERS: ");
		for(i = 0; i < rec_offs_n_fields(offsets); i++) {
			printf("%lu ", rec_offs_base(offsets)[i]);
		}
//		printf("\n");
	}
	
	// check every field
	for(i = 0; i < table->fields_count; i++) {
		// Get field size
		ulint len = rec_offs_nth_size(offsets, i);
		if (debug) printf("\n - field %s(%lu):", table->fields[i].name, len);
		
		// If field is null
		if (len == UNIV_SQL_NULL) {
			// Check if it can be null and jump to a next field if it is OK
			if (table->fields[i].can_be_null) continue;
			// Invalid record where non-nullable field is NULL
			if (debug) printf("Can't be NULL!\n");
			return FALSE;
		} 
		
		// Check size of fixed-length field
		if (table->fields[i].fixed_length) {
			// Check if size is the same and jump to the next field if it is OK
			if (len == table->fields[i].fixed_length) continue;
			// Invalid fixed length field
			if (debug) printf("Invalid fixed length field!\n");
			return FALSE;
		}
		
		// Check if has externally stored data 
		if (rec_offs_nth_extern(offsets, i)) {
			if (debug) printf("\nEXTERNALLY STORED VALUE FOUND in field %i\n", i);
			if (table->fields[i].type == FT_TEXT || table->fields[i].type == FT_BLOB) continue;
			if (debug) printf("Invalid external data flag!\n");
			return FALSE;
		}
		
		// Check size limits for varlen fields
		if (len < table->fields[i].min_length || len > table->fields[i].max_length) {
			if (debug) printf("Length limits check failed!\n");
			return FALSE;
		}

		if (debug) printf("OK!");
	}

	if (debug) printf("\n");
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

	// First field is 0 bytes from origin point
	rec_offs_base(offsets)[0] = 0;
	
	// Init first bytes
	rec_offs_set_n_fields(offsets, table->fields_count);
	
	nulls = rec - (REC_N_NEW_EXTRA_BYTES + 1);
	lens = nulls - (table->n_nullable + 7) / 8;
	offs = 0;
	null_mask = 1;
	
	/* read the lengths of fields 0..n */
	do {
		ulint	len;
		field_def_t *field = &(table->fields[i]);

		/* nullable field => read the null flag */
		if (field->can_be_null) {
//			if (debug) printf("nullable field => read the null flag\n");
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
//			if (debug) printf("Variable-length field: read the length\n");
			/* Variable-length field: read the length */
			len = *lens--;

			if (field->max_length > 255 || field->type == FT_BLOB || field->type == FT_TEXT) {
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
		if (rec + offs - page > UNIV_PAGE_SIZE) {
			if (debug) printf("Invalid offset for field %i: %li\n", i, offs);
			return FALSE;
		}
//		if (debug) printf("Initializing offset for field #%li: %li\n", i, len);
		rec_offs_base(offsets)[i + 1] = len;
	} while (++i < table->fields_count);

	return TRUE;
}



/*******************************************************************/
ibool check_for_a_record(page_t *page, rec_t *rec, table_def_t *table, ulint *offsets) {
	ulint offset, data_size;

	// Check if given origin is valid
	offset = rec - page;
	if (offset < 5 + table->min_rec_header_len) return FALSE;
	if (debug) printf("ORIGIN=OK ");

	// Skip if relative pointer to the next record is too large
//	if (mach_read_from_2(rec-2) > UNIV_PAGE_SIZE - offset) return FALSE;
//	if (debug) printf("NEXT=OK ");

	// Get field offsets for current table
	if (!ibrec_init_offsets(page, rec, table, offsets)) return FALSE;
	if (debug) printf("OFFSETS=OK ");

	// Skip non-deleted records
	if (deleted_records_only && !rec_get_deleted_flag(rec, page_is_comp(page))) return FALSE;
	if (debug) printf("DELETED=OK ");

	// Check the record's data size
	data_size = rec_offs_data_size(offsets);
	if (data_size > table->data_max_size || data_size < table->data_min_size) return FALSE;
	if (debug) printf("DATA_SIZE=OK ");

	// Check fields sizes
	if (!check_fields_sizes(rec, table, offsets)) return FALSE;
	if (debug) printf("FIELD_SIZES=OK ");
	
	// This record could be valid and useful for us
	printf(""); // STRANGE ERROR if this is removed (function never returns true)
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
	if (debug) printf("Page id: %lu\n", page_id);

	// At this moment we support COMPACT pages only
	if (!page_is_comp(page)) {
		if (debug) printf("Page is in old format - skipping\n");
		return;
	}

	// Find possible data area start point (at least 5 bytes of utility data)
	offset = 5;
//	offset = 0x9B;
	if (debug) printf("Starting offset: %lu\n", offset);
	
	// Walk through all possible positions to the end of page 
	// (start of directory - extra bytes of the last rec)
	while (offset < UNIV_PAGE_SIZE - REC_N_NEW_EXTRA_BYTES - 1) {
		// Get record pointer
		origin = page + offset;
		if (debug) printf("\nChecking offset: %lu: ", offset);
		
		// Check all tables
		for (i = 0; i < table_definitions_cnt; i++) {
			// Get table info
			table_def_t table = table_definitions[i];
			if (debug) printf(" (%s) ", table.name);

			// Check if origin points to a valid record
			if (check_for_a_record(page, origin, &table, offsets) && check_constraints(origin, &table, offsets)) {
				if (debug) printf("\n---------------------------------------------------\n"
				       			  "PAGE%lu: Found a table %s record: %p (offset = %lu)\n", page_id, table.name, origin, offset);
				offset += process_ibrec(page, origin, &table, offsets);
				break;
			}
		}

//		break;
		// Check from next byte
		offset++;
	}
}

/*******************************************************************/
void init_table_defs() {
	int i, j;

	if (debug) printf("Initializing table definitions...\n");
	
	for (i = 0; i < table_definitions_cnt; i++) {
		table_def_t *table = &(table_definitions[i]);
		if (debug) printf("Processing table: %s\n", table->name);
		
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
		
		if (debug) {
			printf(" - total fields: %i\n", table->fields_count);
			printf(" - nullable fields: %i\n", table->n_nullable);
			printf(" - minimum header size: %i\n", table->min_rec_header_len);
			printf("\n");
		}
	}
}

/*******************************************************************/
void process_ibfile(int fn) {
	int read_bytes;
	page_t *page = malloc(UNIV_PAGE_SIZE);
	char tmp[20];
	
	if (!page) error("Can't allocate page buffer!");

	// Initialize table definitions (count nullable fields, data sizes, etc)
	init_table_defs();

	if (debug) printf("Read data from fn=%d...\n", fn);

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
	if (debug) printf("Opening file: %s\n", fname);
	if (stat(fname, &fstat) != 0 || (fstat.st_mode & S_IFREG) != S_IFREG) error("Invalid file specified!");
	fn = open(fname, O_RDONLY, 0);
	if (!fn) error("Can't open file!");
	
	return fn;
}

/*******************************************************************/
void usage() {
	error(
	  "Usage: ./constraints_parser [-dDh] -f <innodb_datafile>\n"
	  "  Where\n"
	  "    -h  -- Print this help\n"
	  "    -d  -- Process only those pages which potentially could have deleted records (default = NO)\n"
	  "    -D  -- Recover deleted rows only (default = NO)\n"
	  "    -V  -- Verbode mode (lots of debug information)\n"
	  "    -4  -- innodb_datafile is in REDUNDANT format\n"
	  "    -5  -- innodb_datafile is in COMPACT format\n"
	  "\n"
	);
}

/*******************************************************************/
int main(int argc, char **argv) {
	int fn = 0, ch;

	setbuf(stdout, NULL);

	while ((ch = getopt(argc, argv, "45hdDVf:")) != -1) {
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
	
	return 0;
}
