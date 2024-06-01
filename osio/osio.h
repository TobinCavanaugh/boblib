//
// Created by tobin on 5/31/2024.
//

#ifndef BOBLIB_OSIO_H
#define BOBLIB_OSIO_H

#include "../bstr.h"

#define stdout 1

u0 io_prints(bstr str);

u0 io_printu64(u64 value);

u0 io_printsln(bstr str);

u0 io_println();


#endif //BOBLIB_OSIO_H
