#include "calc.h"

// getop: get next operator or numeric operand
int getop(char s[]) {
    int i = 0, c;
    while((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';
    // support fractions like [.71828], and negative numbers
    if (!isdigit(c) && c != '.' && c != '-') {
        // not a number, might be operator
        return c;
    }
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) {
                ungetch(c);
            }
            return '-';
        }
    }
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    if (c == '.') {
        // collect fraction part
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}