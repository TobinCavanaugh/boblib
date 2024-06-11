//
// Created by TobinC on 6/4/2024.
//

#ifndef RND_H
#define RND_H

#include "../bint.h"


u32 rnd_u32();

u64 rnd_u64();

f128 rnd_f128R(f128 min, f128 max);

u64 rnd_u64R(u64 min, u64 max);

f128 rnd_f128();

i64 rnd_i64R(i64 min, i64 max);


#endif //RND_H
