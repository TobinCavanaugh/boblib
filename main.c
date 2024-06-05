#include "mem/mem.h"
#include "hstr/hstr.h"
#include "osio/osio.h"
#include "rnd/rnd.h"
#include "mem/mem_copy.h"
#include "sw.h"
#include "cpu/cpuinfo.h"

#define il_for(__index, __max, x) { u64 __index = 0; for(; __index < __max; __index++){ x; } }
#define il_while(__cond, x) { while(__cond){x;} }

int main() {
    const char *strData =
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim aeque doleamus animo, cum corpore dolemus, fieri tamen permagna accessio potest, si aliquod aeternum et infinitum impendere malum nobis opinemur. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm in nobis ut et voluptates. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim aeque doleamus animo, cum corpore dolemus, fieri tamen permagna accessio potest, si aliquod aeternum et infinitum impendere malum nobis opinemur. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm in nobis ut et voluptates. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm";

    int max = 1000000;

//    double us = sw_start_us();
//    int i = 0;
//    for (; i < max; i++) {
//
//        u8 *data = mem_halloc(128);
//        mem_copy(data, strData, 128);
//        mem_hfree(data);
//    }
//    sw_print_us(us);
//
//    us = sw_start_us();
//    i = 0;
//    for (; i < max; i++) {
//
//        u8 *data = malloc(128);
//        mem_copy(data, strData, 128);
//        free(data);
//    }
//    sw_print_us(us);


    io_printu64(cpu_get_feature(CF_MMX));
    io_printu64(cpu_get_feature(CF_SSE4_1));
    io_printu64(cpu_get_feature(CF_SSE4_2));
    io_printu64(cpu_get_feature(CF_RDRAND));
    io_printu64(cpu_get_feature(CF_AVX));
    io_printu64(cpu_get_feature(CF_SMX));
    io_printu64(cpu_get_feature(CF_TM1));
    io_printu64(cpu_get_feature(CF_TM2));
    io_printu64(cpu_get_feature(CF_SS));

    io_println();

    io_printCs(cpu_get_manufacturer_id());

//    while (1) {
//        int min = 0;
//        int max = 100;
//        u64 tval = (rnd_u64R(min, max));
//
//        io_printu64(tval);
//        io_println();
//
//        if (tval < min || tval > max) {
//            break;
//        }
//    }
//    io_println();

//    io_printf128(rnd_f128() * 1000000);

    return 0;
}
