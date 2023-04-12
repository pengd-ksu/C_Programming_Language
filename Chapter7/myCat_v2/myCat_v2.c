#include <stdio.h>
#include <stdlib.h>

// filecopy: copy file ifp to file ofp
void filecopy(FILE *ifp, FILE *ofp) {
    int c;

    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
}

// cat: concatenate files, version 1
int main (int argc, char *argv[]) {
    FILE *fp;
    
    // program name for errors
    char *prog = argv[0];
    // no args: copy standard input 
    if (argc == 1) {
        filecopy(stdin, stdout);
    } else {
        // argv[0] is the program name. We need to read the
        // rest of the args
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}