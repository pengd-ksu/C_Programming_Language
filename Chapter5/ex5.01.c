#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign, getSign;
    /* skip white space */
    while (isspace(c = getch())) {
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        getSign = c;
        if (!isdigit(c = getch())) {
            if (c != EOF) {
                ungetch(c);
                ungetch(getSign);
                return getSign;
            }
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * (*pn) + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int main() {
    int n = -10000000;
    getint(&n);
    if (n == -10000000) {
        printf("Input number is invalid.\n");
    } else {
        printf ("The intput number is: %d\n", n);
    }
}