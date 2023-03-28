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
            case 'p':
                // to print the top element without popping it
                op2 = pop();
                printf("Last operand: [%.8g]\n", op2);
                push(op2);
                break;
            case 'c':
                // to clear the stack
                clear();
                break;
            case 'd':
                // to duplicate the top element on the stack
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':
                // to swap the last two elements on the stack
                op2 = pop();
                double tmp = pop();
                push(op2);
                push(tmp);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}