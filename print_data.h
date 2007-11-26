#ifndef _print_data_h_
#define _print_data_h_

#include <univ.i>
#include <page0page.h>
#include <rem0rec.h>

#include "common.h"

extern bool debug;

inline ulonglong make_ulonglong(dulint x);
inline longlong make_longlong(dulint x);

unsigned long long int get_uint_value(field_def_t *field, byte *value);
long long int get_int_value(field_def_t *field, byte *value);

void print_datetime(ulonglong ldate);
void print_date(ulonglong ldate);
void print_enum(int value, field_def_t *field);
void print_field_value(byte *value, ulint len, field_def_t *field);

void rec_print_new(FILE* file, rec_t* rec, const ulint* offsets);

#endif
