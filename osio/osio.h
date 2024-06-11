//
// Created by tobin on 5/31/2024.
//

#ifndef BOBLIB_OSIO_H
#define BOBLIB_OSIO_H

#include "../hstr/hstr.h"

#define stdout (1)
#define stderr (2)


u0 io_prints(hstr *str);

u0 io_printu64(u64 value);

u0 io_printsln(hstr *str);

u0 io_println();

u0 io_printCs(char *str);

u0 io_printc(char c);

u0 io_printf128(f128 val);

hstr *io_u64toS(u64 val);

hstr *io_i64toS(i64 value);

u0 io_printi64(i64 value);

#endif //BOBLIB_OSIO_H
