#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#define MAXLINE 1000

void myFind(FILE *f, char* fileName, int except, int number, char *pattern) {
    int lineNum;
    char line[MAXLINE];
    
    lineNum = 0;

    while (fgets(line, MAXLINE, f) != NULL) {
        ++lineNum;
        // char *strstr(const char *haystack, const char *needle)
        // strstr finds the first occurence of needle in haystack
        if ((strstr(line, pattern) != NULL) != except) {
            // file name exists
            if (*fileName) {
                printf("File %s - \n", fileName);
            }
            if (number) {
                printf("Line number: %d\n", lineNum);
            }
            printf("%s\n", line);
        }
    }
}

// find: print lines that match patterns from 1st arg
int main (int argc, char *argv[]) {
    char pattern[MAXLINE];
    FILE *fp;
    int c, except = 0, number = 0;

    char *prog = argv[0];
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                // 'x' for except, doesn't include this pattern
                case 'x':
                    except = 1;
                    break;
                // 'n' means printing the number
                case 'n':
                    number = 1;
                    break;
                default:
                    fprintf(stderr, "find: illegal option %c\n", c);
                    argc = 0;
                    break;
            }
        }
    }
    if (argc >= 1) {
        strcpy(pattern, *argv);
    } else {
        fprintf(stderr, "Usage: find -x -n pattern [file1, file2...]\n");
        exit(1);
    }
    if (argc == 1) {
        myFind(stdin, "", except, number, pattern);
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr,"%s can't open %s\n", prog, *argv);
                exit(2);
            } else {
                myFind(fp, *argv, except, number, pattern);
                fclose(fp);
            }
        }
    }
    return 0;
}