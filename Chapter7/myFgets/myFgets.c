#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1000

// myFgets: get at most n chars from iop
char *myFgets(char *s, int n, FILE *iop) {
    register int c;
    register char *cs;

    cs = s;
    while (--n > 0 && (c = getc(iop)) != EOF) {
        if ((*cs++ = c) == '\n') {
            break;
        }
    }
    *cs = '\0';
    return (c == EOF && cs == s) ? NULL : s;
}

// myFputs: put string s on file iop
int myFputs(char *s, FILE *iop) {
    int c;

    while (c = *s++) {
        putc(c, iop);
    }
    return ferror(iop) ? EOF : 0;
}

int main (int argc, char *argv[]) {
    FILE *fp;
    char *prog = argv[0];
    char result[MAXLEN];
    if (argc != 2) {
        printf("Usage: display file");
        return 0;
    }
    if ((fp = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "%s can't open %s\n", prog, *argv);
        exit(1);
    } else {
        myFgets(result, MAXLEN, fp);
        myFputs(result, stdout);
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}