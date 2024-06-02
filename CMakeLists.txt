cmake_minimum_required(VERSION 3.25)
project(boblib C)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG -mavx512f")

#set(CMAKE_C_COMPILER gcc)
add_executable(boblib main.c osio/osio.c osio/osio.h bint.h bstr.c bstr.h mem/mem.c mem/mem.h os.c os.h)
