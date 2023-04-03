#include "sortHeader.h"

/* getline: read a line into s, return length */
int myGetline(char s[], int lim) {
    int c, i;
    
    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

// readlines: read input lines
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = myGetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            // delete newline
            line[len-1] = '\0';
            myStrcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

// writelines: write output lines
void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}