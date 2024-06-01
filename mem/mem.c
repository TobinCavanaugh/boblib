//
// Created by tobin on 5/31/2024.
//

#include "mem.h"

#if SYSTEM_OS == OS_WIN

#include <heapapi.h>

#endif


#define HEAP_SHIFT(start) ((void *) start + sizeof(t_heap))
#define BLOCK_SHIFT(start) ((void *) start + sizeof(t_block))

HANDLE heapHandle = NULL;

void *halloc(u64 size) {
    if (heapHandle == NULL) {
        heapHandle = HeapCreate(0x0, 1024, 0);
    }
    return HeapAlloc(heapHandle, 0x0, size);
}

u0 hfree(void *source) {
    if (source != 0) {
        HeapFree(heapHandle, 0x0, source);
    }
}

u0 memcopy(void *destination, void *source, u64 len) {
    if (len == 0) {
        return;
    }

    int offset = 0;
    while (len % 32 == 0) {

        __m256i load = _mm256_store_si256((__m256i *) source);
        len -= 32;
        offset += 32;
    }

    for(; len > 0; len--){

        offset++;
    }
}