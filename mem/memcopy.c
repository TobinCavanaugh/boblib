//
// Created by tobin on 6/3/2024.
//

#include "memcopy.h"

#include <immintrin.h>

#define MEMCOPY_INSTRUCTION_DEBUG 0

#if MEMCOPY_INSTRUCTION_DEBUG

#include "../osio/osio.h"

#endif

u0 memcopy(void *destination, void *source, u64 len) {
    if (len == 0) {
        return;
    }

//    __builtin_memcpy(destination, source, len);
//    return;

    int offset = 0;

#if __AVX512F__
    {
        const u8 avxSize = 64;
        while (len >= avxSize) {
#if MEMCOPY_INSTRUCTION_DEBUG
            io_printCs("avx512,");
#endif
            _mm512_storeu_epi64(destination + offset, _mm512_loadu_epi64(source + offset));
            len -= avxSize;
            offset += avxSize;
        }
    }
#endif


#if __AVX__
    {
        const u8 avxSize = 32;
        while (len >= avxSize) {
#if MEMCOPY_INSTRUCTION_DEBUG
            io_printCs("avx256,");
#endif
            _mm256_storeu_si256(destination + offset, _mm256_loadu_si256(source + offset));
            len -= avxSize;
            offset += avxSize;
        }
    }
#endif


#if 0// __SSE2__ || __SSE3__
    {

        //TODO Duffs device??
        //Note: Spent ~20 mins trying duffs device but no luck,
        //need to sit down and give it a genuine shot. Sadly uprof
        //on amd just crashes, so i cant really profile this to see
        //what most of the time is being eaten up by.

        const u8 sseSize = 16;

        __m128i _a, _b, _c, _d, _e, _f, _g, _h, _i, _j, _k, _l, _m, _n, _o, _p;

        //Does 256B at a time, loop unrolling me feel like a noob
        while (len >= sseSize * 16) {
#if MEMCOPY_INSTRUCTION_DEBUG
            io_printCs("sse256B,");
#endif
            const __m128i *sourceDef = (const __m128i *) (source + offset);
            __m128i *destDef = ((__m128i *) (destination + offset));

            _a = _mm_loadu_si128(sourceDef + 0);
            _b = _mm_loadu_si128(sourceDef + 1);
            _c = _mm_loadu_si128(sourceDef + 2);
            _d = _mm_loadu_si128(sourceDef + 3);
            _e = _mm_loadu_si128(sourceDef + 4);
            _f = _mm_loadu_si128(sourceDef + 5);
            _g = _mm_loadu_si128(sourceDef + 6);
            _h = _mm_loadu_si128(sourceDef + 7);
            _i = _mm_loadu_si128(sourceDef + 8);
            _j = _mm_loadu_si128(sourceDef + 9);
            _k = _mm_loadu_si128(sourceDef + 10);
            _l = _mm_loadu_si128(sourceDef + 11);
            _m = _mm_loadu_si128(sourceDef + 12);
            _n = _mm_loadu_si128(sourceDef + 13);
            _o = _mm_loadu_si128(sourceDef + 14);
            _p = _mm_loadu_si128(sourceDef + 15);

            _mm_prefetch(source + 256, _MM_HINT_NTA);

            _mm_storeu_si128(destDef + 0, _a);
            _mm_storeu_si128(destDef + 1, _b);
            _mm_storeu_si128(destDef + 2, _c);
            _mm_storeu_si128(destDef + 3, _d);
            _mm_storeu_si128(destDef + 4, _e);
            _mm_storeu_si128(destDef + 5, _f);
            _mm_storeu_si128(destDef + 6, _g);
            _mm_storeu_si128(destDef + 7, _h);
            _mm_storeu_si128(destDef + 8, _i);
            _mm_storeu_si128(destDef + 9, _j);
            _mm_storeu_si128(destDef + 10, _k);
            _mm_storeu_si128(destDef + 11, _l);
            _mm_storeu_si128(destDef + 12, _m);
            _mm_storeu_si128(destDef + 13, _n);
            _mm_storeu_si128(destDef + 14, _o);
            _mm_storeu_si128(destDef + 15, _p);

            offset += 256;
            len -= 256;
        }

        //Does 16B at _a time
        while (len >= sseSize) {
#if MEMCOPY_INSTRUCTION_DEBUG
            io_printCs("sse16B,");
#endif
            _mm_storeu_si128(destination + offset, _mm_loadu_si128(source + offset));
            len -= sseSize;
            offset += sseSize;

        }
    }
#endif

    typedef struct {
        u64 _a, _b, _c, _d;
    } block32B;

    typedef struct {
        block32B _a, _b, _c, _d, _e, _f, _g, _h;
    } block256B;

    typedef struct {
        block256B _a, _b, _c, _d;
    } block1024B;


    for (; len >= sizeof(block1024B); len -= sizeof(block1024B)) {
#if MEMCOPY_INSTRUCTION_DEBUG
        io_printCs("b1024B,");
#endif
        *((block1024B *) (destination + offset)) = *((block1024B *) (source + offset));
        offset += sizeof(block1024B);
    }

    for (; len >= sizeof(block256B); len -= sizeof(block256B)) {
#if MEMCOPY_INSTRUCTION_DEBUG
        io_printCs("b256B,");
#endif
        *((block256B *) (destination + offset)) = *((block256B *) (source + offset));
        offset += sizeof(block256B);
    }

    for (; len >= sizeof(block32B); len -= sizeof(block32B)) {
#if MEMCOPY_INSTRUCTION_DEBUG
        io_printCs("b32B,");
#endif
        *((block32B *) (destination + offset)) = *((block32B *) (source + offset));
        offset += sizeof(block32B);
    }

    // 8 byte chunks
    for (; len >= sizeof(u64); len -= sizeof(u64)) {

#if MEMCOPY_INSTRUCTION_DEBUG
        io_printCs("u64b,");
#endif
        *((u64 *) (destination + offset)) = *((u64 *) (source + offset));
        offset += sizeof(u64);
    }

    //4 byte chunks
    for (; len >= sizeof(u32); len -= sizeof(u32)) {

#if MEMCOPY_INSTRUCTION_DEBUG
        io_printCs("u32b,");
#endif
        *((u32 *) (destination + offset)) = *((u32 *) (source + offset));
        offset += sizeof(u32);
    }

    //Individual bytes
    for (; len > 0; len--) {

#if MEMCOPY_INSTRUCTION_DEBUG
        io_printCs("it,");
#endif
        ((u8 *) destination)[offset] = ((u8 *) source)[offset];
        offset++;
    }
}
