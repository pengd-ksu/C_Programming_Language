#include "sortHeader.h"

// storage for alloc
static char allocbuf[MAXLEN];
// next free position
static char *allocp = allocbuf;

// return pointer to n characters
char *alloc(int n) {
    if (allocbuf + MAXLEN - allocp >= n) {   /* it fits */
        allocp += n;
        return allocp - n;                       /* old p */
    } else                                      /* not enough room */
        return 0;
}

// free storage pointed to by p
void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + MAXLEN)
        allocp = p;
}
