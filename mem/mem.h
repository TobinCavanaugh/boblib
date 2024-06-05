//
// Created by tobin on 5/31/2024.
//
#include "../bint.h"

#ifndef BOBLIB_MEM_H
#define BOBLIB_MEM_H


/// The canary is a piece of data we put after our allocated memory block that
/// we can use to detect if a buffer overrun has occurred, the message will be
/// raised when we free that piece of memory with mem_hfree.
/// If you want to disable this, for example, for release, simply define
/// MEM_HEAP_USE_CANARY as 0
#define MEM_HEAP_USE_CANARY 1

u64 mem_get_total_heap_alloc();

void* mem_halloc(u64 size);

u0 mem_hfree(void* source);

void* mem_hrealloc(void* ptr, u64 size);

#define mem_salloc(size) ({ \
    u8 _salloc_data[size] = {0}; \
    _salloc_data;                   \
    })
#endif //BOBLIB_MEM_H
