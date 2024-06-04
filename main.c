#include <unistd.h>
#include "mem/mem.h"
#include "hstr/hstr.h"
#include "osio/osio.h"

#define il_for(__index, __max, x) { u64 __index = 0; for(; __index < __max; __index++){ x; } }
#define il_while(__cond, x) { while(__cond){x;} }

#include <assert.h>

#include "sw.h"
#include "assert/bassert.h"
#include "mem/memcopy.h"
#include "rnd/rnd.h"

int main()
{
    int len = 1000;
    //    _Alignas(16) u8 *buf[1800] = {0};

    const char* data =
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim aeque doleamus animo, cum corpore dolemus, fieri tamen permagna accessio potest, si aliquod aeternum et infinitum impendere malum nobis opinemur. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm in nobis ut et voluptates. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim aeque doleamus animo, cum corpore dolemus, fieri tamen permagna accessio potest, si aliquod aeternum et infinitum impendere malum nobis opinemur. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm in nobis ut et voluptates. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm";

    double us = sw_start_us();

    //0.9MB

    printf("%.17Lf\n", rnd_f128());
    printf("%.17Lf\n", rnd_f128());
    printf("%.17Lf\n", rnd_f128());
    printf("%.17Lf\n", rnd_f128());


    //    il_while(true, io_printCs(":)"));

    //    int i = 0;
    //    for (; i < len; i++) {
    //        io_printc(buf[i]);
    //    }


    return 0;
}
