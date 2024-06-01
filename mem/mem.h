//
// Created by tobin on 5/31/2024.
//

#ifndef BOBLIB_MEM_H
#define BOBLIB_MEM_H

#include "../bint.h"

void *halloc(u64 size);


#define salloc(size) ({ \
    u8 _salloc_data[size] = {0}; \
    _salloc_data;                   \
    })                      \

#endif //BOBLIB_MEM_H