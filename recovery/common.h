// Table definition types
enum field_type {
	FT_NONE,		// dummy type for stop records
	FT_INTERNAL,	// supported
	FT_CHAR,		// supported
	FT_INT,			// supported
	FT_UINT,		// supported
	FT_FLOAT,
	FT_DATE,
	FT_DATETIME,
	FT_ENUM,
	FT_SET,
	FT_BLOB
}; 
typedef enum field_type field_type_t;

typedef struct field_def {
	char *name;
	field_type_t type;
	int min_length;
	int max_length;
	ibool has_data_limits;
	ulint data_min;
	ulint data_max;
} field_def_t;

#define MAX_TABLE_FIELDS 50

typedef struct table_def {
	char *name;
	field_def_t fields[MAX_TABLE_FIELDS];
	int fields_count;
	int data_min_size;
	int data_max_size;
} table_def_t;


/****************************************************************
The following function is used to get a pointer to the nth data field in a
record. */

byte*
rec_get_nth_field(
/*==============*/
 			/* out: pointer to the field */
 	rec_t*	rec, 	/* in: record */
 	ulint	n,	/* in: index of the field */
	ulint*	len)	/* out: length of the field; UNIV_SQL_NULL if SQL
			null */
{
	ulint	os;
	ulint	next_os;

	ut_ad(rec && len);
	ut_ad(n < rec_get_n_fields(rec));

	if (n > 1024) error("Trying to access field in rec with n > 1024");
	if (rec == NULL) error("rec is NULL pointer in get_nth_field!");
	
	if (rec_get_1byte_offs_flag(rec)) {
		os = rec_1_get_field_start_offs(rec, n);

		next_os = rec_1_get_field_end_info(rec, n);

		if (next_os & REC_1BYTE_SQL_NULL_MASK) {
			*len = UNIV_SQL_NULL;

			return(rec + os);
		}

		next_os = next_os & ~REC_1BYTE_SQL_NULL_MASK;
	} else {
		os = rec_2_get_field_start_offs(rec, n);
	
		next_os = rec_2_get_field_end_info(rec, n);

		if (next_os & REC_2BYTE_SQL_NULL_MASK) {
			*len = UNIV_SQL_NULL;

			return(rec + os);
		}

		next_os = next_os & ~(REC_2BYTE_SQL_NULL_MASK
						| REC_2BYTE_EXTERN_MASK);
	}
	
	*len = next_os - os;

	ut_ad(*len < UNIV_PAGE_SIZE);

	return(rec + os);
}


int page_is_interesting(page_t *page) {
	ulint free_offset;
	rec_t *rec;

	// Empty page
	if (mach_read_from_4(page + FIL_PAGE_OFFSET) == 0) return 0;

	// Check offsets (there should be free space, etc)
	free_offset = page_header_get_field(page, PAGE_FREE);
	if (page_header_get_field(page, PAGE_N_RECS) == 0 && free_offset == 0) return 0;
	if (free_offset > 0 && page_header_get_field(page, PAGE_GARBAGE) == 0) return 0;
	if (free_offset > UNIV_PAGE_SIZE) return 0;

	// Check type (we need only index pages)
	if (mach_read_from_2(page + FIL_PAGE_TYPE) != FIL_PAGE_INDEX) return 0;
	
	// Check if this is a real table (not an index)
	rec = page + free_offset;
	if (rec_get_n_fields(rec) < 3) return 0; // index
	if (rec_get_n_fields(rec) > 3 && rec_get_nth_field_len(rec, 1) != 6 && rec_get_nth_field_len(rec, 2) != 7) return 0;
	
	return 1;
}


/* Determine whether the page is in new-style compact format. */
ulint ib_page_is_comp(page_t* page) {
	return (page_header_get_field(page, PAGE_N_HEAP) & 0x8000 ==  0x8000);
}

int mysql_get_identifier_quote_char(trx_t* trx, const char* name, ulint namelen) {
	return '"';
}