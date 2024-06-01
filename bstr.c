//
// Created by tobin on 5/31/2024.
//

#include <assert.h>
#include "bstr.h"
#include "mem/mem.h"

u64 internal_C_strlen(char *data) {
    int i = 0;
    while (data[i] != '\0') {
        i++;
    }
    return i;
}

bstr bstr_set_end(bstr str, u64 len) {
    str.end_ptr = str.char_arr + len;
    return str;
}

u64 bstr_len(bstr str) {
//    assert(str.char_arr <= str.end_ptr);
    return ((u64) str.end_ptr - (u64) &str.char_arr[0]);
}

bstr bstr_create(char *source) {
    bstr str = {0};
    u64 len = internal_C_strlen(source);
    str.char_arr = halloc(len);

    int i= 0;
    for(; i < len; i++){
        str.char_arr[i] = source[i];
    }

    str = bstr_set_end(str, len);
//    assert(bstr_len(str) == len);

    return str;
}