//
// Created by TobinC on 6/4/2024.
//

#include "rnd.h"
#include <immintrin.h>

u64 rnd_u64()
{
    // u64 rand;
    // __asm__ __volatile__ ("RDSEED %0" : "=r"(rand));
    // return rand;


    u64 ret;
    __asm__ __volatile__(
        "1:;\n"
        "rdseed %0;\n"
        "jnc 1b;\n"
        : "=r"(ret)
    );

    return ret;
}

f128 rnd_f128()
{
    f128 x = (f128)rnd_u64();
    f128 y = (f128)u64_max;
    f128 z = (x / y);
    return z;
}

u32 rnd_u32()
{
    return (u32)rnd_u64();
}
