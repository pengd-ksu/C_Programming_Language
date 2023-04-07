#include <stdio.h>
#include <string.h>
// to import atof
#include <stdlib.h>

// max length of any input line
#define MAXLEN 1000
// max #lines to be sorted
#define MAXLINES 5000

void myStrcpy(char *, char *);
int myGetline(char [], int);
int readlines(char *[], int);
void writelines(char *[], int, int);
void myQsort(void **, int, int, int (*)(void *, void *));
void swap(void *[], int i, int j);
char *alloc(int);
int numcmp(char *, char *);
int myStrcmp(char *, char *);