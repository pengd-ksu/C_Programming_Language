#include <stdio.h>

void printd(int);

int main () {
    printd(-12345);
    putchar('\n');
    printd(67890);
    putchar('\n');
    return 0;
}

// printd: print n in decimal
void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}