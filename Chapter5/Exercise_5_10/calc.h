#include<stdio.h>
// for atof()
#include <stdlib.h>
#include <ctype.h>
// for strlen
#include <string.h>

// signal that a number was found
#define NUMBER '0'
void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
void ungets(char []);