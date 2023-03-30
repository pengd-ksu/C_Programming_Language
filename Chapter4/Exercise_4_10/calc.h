#include<stdio.h>
// import bool
#include<stdbool.h>
// for atof()
#include <stdlib.h>
#include <ctype.h>
// for fmod
#include <math.h>

// signal that a number was found
#define NUMBER '0'
#define MAXLINE 100

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
int myGetline(char [], int);