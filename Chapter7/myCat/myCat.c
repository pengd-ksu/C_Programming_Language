#include <stdio.h>

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
    
    // no args: copy standard input 
    if (argc == 1) {
        filecopy(stdin, stdout);
    } else {
        // argv[0] is the program name. We need to read the
        // rest of the args
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("myCat: can't open %s\n", *argv);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
}