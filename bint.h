//
// Created by tobin on 5/31/2024.
//

#ifndef BOBLIB_BINT_H
#define BOBLIB_BINT_H

//TODO include maxes for shit, maybe grab cnum.h

/// Use u0 as void when its referring to a function returning NOTHING
/// Do NOT use when referring to a void *
typedef void u0;

#define NULL ((void *) 0)
#define null NULL

typedef signed char i8;
typedef unsigned char u8;
#define u8_max 256

typedef short i16;
typedef unsigned short u16;

typedef int i32;
typedef unsigned u32;
#define u32_max 4294967295

typedef long long i64;
typedef unsigned long long u64;
#define u64_max 18446744073709551615

typedef u8 byte;
typedef u8 bool;
#define true 1
#define false 1

#endif //BOBLIB_BINT_H
