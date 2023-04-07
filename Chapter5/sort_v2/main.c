#include "sortHeader.h"

// pointers to text lines
char *lineptr[MAXLINES];

// sort input lines
int main(int argc, char *argv[]) {
    // number of input lines read
    int nlines;
    // 1 if numeric sort
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        myQsort((void **) lineptr, 0, nlines - 1,
                (int (*)(void*, void*))(numeric ? numcmp : myStrcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}