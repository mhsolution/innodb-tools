#include "univ.i"
#include "page0page.h"
#include "rem0rec.h"

#include "common.h"

extern bool deleted_pages_only;

int page_is_interesting(page_t *page) {
	ulint free_offset;
	rec_t *rec;
/*
	// Empty page
	if (mach_read_from_4(page + FIL_PAGE_OFFSET) == 0) return 0;

	// Check offsets (there should be free space, etc)
	if (deleted_pages_only) {
		free_offset = page_header_get_field(page, PAGE_FREE);
		if (page_header_get_field(page, PAGE_N_RECS) == 0 && free_offset == 0) return 0;
		if (free_offset > 0 && page_header_get_field(page, PAGE_GARBAGE) == 0) return 0;
		if (free_offset > UNIV_PAGE_SIZE) return 0;
	}

	// Check type (we need only index pages)
	if (mach_read_from_2(page + FIL_PAGE_TYPE) != FIL_PAGE_INDEX) return 0;
	
	// Check if this is a real table (not an index)
	if (deleted_pages_only) {
		rec = page + free_offset;
		if (rec_get_n_fields(rec) < 3) return 0; // index
		if (rec_get_n_fields(rec) > 3 && rec_get_nth_field_len(rec, 1) != 6 && rec_get_nth_field_len(rec, 2) != 7) return 0;
	}
*/	
	return 1;
}

int mysql_get_identifier_quote_char(trx_t* trx, const char* name, ulint namelen) {
	return '"';
}
