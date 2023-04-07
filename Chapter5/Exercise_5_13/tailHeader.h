#include <stdio.h>
#include <string.h>
// to import atoi
#include <stdlib.h>

// max length of any input line
#define MAXLEN 1000
// max #lines to store
#define MAXLINES 5000
// default NUMLINES to print starting from the end of input 
#define NUMLINES 10

void myStrcpy(char *, char *);
int myGetline(char [], int);
int readlines(char *[], int);
void writeLastNumLines(char *[], int, int);
void swap(char *[], int i, int j);
char *alloc(int);