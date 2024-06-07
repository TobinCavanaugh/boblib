//
// Created by tobin on 6/6/2024.
//

#ifndef BOBLIB_MAT_H
#define BOBLIB_MAT_H


#include "../bint.h"


/// Performs the absolute value of the integer, can be any size
#define mat_absi(x) ((x ^ (x >> (sizeof(x) * 8 - 1))) - (x >> (sizeof(x) * 8 - 1)))

u64 mat_powu64(u64 base, u64 exp);

i64 mat_absi64(i64 x);

#endif //BOBLIB_MAT_H
