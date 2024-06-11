//
// Created by TobinC on 6/4/2024.
//

#include "rnd.h"
#include "../assert/bassert.h"
#include "../cpu/cpuinfo.h"
#include <immintrin.h>
#include <cpuid.h>

u64 rnd_u64() {


    unsigned int eax, ebx, ecx, edx;

//#define HasRDRAND (ecx & (1 << 30))
#define HasRDRAND cpu_get_feature(CF_RDRAND)

//hmmm
#define HasRDSEED (ebx & (1 << 18))
//#define HasRDSEED

    cpu_getid(1, &eax, &ebx, &ecx, &edx);

#ifdef __x86_64__
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
    } else {
        bassertn(0 == 1, "Neither RDSEED or RDRAND available, another implementation is necessary.");
    }
#else
        bassertn(0 == 1, "ARM Random not implemented");
#endif

    bassertn(flag != 0, "No random number was generated due to unimplemented random functions");

    return ret;
}

/// Prints a random number between min(inclusive) and max(inclusive)
/// \param min The minimum value that can be generated (inclusive)
/// \param max The maximum value that can be generated (inclusive)
/// \return The value based on RDSEED or RDRAND
u64 rnd_u64R(u64 min, u64 max) {
    max++;
    f128 v = rnd_f128();
    v *= (max - min);
    v += min;
    return (u64) v;
}

/// Prints a random number between min(inclusive) and max(inclusive)
/// \param min The minimum value that can be generated (inclusive)
/// \param max The maximum value that can be generated (inclusive)
/// \return The value based on RDSEED or RDRAND
i64 rnd_i64R(i64 min, i64 max) {
    if (max > 0) {
        max++;
    }
    if (min < 0) {
        --min;
    }

    f128 v = rnd_f128();
    v *= (max - min);
    v += min;
    return (i64) v;
}

f128 rnd_f128R(f128 min, f128 max) {
    f128 v = rnd_f128();
    v *= (max - min);
    v += min;
    return v;
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
