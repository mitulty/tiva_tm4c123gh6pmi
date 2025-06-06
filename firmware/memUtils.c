/**
 * @author: Mitul Tyagi
 * @description: Memory Functions in libc
 */

#include <stddef.h>
#include "stdint.h"

int memcmp(const void *p1, const void *p2, size_t n)
{
    size_t i;

    /**
     * p1 and p2 are the same memory? easy peasy! bail out
     */
    if (p1 == p2)
    {
        return 0;
    }

    // This for loop does the comparing and pointer moving...
    for (i = 0; (i < n) && (*(uint8_t *)p1 == *(uint8_t *)p2);
         i++, p1 = 1 + (uint8_t *)p1, p2 = 1 + (uint8_t *)p2)
        ;

    // if i == length, then we have passed the test
    return (i == n) ? 0 : (*(uint8_t *)p1 - *(uint8_t *)p2);
}
int memcmp_new(const void *vl, const void *vr, size_t n)
{
    const unsigned char *l = vl, *r = vr;
    for (; n && *l == *r; n--, l++, r++)
        ;
    return n ? *l - *r : 0;
}
void *__attribute__((weak)) memset(void *dest, int c, size_t n)
{
    unsigned char *s = dest;

    if (n == 0)
        return dest;

    // Fill the memory with the given character
    while (n--)
        *s++ = c;

    return dest;
}

void *__attribute__((weak)) memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    if (n == 0 || d == s)
        return dest;

    if (d < s)
    {
        while (n--)
            *d++ = *s++;
    }
    else
    {
        d += n;
        s += n;
        while (n--)
            *(--d) = *(--s);
    }

    return dest;
}