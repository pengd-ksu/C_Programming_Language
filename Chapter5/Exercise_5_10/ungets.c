#include "calc.h"

void ungets(char s[]) {
    int l = strlen(s);
    for (int i = l - 1; i >= 0; i--) {
        ungetch(s[i]);
    }
}