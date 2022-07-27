//#include <ctype.h>
#include <stdio.h>

/* strlen: return length of string s */
int myStrlen(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++) {
        n++;
    }
    return n;
}

int main() {
    int n;
    n = myStrlen("hello, world");
    printf("The length of hello, world is: %d\n", n);
}