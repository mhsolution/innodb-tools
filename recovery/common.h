#ifndef common_h
#define common_h

// Field limits type
typedef struct field_limits {
	// In opposite to field.can_be_null, this field sets 
	// limit from the data point of view
	ibool can_be_null; 
	
	// min and max values for FT_INT fields
	long long int int_min_val;
	long long int int_max_val;

	// min and max values for FT_UNT fields
	unsigned long long int uint_min_val;
	unsigned long long int uint_max_val;

	// min and max string length
	long long int char_min_len;
	long long int char_max_len;
	
	// Should data be forced down to some ASCII sub-set or not
	ibool char_ascii_only;
	ibool char_digits_only;
	
	// Dates validation
	ibool date_validation;
} field_limits_t;

// Table definition types
typedef enum field_type {
	FT_NONE,		// dummy type for stop records
	FT_INTERNAL,	// supported
	FT_CHAR,		// supported (w/o externals)
	FT_INT,			// supported
	FT_UINT,		// supported
	FT_FLOAT,		// supported
	FT_DOUBLE,		// supported
	FT_DATE,		// supported
	FT_DATETIME,	// supported
	FT_ENUM,		// supported (w/o values substitution)
	FT_SET,
	FT_BLOB,
	FT_TEXT,		// supported (w/o externals)
	FT_BIT,
	FT_DECIMAL		// supported
} field_type_t;

typedef struct field_def {
	char *name;
	field_type_t type;
	int min_length;
	int max_length;
	
	ibool can_be_null;
	int fixed_length;
	
	ibool has_limits;
	field_limits_t limits;
} field_def_t;

#define MAX_TABLE_FIELDS 50

typedef struct table_def {
	char *name;
	field_def_t fields[MAX_TABLE_FIELDS];
	int fields_count;
	int data_min_size;
	int data_max_size;
	int n_nullable;
	int min_rec_header_len;
} table_def_t;

#endif
