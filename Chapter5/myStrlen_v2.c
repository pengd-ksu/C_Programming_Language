//#include <ctype.h>
#include <stdio.h>

/* strlen: return length of string s */
size_t myStrlen_v2(char *s) {
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}

int main() {
    size_t n;
    n = myStrlen_v2("hello, world");
    printf("The length of 'hello, world' is : %zu\n", n);
}