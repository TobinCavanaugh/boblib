//
// Created by tobin on 6/6/2024.
//

#ifndef BOBLIB_MAT_H
#define BOBLIB_MAT_H


#include "../bint.h"


/// Performs the absolute value of the integer, can be any size
//For whatever reason (these all make logical sense) but none of them work
//#define mat_absi(x) (x * ((x>0)-(x<0)))
//#define mat_absi(x) ((x >> (sizeof(x) - 1) | 1) * x)
//#define mat_absi(x) (x * ((x>0)-(x<0)))


i64 mat_absi(i64 x);

u64 mat_powu64(u64 base, u64 exp);


#endif //BOBLIB_MAT_H
