//
// Created by tobin on 5/31/2024.
//

#ifndef BOBLIB_hstr_H
#define BOBLIB_hstr_H

#include "../bint.h"

typedef struct
{
    char* char_arr;
    char* end_ptr;
} hstr;


#define str_append(base, value) \
    _Generic((value), \
        char*: hstr_appendC, \
        hstr*: hstr_append,\
        hstr: hstr_appendL, \
    (base, default)

#define HSTR(str) hstr_create(str)

u64 internal_C_strlen(char* data);

u0 hstr_set_end(hstr* str, u64 len);

hstr* hstr_create(char* source);

u64 hstr_len(hstr* str);

#endif //BOBLIB_hstr_H
