//
// Created by tobin on 6/5/2024.
//

#ifndef BOBLIB_CPUINFO_H
#define BOBLIB_CPUINFO_H

#include "../bint.h"

//Names chosen based on https://en.wikipedia.org/wiki/CPUID
typedef enum {
    CF_FPU = 0,
    CF_VME = 1,
    CF_DE = 2,
    CF_PSE = 3,
    CF_TSC = 4,
    CF_MSR = 5,
    CF_PAE = 6,
    CF_MCE = 7,
    CF_CX8 = 8,
    CF_APIC = 9,
    MTRR_RESERVED = 10,
    CF_SEP = 11,
    CF_MTRR = 12,
    CF_PGE = 13,
    CF_MCA = 14,
    CF_CMOV = 15,
    CF_PAT = 16,
    CF_PSE_36 = 17,
    CF_PSN = 18,
    CF_CLFSH = 19,
    CF_NX = 20,
    CF_DS = 21,
    CF_ACPI = 22,
    CF_MMX = 23,
    CF_FXSR = 24,
    CF_SSE = 25,
    CF_SSE2 = 26,
    CF_SS = 27,
    CF_HTT = 28,
    CF_TM1 = 29,
    CF_IA64 = 30,
    CF_PBE = 31,
    CF_SSE3 = 32,
    CF_PCLMULQDQ = 33,
    CF_DTES64 = 34,
    CF_MONITOR = 35,
    CF_DS_CPL = 36,
    CF_VMX = 37,
    CF_SMX = 38,
    CF_EST = 39,
    CF_TM2 = 40,
    CF_SSSE3 = 41,
    CF_CNXT_ID = 42,
    CF_SDNG = 43,
    CF_FMA = 44,
    CF_CX16 = 45,
    CF_XTPR = 46,
    CF_PDCM = 47,
    CF_RESERVED = 48,
    CF_PCID = 49,
    CF_DCA = 50,
    CF_SSE4_1 = 51,
    CF_SSE4_2 = 52,
    CF_X2APIC = 53,
    CF_MOVBE = 54,
    CF_POPCNT = 55,
    CF_TSC_DEADLINE = 56,
    CF_AES_NI = 57,
    CF_XSAVE = 58,
    CF_OSXSAVE = 59,
    CF_AVX = 60,
    CF_F16C = 61,
    CF_RDRAND = 62,
    CF_HYPERVISOR = 63,
} CPU_FEATURE;


u64 cpu_get_feature(CPU_FEATURE feature);

u0 cpu_getid(i32 info, u32 *eax, u32 *ebx, u32 *ecx, u32 *edx);


char *cpu_get_manufacturer_id();

#endif //BOBLIB_CPUINFO_H
