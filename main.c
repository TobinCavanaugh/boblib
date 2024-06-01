#include <unistd.h>
#include "mem/mem.h"
#include "bstr.h"
#include "osio/osio.h"

int main() {
//    write(1, "aaaa", 5);

    bstr test = C("aaaa");
    io_println();
    io_prints(test);
    io_printu64(1);
    io_println();
    io_printu64(22);
    io_println();
    io_printu64(333);
    io_println();
    io_printu64(4444);
    io_println();
    io_printu64(555555);
    io_println();

//    _exit(0);
}
