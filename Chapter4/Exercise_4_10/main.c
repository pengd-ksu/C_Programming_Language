#include "calc.h"

// max size of operand or operator
#define MAXOP 100

// reverse Polish calculator
int main() {
    int type;
    double op2;
    char s[MAXOP];

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
            case '\n':
                printf("%f\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}