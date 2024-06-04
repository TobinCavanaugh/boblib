//
// Created by tobin on 5/31/2024.
//
#include "../bint.h"

#ifndef BOBLIB_MEM_H
#define BOBLIB_MEM_H


u64 mem_get_total_heap_alloc();

void* mem_halloc(u64 size);

u0 mem_hfree(void* source);

void* mem_hrealloc(void* ptr, u64 size);

#define mem_salloc(size) ({ \
    u8 _salloc_data[size] = {0}; \
    _salloc_data;                   \
    })
#endif //BOBLIB_MEM_H
