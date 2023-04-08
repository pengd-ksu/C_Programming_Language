#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);
int getch(void);
void ungetch(int);

int gettoken(void);
// type of last token
int tokentype;
// last token string
char token[MAXTOKEN];
// identifier name
char name[MAXTOKEN];
// data type = char, int, etc
char datatype[MAXTOKEN];
// output string
char out[1000];
