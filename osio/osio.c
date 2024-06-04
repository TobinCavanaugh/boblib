//
// Created by tobin on 5/31/2024.
//

#include <unistd.h>
#include "osio.h"

u64 output = stdout;

u0 io_prints(hstr* str)
{
    if (str->char_arr != NULL)
    {
        write(output, str->char_arr, hstr_len(str));
    }

    //    const char nullterm = '\0';
    //    write(stdout, &nullterm, 1);
}

u0 io_printCs(char* str)
{
    write(output, str, internal_C_strlen(str));
}

u0 io_printc(char c)
{
    write(output, &c, 1);
}

u0 io_printf128(f128 value)
{
    // if (value == 0)
    // {
    // io_printCs();
    // }
}

u0 io_printu64(u64 value)
{
    if (value == 0)
    {
        io_printc('0');
        return;
    }

    static char tmpBuf[22] = {0};

    const int base = 10;
    int i = 22;

    for (; value && i; --i, value /= base)
    {
        //"0123456789abcedf"
        tmpBuf[i] = "0123456789abcedf"[value % base];
    }

    char* string = &tmpBuf[i + 1];

    write(output, string, internal_C_strlen(string));
}

u0 io_printi64(i64 value)
{
    if (value < 0)
    {
        char sign = '-';
        write(output, &sign, 1);
        value *= -1;
    }

    io_printu64(value);
}

u0 io_printsln(hstr* str)
{
    io_prints(str);
    io_printc('\n');
}

u0 io_println()
{
    io_printc('\n');
}
