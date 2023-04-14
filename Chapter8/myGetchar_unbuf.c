#include "unistd.h"
#include <stdio.h>

// myGetchar: unbuffered single character input
int myGetchar(void) {
    char c;
    
    // Cast c to unsigned char to eliminate any problem 
    // of sign extension
    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int main () {
    int c;
    while ((c = myGetchar()) != EOF) {
        putchar(c);
    }
    return 0;
}