#include "calc.h"

// getop: get next operator or numeric operand
int getop(char s[]) {
    int i = 0;
    int len = myGetline(s, MAXLINE);
    if (len == 0) {
        return EOF;
    }
    while(s[i] == ' ' || s[i] == '\t') {
        i++;
    }
    // support fractions like [.71828], and negative numbers
    if (!isdigit(s[i]) && s[i] != '.' && s[i] != '-') {
        // not a number, might be operator
        return s[i];
    }
    if (s[i] == '-' && (((++i) == len) || (!isdigit(s[i]) && (s[i] != '.')))) {
        return '-';
    }
    return NUMBER;
}