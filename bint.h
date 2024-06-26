//
// Created by tobin on 5/31/2024.
//

#ifndef BOBLIB_BINT_H
#define BOBLIB_BINT_H

//TODO include maxes for shit, maybe grab cnum.h

/// Use u0 as void when its referring to a function returning NOTHING
/// Do NOT use when referring to a void *
typedef void u0;

#undef NULL
#define NULL ((void *) 0)
#define null NULL

typedef signed char i8;
typedef unsigned char u8;
#define u8_max (u8)-1
#define u8_size sizeof(u8) //1

typedef short i16;
typedef unsigned short u16;
#define u16_max (u16)-1
#define u16_size sizeof(u16) //2

typedef int i32;
typedef unsigned u32;
#define u32_max (u32)-1
#define u32_size sizeof(u32) //4

typedef long long i64;
typedef unsigned long long u64;
#define u64_max (u64)-1
#define u64_size sizeof(u64) //8

typedef float f32;
#define f32_size sizeof(f32) //4

typedef double f64;
#define f64_size sizeof(f64) //8

typedef long double f128;
#define f128_size sizeof(f128); //16

typedef u8 byte;
typedef u8 bool;
#define true 1
#define false 0


#endif //BOBLIB_BINT_H
