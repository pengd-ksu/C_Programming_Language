#include "myFile.h"

// filecopy: copy file ifp to file ofp
void filecopy(MYFILE *ifp, MYFILE *ofp) {
    int c;

    while ((c = mygetc(ifp)) != MYEOF) {
        myputc(c, ofp);
    }
}

// cat: concatenate files, version 1
int main (int argc, char *argv[]) {
    MYFILE *fp;
    
    // program name for errors
    char *prog = argv[0];
    // no args: copy standard input 
    if (argc == 1) {
        filecopy(mystdin, mystdout);
    } else {
        // argv[0] is the program name. We need to read the
        // rest of the args
        while (--argc > 0) {
            if ((fp = myFopen(*++argv, "r")) == MYNULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, mystdout);
                //fclose(fp);
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}