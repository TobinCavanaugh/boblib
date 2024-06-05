//
// Created by TobinC on 6/4/2024.
//

#include "rnd.h"
#include "../assert/bassert.h"
#include "../cpu/cpuinfo.h"
#include <immintrin.h>
#include <cpuid.h>

u64 rnd_u64() {
    // u64 rand;
    // __asm__ __volatile__ ("RDSEED %0" : "=r"(rand));
    // return rand;


    unsigned int eax, ebx, ecx, edx;

#define HasRDRAND (ecx & (1 << 30))
#define HasRDSEED (ebx & (1 << 18))

    cpu_getid(1, &eax, &ebx, &ecx, &edx);

    u8 flag = 0;
    u64 ret;
    if (HasRDSEED) {
        flag = 1;
        __asm__ __volatile__(
                "1:;\n"
                "rdseed %0;\n"
                "jnc 1b;\n"
                : "=r"(ret)
                );
    } else if (HasRDRAND) {
        flag = 2;
        __asm__ __volatile__(
                "1:;\n"
                "rdrand %0;\n"
                "jnc 1b;\n"
                : "=r"(ret)
                );
    }


    bassert(flag != 0);

    return ret;
}

/// Prints a random number between min(inclusive) and max(inclusive)
/// \param min The minimum value that can be generated (inclusive)
/// \param max The maximum value that can be generated (inclusive)
/// \return The value based on RDSEED
u64 rnd_u64R(u64 min, u64 max) {
    f128 v = rnd_f128();
    v *= (max - min);
    v += min;
    return (u64) v;
}

f128 rnd_f128() {
    f128 x = (f128) rnd_u64();
    f128 y = (f128) u64_max;
    f128 z = (x / y);
    return z;
}

u32 rnd_u32() {
    return (u32) rnd_u64();
}
