#include "sortHeader.h"

// pointers to text lines
char *lineptr[MAXLINES];

// sort input lines
int main(int argc, char *argv[]) {
    // number of input lines read
    int nlines;
    // 1 if numeric sort
    int numeric = 0;
    int dec = 0;
    char c;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch(c) {
                case 'n' :
                    numeric = 1;
                    break;
                case 'r' :
                    dec = 1;
                    break;
                default:
                    printf("Illegal option %c\n", c);
                    return 1;
            }
        }
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        myQsort((void **) lineptr, 0, nlines - 1,
                (int (*)(void*, void*))(numeric ? numcmp : myStrcmp));
        writelines(lineptr, nlines, dec);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}