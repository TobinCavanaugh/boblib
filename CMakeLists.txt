cmake_minimum_required(VERSION 3.25)
project(boblib C)

set(CMAKE_C_STANDARD 90)
# -mavx512f
#.....................................................[TEMPORARY UNTIL io_printf128]
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -std=c89 -D_DEBUG -D__USE_MINGW_ANSI_STDIO")

#set(CMAKE_C_COMPILER gcc)
add_executable(boblib
        main.c

        osio/osio.c osio/osio.h

        bint.h

        hstr/hstr.c hstr/hstr.h

        mem/mem.c mem/mem.h

        os.c os.h

        sw.h

        mem/mem_copy.c mem/mem_copy.h

        rnd/rnd.c rnd/rnd.h

        osio/io_numtohstr.c osio/io_numtohstr.h

        assert/bassert.h

        cpu/cpuinfo.c cpu/cpuinfo.h

)
