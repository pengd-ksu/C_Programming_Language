//#include <ctype.h>
#include <stdio.h>

/* strlen: return length of string s */
size_t myStrlen_v1(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++) {
        n++;
    }
    return n;
}

int main() {
    size_t n;
    n = myStrlen_v1("hello, world");
    printf("The length of 'hello, world' is : %zu\n", n);
}