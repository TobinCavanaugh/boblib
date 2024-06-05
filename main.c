#include "mem/mem.h"
#include "hstr/hstr.h"
#include "osio/osio.h"
#include "rnd/rnd.h"
#include "mem/mem_copy.h"

#define il_for(__index, __max, x) { u64 __index = 0; for(; __index < __max; __index++){ x; } }
#define il_while(__cond, x) { while(__cond){x;} }

int main() {
    const char *data =
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim aeque doleamus animo, cum corpore dolemus, fieri tamen permagna accessio potest, si aliquod aeternum et infinitum impendere malum nobis opinemur. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm in nobis ut et voluptates. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim aeque doleamus animo, cum corpore dolemus, fieri tamen permagna accessio potest, si aliquod aeternum et infinitum impendere malum nobis opinemur. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm in nobis ut et voluptates. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm";

    int i = 0;
    for (; i < 10; i++) {
        u8 *daata = mem_halloc(128);
        mem_copy(daata, data, 128 + 45);
        mem_hfree(daata);
    }

//    mem_hfree(daata);
//    u64 val = 1000000000;
//    u8* tmp0 = mem_halloc(val);
//    while (val > 0)
//    {
//        val--;
//        tmp0[val] = '0';
//    }
//
//    io_println();
//    io_printu64(mem_get_total_heap_alloc());
//
//    while (1)
//    {
//    }

    io_printf128(rnd_f128() * 1000000);

    return 0;
}
