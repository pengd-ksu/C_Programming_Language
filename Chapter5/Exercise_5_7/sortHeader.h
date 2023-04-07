#include <stdio.h>
#include <string.h>

// max length of any input line
#define MAXLEN 1000
// max #lines to be sorted
#define MAXLINES 5000

void myStrcpy(char *, char *);
int myGetline(char [], int);
int readlines(char *[], int, char []);
void writelines(char *[], int);
void myQsort(char *[], int, int);
void swap(char *[], int i, int j);
char *alloc(int);