#include "tailHeader.h"

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
            // delete newline, this is very important. myGetline
            // returns a length that include '\n' if there's a 
            // new line by the end of the string. The final '\0'
            // attached in myGetline will not be included in p.
            // Since p's allocbuf is a static var, it will persist
            // in alloc. Every time when p provides a pointer to
            // lineptr, it would cause a problem for myStrcmp if
            // there's no end to the part of string that the 
            // pointer points to.
            line[len-1] = '\0';
            myStrcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

// writelines: write output lines
void writeLastNumLines(char *lineptr[], int num, int nlines) {
    int start = nlines - num;
    for (int i = start; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}