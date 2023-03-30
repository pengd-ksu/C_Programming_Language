#include "header.h"

int main() {
    int c;
    char s[MAXSIZE] = "Remove this string.";
    char t[MAXSIZE] = "A contrast to prev.";
    printf("String s: [%s]\n", s);
    printf("String t: [%s]\n", t);
    ungets(s);
    //printf("After ungets to string s: [%s]\n", s);
    for (int i = strlen(t); (c = getch()) != EOF && i < MAXSIZE; i++) {
        t[i] = c;
    }
    printf("New string t: [%s]\n", t);
    return 0;
}