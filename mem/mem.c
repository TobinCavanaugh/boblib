//
// Created by tobin on 5/31/2024.
//

#include <unistd.h>
#include "../os.h"
#include "mem.h"

#include "memcopy.h"
#include "../osio/osio.h"

#if SYSTEM_OS == OS_WIN

#include <memoryapi.h>

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


#define ALLOCATION_SIZE 1024

typedef struct heap_block
{
    char sign[8];
    u64 size;
    struct heap_block* next;
} heap_block;

static heap_block head = {0};
static const u64 alignment = 16;
static u64 total_heap_allocation = 0;

u64 mem_get_total_heap_alloc()
{
    return total_heap_allocation;
}

// #if SYSTEM_OS == OS_WIN
// HANDLE heapHandle = NULL;
// #endif

//Adapted from Sylvain Defresne
//https://stackoverflow.com/a/5422447/21769995
void* mem_halloc(u64 size)
{
    //Round size to the nearest power of two, only works if alignment is a pow of two
    size = (size + u64_size + (alignment - 1)) & ~(alignment - 1);

    heap_block* newBlock = head.next;
    heap_block** headptr = &head.next;

    //Go through all blocks
    while (newBlock != NULL)
    {
        //If it has the size we need
        if (newBlock->size >= size)
        {
            //We set the next of our head to the block we found
            *headptr = newBlock->next;
            memcopy(newBlock->sign, "~~~~~~~", 8);
            total_heap_allocation += size;
            return (u8*)newBlock + sizeof(heap_block);
        }

        //Set our headptr to point at the next block
        headptr = &newBlock->next;

        //Look at the next block
        newBlock = newBlock->next;
    }

#if SYSTEM_OS == OS_WIN
    //TODO This is not ideal afaik
    newBlock = VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE);
    newBlock->size = size;
#elif
    newBlock = (heap_block*) sbrk(size);
    newBlock->size = size;
#endif

    memcopy(newBlock->sign, "+++++++", 8);
    total_heap_allocation += newBlock->size;

    return ((u8*)newBlock) + sizeof(heap_block);
}

u0 mem_hfree(void* ptr)
{
    heap_block* block = (heap_block*)((u8*)ptr - sizeof(heap_block));
    block->next = head.next;
    head.next = block;

    //Prevent wrap around
    if (total_heap_allocation - block->size >= total_heap_allocation)
    {
        total_heap_allocation = 0;
    }
    else
    {
        total_heap_allocation -= block->size;
    }
}

void* mem_hrealloc(void* ptr, u64 size)
{
    // #if SYSTEM_OS == OS_WIN
    // if (heapHandle == NULL)
    // {
    // return halloc(size);
    // }
    // return HeapReAlloc(heapHandle, 0x0, ptr, size);
    // #endif
    // return realloc(ptr, size);
    // }

    // u0 hfree(void* source)
    // {
    // #if SYSTEM_OS == OS_WIN
    // if (source != 0)
    // {
    // HeapFree(heapHandle, 0x0, source);
    // }
    // #endif
    return NULL;
}
