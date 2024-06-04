//
// Created by tobin on 5/31/2024.
//

#include "hstr.h"

#include "../assert/bassert.h"
#include "../mem/mem.h"


/* NOTES:
 * DESIGN ====================================================================
 * This could all be handled using hstr
 *
 */

u64 internal_C_strlen(char* data)
{
    int i = 0;
    while (data[i] != '\0')
    {
        i++;
    }
    return i;
}

u0 hstr_set_end(hstr* str, u64 len)
{
    bassert(str->char_arr != NULL);
    str->end_ptr = str->char_arr + len;
    bassert(str->end_ptr != NULL);
}

u64 hstr_len(hstr* str)
{
    bassert(str->char_arr <= str->end_ptr);
    return ((u64)str->end_ptr - (u64)&str->char_arr[0]);
}

u0 hstr_append(hstr* str, hstr* add)
{
}

u0 hstr_appendL(hstr* str, hstr add)
{
}

u0 hstr_appendC(hstr* str, char* add)
{
}


//strop(string, operation, args)


hstr* hstr_create(char* source)
{
    hstr* str = mem_halloc(sizeof(hstr));
    u64 len = internal_C_strlen(source);
    str->char_arr = mem_halloc(len);

    int i = 0;
    for (; i < len; i++)
    {
        str->char_arr[i] = source[i];
    }

    hstr_set_end(str, len);
    bassert(hstr_len(str) == internal_C_strlen(source));

    return str;
}
