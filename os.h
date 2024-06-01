//
// Created by tobin on 5/31/2024.
//

#ifndef BOBLIB_OS_H
#define BOBLIB_OS_H

#define SYSTEM_OS
#define OS_WIN 0
#define OS_POSIX 1

#ifdef WIN64
#define SYSTEM_OS OS_WIN
#elif WIN32
#define SYSTEM_OS OS_WIN
#elif _WIN32
#define SYSTEM_OS OS_WIN
#elif WINNT
#define SYSTEM_OS OS_WIN
#else
#define SYSTEM_OS OS_POSIX
#endif

#endif //BOBLIB_OS_H
