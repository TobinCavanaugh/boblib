//
// Created by tobin on 5/31/2024.
//

#include <unistd.h>
#include "osio.h"
#include "../mem/mem_copy.h"
#include "../mem/mem.h"

u64 output = stdout;

u0 io_prints(hstr *str) {
    if (str->char_arr != NULL) {
        write(output, str->char_arr, hstr_len(str));
    }

    //    const char nullterm = '\0';
    //    write(stdout, &nullterm, 1);
}


u0 io_printCs(char *str) {
    write(output, str, internal_C_strlen(str));
}

u0 io_printc(char c) {
    write(output, &c, 1);
}

u0 io_printf128(f128 value) {
    io_printu64((u64) value);
    io_printc('.');
    value -= (u64) value;
    value *= 1000000000000000000;
    io_printu64((u64) value);
}

u0 io_printu64(u64 value) {

//    write(output, string, internal_C_strlen(string));
}

char *io_u64toS(u64 val) {

    char *buf = mem_halloc(22);

    if (val == 0) {
        mem_copy(buf, "0", 2);
        return buf;
    }

    const int base = 10;
    int i = 22;

    for (; val && i; --i, val /= base) {
        buf[i] = "0123456789abcedf"[val % base];
    }
}

char *io_i64toS(i64 value) {

    char *buf = mem_halloc(22);
    if (value < 0) {
        char sign = '-';
        write(output, &sign, 1);
        value *= -1;
    }
    io_printu64(value);

    return buf;
}

u0 io_printi64(i64 value) {

}

u0 io_printsln(hstr *str) {
    io_prints(str);
    io_printc('\n');
}

u0 io_println() {
    io_printc('\n');
}
