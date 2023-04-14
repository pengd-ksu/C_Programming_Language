#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1000

// filecopy: copy file ifp to file ofp
void filecopy(int ifp, int ofp) {
    char buf[BUFSIZE];
    int n;

    while ((n = read(ifp, buf, BUFSIZE)) > 0) {
        if (write(ofp, buf, n) != n) {
            fprintf(stderr, "cat: write error");
        }
    }
}

// cat: concatenate files, version 1
int main (int argc, char *argv[]) {
    int fp;
    
    // program name for errors
    char *prog = argv[0];
    // no args: copy standard input 
    if (argc == 1) {
        filecopy(0, 1);
    } else {
        // argv[0] is the program name. We need to exclude it and 
        // read the rest of the args
        while (--argc > 0) {
            if ((fp = open(*++argv, O_RDONLY, 0)) == -1) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, 1);
                close(fp);
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}