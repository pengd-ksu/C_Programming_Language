#include <stdio.h>

int main(){
    int c, lastc;
    lastc = EOF;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (lastc != ' ')
                putchar(c);
        }
        else
            putchar(c);
        lastc = c;
    }
}