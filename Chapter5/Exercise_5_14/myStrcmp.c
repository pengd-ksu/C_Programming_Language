/* myStrcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
#include "sortHeader.h"

int myStrcmp(char *s, char *t) {
    for ( ; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}
