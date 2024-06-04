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

/// Assert that when not true, prints out the condition and the URL to the file and line
/// @param cond
#define bassert(cond) {u8 condVal = (cond); if(!condVal) { io_printCs("\nAssert Failed: `" PASTE_SEQ(cond) "` is not true. "); io_printCs(__FILE__); io_printCs(":"); io_printu64(__LINE__); _exit(10);} }
#else
#define bassert(cond) {}
#endif


#endif //BASSERT_H
