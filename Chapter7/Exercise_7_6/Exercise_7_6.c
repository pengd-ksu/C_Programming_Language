#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN (1 << 5)

int main (int argc, char *argv[]) {
    FILE *f1, *f2;
    char *prog = argv[0];
    char line1[MAXLEN], line2[MAXLEN];
    char *res1, *res2;
    int lineNum;

    if (argc != 3) {
        fprintf(stderr, "Usage: compare f1 f2\n");
    }
    if ((f1 = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "%s can't open file %s\n", prog, *argv);
        exit(1);
    }
    if ((f2 = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "%s can't open file %s\n", prog, *argv);
        exit(2);
    }

    lineNum = 0;
    do {
        res1 = fgets(line1, MAXLEN, f1);
        res2 = fgets(line2, MAXLEN, f2);
        lineNum++;
    } while (res1 != NULL && res2 != NULL && strcmp(line1, line2) == 0);
    if (strcmp(line1, line2) != 0) {
        printf("Line number: %d\n", lineNum);
        printf("file1: [%s], file2: [%s]\n", 
                res1 == NULL ? "EOF":line1,
                res2 == NULL ? "EOF":line2);
    }
    exit(0);
}