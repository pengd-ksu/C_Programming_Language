#include<stdio.h>
#include<string.h>
#include "alloc.h"
/* Set ALLOCSIZE in alloc.c to 10 to make this test convenient */
int main() {
    int l1 = 3, l2 = 8, l3 = 4;

    char* a1 = alloc(l1);
    if (a1 != 0) {
        a1 = "wet";
        //a1 = "wetyday"; // There's no check for the length, careful
        for (int i = 0; i < l1; i++) {
            printf("%c ", a1[i]);
        }
        putchar('\n');
    }

    //afree(a1); // this will make a2 available.
    char* a2 = alloc(l2);
    if (a2 != 0) {
        a2 = "soundof";
        for (int i = 0; i < l2; i++) {
            printf("%c ", a2[i]);
        }
        putchar('\n');
    }

    char* a3 = alloc(l3);
    if (a3 != 0) {
        a3 = "rain";
        for (int i = 0; i < l3; i++) {
            printf("%c ", a3[i]);
        }
        putchar('\n');
    }
    return 0;
}