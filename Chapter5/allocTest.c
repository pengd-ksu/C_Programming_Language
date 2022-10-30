#include<stdio.h>
#include<string.h>
#include "alloc.h"
/* Set ALLOCSIZE in alloc.c to 10 to make this test convenient */
int main() {
    int l1 = 3, l2 = 8, l3 = 4;

    char* a1 = alloc(l1);
    if (a1 != 0) {
        a1[0] = 'w';
        a1[1] = 'e';
        a1[2] = 't';
        for (int i = 0; i < strlen(a1); i++) {
            printf("%i of a1 is: %c\n", i, a1[i]);
        }
    }

    //afree(a1); // this will make a2 available.
    char* a2 = alloc(l2);
    if (a2 != 0) {
        a2[0] = 's';
        a2[1] = 'o';
        a2[2] = 'u';
        a2[3] = 'n';
        a2[4] = 'd';
        a2[5] = 'o';
        a2[6] = 'f';
        for (int i = 0; i < strlen(a2); i++) {
            printf("%i of a2 is: %c\n", i, a2[i]);
        }
    }

    char* a3 = alloc(l3);
    if (a3 != 0) {
        a3[0] = 'r';
        a3[1] = 'a';
        a3[2] = 'i';
        a3[3] = 'n';
        for (int i = 0; i < strlen(a3); i++) {
            printf("%i of a3 is: %c\n", i, a3[i]);
        }
    }
    return 0;
}