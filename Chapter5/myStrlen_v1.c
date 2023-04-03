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
    char c[] = "Martian.";
    n = myStrlen_v1(c);
    printf("The length of [%s] is : [%zu]\n", c, n);
}