#include "header.h"
#define BUFSIZE 100

// changed the buf to int array, since EOF(-1) set as char and
// converted to int might lose information, like filled with 1
// or 0 from the left side.
int buf[BUFSIZE];
// next free position in buf
int bufp = 0;

// get a (possibly pushed back) character
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}