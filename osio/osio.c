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

char *io_f128toS(f128 val) {

}


hstr *io_u64toS(u64 val) {

    //Set the buf length to 22 characters
    hstr *buf = HSTR("");

    if (val == 0) {
        hstr_appendCs(buf, "0");
//        mem_copy(buf->char_arr, "0", 2);
        return buf;
    }

    const int base = 10;
    int i = 22;

    //add 23 chars, one extra for - sign
    hstr_appendCs(buf, ".......................");

    for (; val && i; --i, val /= base) {
        buf->char_arr[i] = "0123456789abcedf"[val % base];
    }

    //TODO IMPLEMENT CUSTOM MEMMOVE
    memmove(buf->char_arr, buf->char_arr + i + 1, 22 - i);
    hstr_set_end(buf, 22 - i);

    return buf;
}

u0 io_printu64(u64 value) {
    hstr *str = io_u64toS(value);
    io_prints(str);
    hstr_free(str);
}

hstr *io_i64toS(i64 value) {

    u64 tmp = (u64) value;
    if (value < 0) {
        tmp = (u64) (value * -1);
    }

    hstr *buf = io_u64toS(tmp);

    if (value < 0) {
        memmove(buf->char_arr + 1, buf->char_arr, hstr_len(buf));
        buf->end_ptr++;
        buf->char_arr[0] = '-';
    }

    return buf;
}

u0 io_printi64(i64 value) {
    hstr *str = io_i64toS(value);
    io_prints(str);
    hstr_free(str);
}

u0 io_printsln(hstr *str) {
    io_prints(str);
    io_printc('\n');
}

u0 io_println() {
    io_printc('\n');
}
