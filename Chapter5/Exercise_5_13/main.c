#include "tailHeader.h"

// pointers to text lines
char *lineptr[MAXLINES];

int main(int argc, char *argv[]) {
    // number of input lines read
    int nlines, num;
    if (argc == 1) {
        num = NUMLINES;
    } else if (argc == 2 && (*++argv)[0] == '-') {
        // The C library function int atoi(const char *str) converts
        // the string argument str to an integer (type int). Pass 
        // an address to atoi, which is argv[0]+1, to the next char,
        // like tail -n, the beginning of n is passed. Address 
        // arithmetic will take '1' as one char.
        num = atoi(argv[0]+1);
    } else {
        printf("Usage: tail -n");
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        // if 'tail -n', n is smaller than the #line we input, just
        // output all the lines.
        if (nlines > num) {
            writeLastNumLines(lineptr, num, nlines);
        } else {
            writeLastNumLines(lineptr, nlines, nlines);
        }
        return 0;
    } else {
        printf("error: input too big to store\n");
        return 1;
    }
}