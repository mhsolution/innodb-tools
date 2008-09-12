#include <print_data.h>
#include <decimal.h>

/*******************************************************************/
inline void print_datetime(ulonglong ldate) {
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
inline void print_date(ulong ldate) {
	int year, month, day;

	ldate &= ~(1UL << 23);
	
	day = ldate % 32; ldate /= 32;
	month = ldate % 16; ldate /= 16;
	year = ldate;
	
	printf("\"%04u-%02u-%02u\"", year, month, day);
}

/*******************************************************************/
inline void print_time(ulong ltime) {
	int hour, min, sec;

	ltime &= ~(1UL << 23);
	
	sec = ltime % 60; ltime /= 60;
	min = ltime % 60; ltime /= 60;
	hour = ltime % 24;
	
	printf("\"%02u:%02u:%02u\"", hour, min, sec);
}


/*******************************************************************/
inline void print_enum(int value, field_def_t *field) {
	printf("\"%s\"", field->limits.enum_values[value-1]);
}

/*******************************************************************/
inline unsigned long long int get_uint_value(field_def_t *field, byte *value) {
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
inline long long int get_int_value(field_def_t *field, byte *value) {
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
inline void print_string(char *value, ulint len, field_def_t *field) {
    uint i, num_spaces = 0, out_pos = 0;
    static char out[32768];
    
    out[out_pos++] = '"';
    for(i = 0; i < len; i++) {
        if (value[i] != ' ' && num_spaces > 0) {
            while(num_spaces > 0) {
                out[out_pos++] = ' ';
                num_spaces--;
            }
        }
		if (value[i] == '\\') out[out_pos++] = '\\', out[out_pos++] = '\\';
		else if (value[i] == '"') out[out_pos++] = '\\', out[out_pos++] = '"';
		else if (value[i] == '\n') out[out_pos++] = '\\', out[out_pos++] = 'n';
		else if (value[i] == '\r') out[out_pos++] = '\\', out[out_pos++] = 'r';
		else if (value[i] == '\t') out[out_pos++] = '\\', out[out_pos++] = 't';
    	else {
            if (value[i] == ' ') {
                num_spaces++;
            } else {
                if ((int)value[i] < 32) {
                    out_pos += sprintf(out + out_pos, "\\x%02x", (uchar)value[i]);
                } else {
                    out[out_pos++] = value[i];
                }
            }
        }
	}

    if (num_spaces > 0 && !field->char_rstrip_spaces) {
        while(num_spaces > 0) {
            out[out_pos++] = ' ';
            num_spaces--;
        }
    }
    out[out_pos++] = '"';
    out[out_pos++] = 0;
    fputs(out, stdout);
}

/*******************************************************************/
inline void print_decimal(byte *value, field_def_t *field) {
    char string_buf[256];
    decimal_digit_t dec_buf[256];
    int len = 255;
    
    decimal_t dec;
    dec.buf = dec_buf;
    dec.len = 256;
    
    bin2decimal((char*)value, &dec, field->decimal_precision, field->decimal_digits);
    decimal2string(&dec, string_buf, &len, field->decimal_precision, field->decimal_digits, ' ');
    print_string(string_buf, len, field);
}

/*******************************************************************/
inline void print_field_value(byte *value, ulint len, field_def_t *field) {
	switch (field->type) {
		case FT_INTERNAL:
    		break;

		case FT_CHAR:
		case FT_TEXT:
            print_string((char*)value, len, field);
			break;

		case FT_UINT:
            printf("%llu", get_uint_value(field, value));
			break;

		case FT_INT:
            printf("%lli", get_int_value(field, value));
			break;

		case FT_FLOAT:
			printf("%f", mach_float_read(value));
			break;

		case FT_DOUBLE:
			printf("%lf", mach_double_read(value));
			break;

		case FT_DATETIME:
			print_datetime(make_longlong(mach_read_from_8(value)));
			break;

		case FT_DATE:
			print_date(mach_read_from_3(value));
			break;

		case FT_TIME:
			print_time(mach_read_from_3(value));
			break;

		case FT_ENUM:
			print_enum(mach_read_from_1(value), field);
			break;

        case FT_DECIMAL:
            print_decimal(value, field);
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
