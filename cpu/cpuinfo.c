//
// Created by tobin on 6/5/2024.
//
#include "cpuinfo.h"
#include "../mem/mem_copy.h"


typedef struct
{
    u8 leaf;
    u8 reg;
    u8 bit;
} cpu_feature;

//..0....1....2....3..
//[eax][ebx][ecx][edx]
const static cpu_feature features[] = {

    //LEAF 1 | EDX | =======================
    // #pragma region LEAF_1_EDX
    {1, 3, 0}, //fpu
    {1, 3, 1}, //vme
    {1, 3, 2}, //de
    {1, 3, 3}, //pse
    {1, 3, 4}, //tsc
    {1, 3, 5}, //msr
    {1, 3, 6}, //pae
    {1, 3, 7}, //mce
    {1, 3, 8}, //cx8
    {1, 3, 9}, //apic
    {1, 3, 10}, //mtrr [reserved]
    {1, 3, 11}, //sep
    {1, 3, 12}, //mtrr
    {1, 3, 13}, //pge
    {1, 3, 14}, //mca
    {1, 3, 15}, //cmov
    {1, 3, 16}, //pat
    {1, 3, 17}, //pse_36
    {1, 3, 18}, //psn
    {1, 3, 19}, //clfsh
    {1, 3, 20}, //nx
    {1, 3, 21}, //ds
    {1, 3, 22}, //acpi
    {1, 3, 23}, //mmx
    {1, 3, 24}, //fxsr
    {1, 3, 25}, //sse
    {1, 3, 26}, //sse2
    {1, 3, 27}, //ss
    {1, 3, 28}, //htt
    {1, 3, 29}, //tm
    {1, 3, 30}, //ia64
    {1, 3, 31}, //pbe
    // #pragma endregion LEAF_1_EDX

    //LEAF 1 | ECX | =======================
    // #pragma region LEAF_1_ECX
    {1, 2, 0}, //sse3
    {1, 2, 1}, //pclmulqdq
    {1, 2, 2}, //dtes64
    {1, 2, 3}, //monitor
    {1, 2, 4}, //ds_cpl
    {1, 2, 5}, //vmx
    {1, 2, 6}, //smx
    {1, 2, 7}, //est
    {1, 2, 8}, //tm2
    {1, 2, 9}, //ssse3
    {1, 2, 10}, //cnxt_id
    {1, 2, 11}, //sdng
    {1, 2, 12}, //fma
    {1, 2, 13}, //cx16
    {1, 2, 14}, //xtpr
    {1, 2, 15}, //pdcm
    {1, 2, 16}, //[reserved]
    {1, 2, 17}, //pcid
    {1, 2, 18}, //dca
    {1, 2, 19}, //sse4_1
    {1, 2, 20}, //sse4_2
    {1, 2, 21}, //x2apic
    {1, 2, 22}, //movbe
    {1, 2, 23}, //popcnt
    {1, 2, 24}, //tsc_deadline
    {1, 2, 25}, //aes_ni
    {1, 2, 26}, //xsave
    {1, 2, 27}, //osxsave
    {1, 2, 28}, //avx
    {1, 2, 29}, //f16c
    {1, 2, 30}, //rdrnd
    {1, 2, 31}, //hypervisor
    // #pragma endregion LEAF_1_ECX


};

u64 cpu_get_feature(CPU_FEATURE inFeature)
{
    cpu_feature feature = features[inFeature];

    //eax, ebx, ecx, edx
    u32 regs[] = {0, 0, 0, 0};

    cpu_getid(1, &regs[0], &regs[1], &regs[2], &regs[3]);

    u32 ret = (regs[feature.reg] & (1 << feature.bit)) != 0;
    return ret;
}

static char cpu_manufacturer_id[13];

char* cpu_get_manufacturer_id()
{
    //String is stored as EBX -> EDX -> ECX
    u32 regs[] = {0, 0, 0, 0};
    cpu_getid(0, &regs[0], &regs[1], &regs[2], &regs[3]);

    mem_copy(cpu_manufacturer_id + 0, &regs[1], 4);
    mem_copy(cpu_manufacturer_id + 8, &regs[2], 4);
    mem_copy(cpu_manufacturer_id + 4, &regs[3], 4);

    cpu_manufacturer_id[12] = 0;

    return (char*)&cpu_manufacturer_id;
}

u0 cpu_getid(i32 info, u32* eax, u32* ebx, u32* ecx, u32* edx)
{
    __asm__ __volatile__ (
        "cpuid"
        : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
        : "a" (info)
        :
    );
}
