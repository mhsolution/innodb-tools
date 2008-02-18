#include <print_data.h>

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
void print_enum(int value, field_def_t *field) {
	printf("\"%s\"", field->limits.enum_values[value-1]);
}

/*******************************************************************/
unsigned long long int get_uint_value(field_def_t *field, byte *value) {
	switch (field->fixed_length) {
		case 1: return mach_read_from_1(value);
		case 2: return mach_read_from_2(value);
		case 3: return mach_read_from_3(value) & 0x3FFFFFUL;
		case 4: return mach_read_from_4(value);
		case 8: return make_ulonglong(mach_read_from_8(value));
	}
	return 0;
}

/*******************************************************************/
long long int get_int_value(field_def_t *field, byte *value) {
	switch (field->fixed_length) {
		case 1: return mach_read_from_1(value) & ~(1<<7);
		case 2: return mach_read_from_2(value) & ~(1<<15);
		case 3: return mach_read_from_3(value) & 0x3FFFFFUL & ~(1L<<23);
		case 4: return mach_read_from_4(value) & ~(1L<<31);
		case 8: return make_longlong(mach_read_from_8(value)) & ~(1LL<<63);
	}
	return 0;
}

/*******************************************************************/
void print_field_value(byte *value, ulint len, field_def_t *field) {
	int i;
	
	switch (field->type) {
		case FT_INTERNAL:
    		break;

		case FT_CHAR:
		case FT_TEXT:
    		printf("\"");
		    for(i = 0; i < len; i++) {
				if (value[i] == '"') printf("\\\"");
				else if (value[i] == '\n') printf("\\n");
				else if (value[i] == '\r') printf("\\r");
				else printf("%c", value[i]);
    		}
    		printf("\"");
			break;

		case FT_UINT:
			switch (field->fixed_length) {
				case 1: printf("%u", mach_read_from_1(value)); break;
				case 2: printf("%u", mach_read_from_2(value)); break;
				case 3: printf("%lu", mach_read_from_3(value) & 0x3FFFFFUL); break;
				case 4: printf("%lu", mach_read_from_4(value)); break;
				case 8: printf("%llu", make_ulonglong(mach_read_from_8(value))); break;
				default: printf("uint_undef(%d)", field->fixed_length);
			}
			break;

		case FT_INT:
			switch (field->fixed_length) {
				case 1: printf("%d", mach_read_from_1(value) & ~(1<<7)); break;
				case 2: printf("%i", mach_read_from_2(value) & ~(1<<15)); break;
				case 3: printf("%li", mach_read_from_3(value) & 0x3FFFFFUL & ~(1L<<23)); break;
				case 4: printf("%li", mach_read_from_4(value) & ~(1L<<31)); break;
				case 8: printf("%lli", make_longlong(mach_read_from_8(value)) & ~(1LL<<63)); break;
				default: printf("int_undef(%d)", field->fixed_length);
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

		case FT_ENUM:
			print_enum(mach_read_from_1(value), field);
			break;

        case FT_DECIMAL:
            printf("DECIMAL");
            break;

		default:
    		printf("undef(%d)", field->type);
	}
}



/*******************************************************************/
void
rec_print_new(
/*==========*/
	FILE*		file,	/* in: file where to print */
	rec_t*		rec,	/* in: physical record */
	const ulint*	offsets)/* in: array returned by rec_get_offsets() */
{
	const byte*	data;
	ulint		len;
	ulint		i;

	ut_ad(rec_offs_validate(rec, NULL, offsets));

	ut_ad(rec);

	fprintf(file, "PHYSICAL RECORD: n_fields %lu;"
		" compact format; info bits %lu\n",
		(ulong) rec_offs_n_fields(offsets),
		(ulong) rec_get_info_bits(rec, TRUE));
	
	for (i = 0; i < rec_offs_n_fields(offsets); i++) {

		data = rec_get_nth_field(rec, offsets, i, &len);

		fprintf(file, " %lu:", (ulong) i);
	
		if (len != UNIV_SQL_NULL) {
			if (len <= 30) {

				ut_print_buf(file, data, len);
			} else {
				ut_print_buf(file, data, 30);

				fputs("...(truncated)", file);
			}
		} else {
			fputs(" SQL NULL", file);
		}
		putc(';', file);
	}

	putc('\n', file);
}