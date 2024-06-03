//
// Created by tobin on 5/31/2024.
//

#include <unistd.h>
#include "../os.h"
#include "mem.h"
#include "../osio/osio.h"

#if SYSTEM_OS == OS_WIN

#include <heapapi.h>

#else

#include <unistd.h>
#include <sys/syscall.h>

#endif




//O(n) for memory block access is pretty shit
//Maybe i should split blocks based on boundaries
//of some sort??

//Maybe a fixed table of pointers to heap blocks?

//heap block includes cursor and number of active allocations


//halloc steps:
//check current block, 4096 - cursor + alignment >= size
//if so, just plop our data in
//if not, store this block, move onto next block and check that, if we cant find an open block to the right
//wrap around to the first block, check up until we reach our stored block.
//if these are all full, jump to the last block and heap alloc a new block

//Steps:
//1. check block
//

typedef struct heap_block {
    u8 *data;
} heap_block;

#if SYSTEM_OS == OS_WIN
HANDLE heapHandle = NULL;
#endif

void *halloc(u64 size) {

#if SYSTEM_OS == OS_WIN
    if (heapHandle == NULL) {
        heapHandle = HeapCreate(0x0, 1024, 0);
    }
    return HeapAlloc(heapHandle, 0x0, size);
#else
    //TODO implement LINUX alloc, might as well us VirtualAlloc for windows to make use of this new allocator
//    syscall(SYS_ALL)
//    sbrk()
#endif

    return malloc(size);
}


void *hrealloc(void *ptr, u64 size) {
#if SYSTEM_OS == OS_WIN
    if (heapHandle == NULL) {
        return halloc(size);
    }
    return HeapReAlloc(heapHandle, 0x0, ptr, size);
#endif
    return realloc(ptr, size);
}

u0 hfree(void *source) {
#if SYSTEM_OS == OS_WIN
    if (source != 0) {
        HeapFree(heapHandle, 0x0, source);
    }
#endif
}
