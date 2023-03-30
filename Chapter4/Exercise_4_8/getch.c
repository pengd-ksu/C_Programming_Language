#include "calc.h"

// Since there will never be more than one char to pushback, we 
// don't need a char array here.
char buff = 0;

// get a (possibly pushed back) character
int getch(void) {
    int c;
    if (buff != 0) {
        c = buff;
    } else {
        c = getchar();
    }
    buff = 0;
    return c;
}

// push character back on input
void ungetch(int c) {
    if (buff != 0) {
        printf("ungetch: too many characters\n");
    } else {
        buff = c;
    }
}