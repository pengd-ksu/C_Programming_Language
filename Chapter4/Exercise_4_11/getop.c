#include "calc.h"

// getop: get next operator or numeric operand
int getop(char s[]) {
    int i = 0, c;
    // 0 is a sign that there's no ungetch last time.
    static int lastC = 0;
    if (lastC == 0) {
        c = getchar();
    } else {
        c = lastC;
        lastC = 0;
    }
    while((s[0] = c) == ' ' || c == '\t') {
        c = getchar();
    }
    s[1] = '\0';
    // support fractions like [.71828], and negative numbers
    if (!isdigit(c) && c != '.' && c != '-') {
        // not a number, might be operator
        return c;
    }
    if (c == '-') {
        if (isdigit(c = getchar()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) {
                lastC = c;
            }
            return '-';
        }
    }
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getchar())) {
            ;
        }
    }
    if (c == '.') {
        // collect fraction part
        while (isdigit(s[++i] = c = getchar())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        lastC = c;
    }
    return NUMBER;
}