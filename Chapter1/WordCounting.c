#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word*/

/* count lines, words, and characters in input */
int main()
{
    int c, nl, nw, nc, state;

    state = OUT;/* For initialization when getting the first word*/
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' '|| c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {/* if (state == OUT) will get us only calculate
        once for every word. Calculation done when entering the first char.*/
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}