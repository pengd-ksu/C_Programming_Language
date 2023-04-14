#include "unistd.h"
#include <stdio.h>

#define BUFSIZ 1024

// myGetchar: simple buffered version
int myGetchar(void) {
    static char buf[BUFSIZ];
    // Assign the pointer bufp to the array buf, could also 
    // be written as: static char *bufp = &buf[0];
    static char *bufp = buf;
    static int n = 0;

    // buffer is empty
    if (n == 0) {
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int main () {
    int c;
    while ((c = myGetchar()) != EOF) {
        putchar(c);
    }
    return 0;
}