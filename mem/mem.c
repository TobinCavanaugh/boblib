//
// Created by tobin on 5/31/2024.
//

#include <unistd.h>
#include "../os.h"
#include "mem.h"

#include "mem_copy.h"
#include "../osio/osio.h"

#if SYSTEM_OS == OS_WIN
#include <memoryapi.h>
#else
#include <unistd.h>
#include <sys/syscall.h>
#endif

/// This datastructure handles our freed heap blocks
typedef struct heap_block
{
    u64 size;
    struct heap_block* next;
} heap_block;

/// The start of our heap blocks
static heap_block head = {0};

/// The alignment of our memory, this aligns to 16B boundaries
static const u64 alignment = 16;

/// The amount of data allocated on the heap
static u64 total_heap_allocation = 0;

/// The boblib counterpart to malloc. Performs a heap allocation.
/// Use mem_hfree to free memory allocated by this
/// Adapted from Sylvain Defresne:
/// https://stackoverflow.com/a/5422447/21769995
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
            total_heap_allocation += size;
            return (u8*)newBlock + sizeof(heap_block);
        }

        //Set our headptr to point at the next block
        headptr = &newBlock->next;

        //Look at the next block
        newBlock = newBlock->next;
    }

    //TODO This is not ideal afaik
#if SYSTEM_OS == OS_WIN
    newBlock = VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#elif
    newBlock = (heap_block*) sbrk(size);
#endif

    if (newBlock == NULL)
    {
        return NULL;
    }
    newBlock->size = size;

    total_heap_allocation += newBlock->size;

    return ((u8*)newBlock) + sizeof(heap_block);
}

/// Frees memory allocated on the heap by mem_halloc()
/// @param ptr The pointer to the data of the block to be freed.
u0 mem_hfree(void* ptr)
{
    //TODO If the pointer isn't to the start of the memory block this will fail,
    //that sucks.

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

/// Reallocates the heap block at ptr to a new block of size.
/// @param ptr The pointer to the heap block data
/// @param size The size of the reallocation
/// @return Returning NULL is the failure state, where no state changes
void* mem_hrealloc(void* ptr, u64 size)
{
    void* new = mem_halloc(size);
    if (new == NULL)
    {
        return NULL;
    }

    heap_block* current = (heap_block*)((u8*)ptr - sizeof(heap_block));
    mem_copy(new, ptr, current->size);

    mem_hfree(ptr);

    return new;
}

/// Get the current amount of heap allocated bytes
/// @return The amount of bytes
u64 mem_get_total_heap_alloc()
{
    return total_heap_allocation;
}
