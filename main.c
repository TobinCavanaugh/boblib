#include <unistd.h>
#include "mem/mem.h"
#include "bstr.h"
#include "osio/osio.h"

#define il_for(__index, __max, x) { u64 __index = 0; for(; __index < __max; __index++){ x; } }
#define il_while(__cond, x) { while(__cond){x;} }

int main() {


    u8 *buf = halloc(512);

    char *data = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim aeque doleamus animo, cum corpore dolemus, fieri tamen permagna accessio potest, si aliquod aeternum et infinitum impendere malum nobis opinemur. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm in nobis ut et voluptates. Ullus investigandi veri, nisi inveneris, et quaerendi defatigatio turpis est, cum esset accusata et vituperata ab Hortensio. Qui liber cum et mortem contemnit, qua qui est imbutus quietus esse numquam potest. Praeterea bona praeterita grata recordatione renovata delectant. Est autem situm.";

    int len = 10;
    memcopy(buf, data, len);

//    il_for(v, len, io_printc(buf[v]););
    il_while(true, io_printCs(":)"));

//    int i = 0;
//    for (; i < len; i++) {
//        io_printc(buf[i]);
//    }


    return 0;
}
