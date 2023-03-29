#include "calc.h"

// max size of operand or operator
#define MAXOP 100
#define VARNUM 26

// reverse Polish calculator
int main() {
    int type, var = 0;
    double op2;
    char s[MAXOP];
    // variables store user-defined var, v stores most recently print
    double variables[VARNUM], v;
    for (int i = 0; i < VARNUM; i++) {
        variables[i] = 0.0;
    }

    while ((type = getop(s))!= EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
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
            case '%':
                op2 = pop();
                if (op2 != 0) {
                    push(fmod(pop(), op2));
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '=':
            // handle case: 3 A =, which assigns 3 to 'A'
                if (var >= 'A' && var <= 'Z') {
                    pop(); // first pop the place holder, check default
                    variables[var - 'A'] = pop();
                    var = 0;
                } else {
                    printf("Can only take variables from 'A' to 'Z'\n");
                }
                break;
            case '\n':
            // will bump error if only input: 3 A =, since stack is empty.
                v = pop();
                printf("\t%.8g\n", v);
                break;
            default:
                if (type >= 'A' && type <= 'Z') {
                    // var to store last seen variable name
                    var = type;
                    push(variables[type - 'A']);
                } else if (type == 'v') {
                    push(v);
                } else {
                    printf("error: unknown command %s\n", s);
                }
                break;
        }
    }
    return 0;
}