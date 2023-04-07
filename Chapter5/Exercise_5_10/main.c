#include "calc.h"

// max size of operand or operator
#define MAXOP 100

// reverse Polish calculator
int main(int argc, char *argv[]) {
    double op2;
    char s[MAXOP];

    while (--argc > 0) {
        ungets(" ");
        ungets(*++argv);
        switch (getop(s)) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                // Due to shell expansion, * will be interpreted as all files
                // in the current directory. Must input like: ./expr 3 5 '*'
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                }
                else {
                    printf("error: zero divisor\n");
                }
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    printf("Final result: %.8g\n", pop());
    return 0;
}