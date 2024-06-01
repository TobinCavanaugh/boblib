//
// Created by tobin on 5/31/2024.
//

#include "os.h"
#include "bint.h"

#if SYSTEM_OS == OS_WIN

#include <sysinfoapi.h>

#endif

u64 os_get_page_size() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    return sysInfo.dwPageSize;
}
