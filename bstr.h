//
// Created by tobin on 5/31/2024.
//

#ifndef BOBLIB_BSTR_H
#define BOBLIB_BSTR_H

#include "bint.h"

typedef struct {
    char *char_arr;
    char *end_ptr;
} bstr;

#define C(str) bstr_create(str)

u64 internal_C_strlen(char *data);

bstr bstr_set_end(bstr str, u64 len);

bstr bstr_create(char *source);

u64 bstr_len(bstr str);

#endif //BOBLIB_BSTR_H
