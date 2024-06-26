//
// Created by TobinC on 6/4/2024.
//

#ifndef BASSERT_H
#define BASSERT_H

#include "../bint.h"
#include "../osio/osio.h"
#include <unistd.h>


#ifdef _DEBUG
#define PASTE_SEQ(seq) #seq
#define CAT_SEQ(x, y) x ## y

/// Assert that when not true, prints out the note, the condition and the URL to the file and line
/// @param cond
#define bassertn(cond, note) ({                                                                      \
u8 condVal = (cond);                                                                                 \
if(!condVal) {                                                                                       \
    io_printCs("\nAssert Failed ------------------------------------------------------------------");\
    io_printCs("\n\t- Note : ["); io_printCs(note); io_printCs("]");                                 \
    io_printCs("\n\t- Condition : `" PASTE_SEQ(cond) "` is not true. ");                             \
    io_printCs("\n\t- "); io_printCs(__FILE__); io_printCs(":"); io_printu64(__LINE__);              \
    _exit(10);                                                                                       \
    }                                                                                                \
})

#define bassert(cond) bassertn(cond, "")

#else
#define bassert(cond) {}
#endif


#endif //BASSERT_H
