//
// Created by tobin on 5/31/2024.
//

#include <unistd.h>
#include "osio.h"

u0 io_prints(bstr str) {
    if (str.char_arr != NULL) {
        write(stdout, str.char_arr, bstr_len(str));
    }
//    const char nullterm = '\0';
//    write(stdout, &nullterm, 1);
}

u0 io_printc(char c) {
    write(stdout, &c, 1);
}


u0 io_printu64(u64 value) {
    static char tmpBuf[22] = {0};

    const int base = 10;
    int i = 22;


    for (; value && i; --i, value /= base) {
        tmpBuf[i] = "0123456789abcedf"[value % base];
    }

    char *string = &tmpBuf[i + 1];

    write(stdout, string, internal_C_strlen(string));
}

u0 io_printi64(i64 value) {
    if (value < 0) {
        char sign = '-';
        write(stdout, &sign, 1);
        value *= -1;
    }

    io_printu64(value);
}

u0 io_printsln(bstr str) {
    io_prints(str);
    io_printc('\n');
}

u0 io_println() {
    io_printc('\n');
}