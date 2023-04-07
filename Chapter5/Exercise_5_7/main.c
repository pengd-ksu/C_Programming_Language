#include "sortHeader.h"

// pointers to text lines
char *lineptr[MAXLINES];

// sort input lines
int main() {
    // number of input lines read
    int nlines;
    char line[MAXLEN];
    if ((nlines = readlines(lineptr, MAXLINES, line)) >= 0) {
        myQsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}