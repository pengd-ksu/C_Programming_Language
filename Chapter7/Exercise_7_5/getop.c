#include "calc.h"

// Based on exercise 4.3, support negative number
// getop: get next operator or numeric operand
// Since we will use scanf and sscanf instead of getch
// and putch, we need a buffer to store last char.
int getop(char s[]) {
    int i, rc;
    // must be char, int cause problems. Need further check.
    char c;
    static char lastc[] = " ";
    // read lastc[0] to c
    sscanf(lastc, "%c", &c);
    // clear the buffer
    lastc[0] = ' ';
    while((s[0] = c) == ' ' || c == '\t') {
        // Two purposes for this part: 1. continue scan, which will
        // end the while loop when c is not a white space; 2. scanf
        // will not alter c when meet the end of file (EOF), manually
        // assign c with EOF.
        if (scanf("%c", &c) == EOF) {
            c = EOF;
        }
    }
    s[1] = '\0';
    // support fractions like [.71828], and negative numbers
    if (!isdigit(c) && c != '.' && c != '-') {
        // not a number, might be operator
        return c;
    }
    i = 0;
    if (c == '-') {
        // Check next input char to see if this is part of a
        // negative number (eg -3.14, -.314), or operator minus
        scanf("%c", &c);
        if (isdigit(c) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) {
                lastc[0] = c;
            }
            return '-';
        }
    }
    if (isdigit(c)) {
        do {
            // scanf returns the successful matched and assigned
            // items. And it returns EOF upon end of file. Once
            // scanf found EOF, it won't change c anymore. rc is
            // used against an infinite loop
            rc = scanf("%c", &c);
            if (!isdigit(s[++i] = c)) {
                break;
            }
        } while (rc != EOF);
    }
    if (c == '.') {
        // collect fraction part
        do {
            rc = scanf("%c", &c);
            if (!isdigit(s[++i] = c)) {
                break;
            }
        } while (rc != EOF);
    }
    s[i] = '\0';
    if (c != EOF) {
        lastc[0] = c;
    }
    return NUMBER;
}