#include "unistd.h"
#include <fcntl.h>
#include <stdio.h>
// to use variable sized args
#include <stdarg.h>
// to import exit()
#include <stdlib.h>

// RW for owner, grouper, others
#define PERMS 0666
#define BUFSIZ 1024

// error: print an error message and die
void error(char *fmt, ...) {
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

// cp: copy f1 to f2
int main(int argc, char *argv[]) {
    int f1, f2, n;
    char buf[BUFSIZ];

    if (argc != 3) {
        error("Usage: myCp from to");
    }
    if ((f1 = open(argv[1], O_RDONLY)) == -1) {
        error("myCp: can't open %s", argv[1]);
    }
    if ((f2 = creat(argv[2], PERMS)) == -1) {
        error("myCp: can't create %s, mode %03o",
            argv[2], PERMS);
    }
    // Check on file descriptor, and get fd's value (4 in this case)
    fprintf(stdout, "f2: %d\n", f2);
    while ((n = read(f1, buf, BUFSIZ)) > 0) {
        // It could still write to file with int that queals to fd.
        // Need to understand it later maybe in CSAPP or os.
        //if (write(4, buf, n) != n) {
        if (write(f2, buf, n) != n) {
            error("myCp: write error on file %s", argv[2]);
        }
    }
    return 0;
}

