#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

/* myGetline: get line int s, return length */
int myGetline(char s[], int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

// find: print lines that match patterns from 1st arg
int main (int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

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
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }
    if (argc != 1) {
        printf("Usage: find -x -n pattern\n");
    } else {
        while (myGetline(line, MAXLINE) > 0) {
            lineno++;
            // char *strstr(const char *haystack, const char *needle)
            // strstr finds the first occurence of needle in haystack
            if ((strstr(line, *argv) != NULL) != except) {
                if (number) {
                    printf("%ld:", lineno);
                }
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}