// to import va_list, va_start, va_end
#include <stdarg.h>
#include <stdio.h>

// minprintf: minimal printf with variable argument list
void minprintf(char *fmt, ...) {
    // points to each unnamed arg in turn
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    // make ap point to 1st unnamed arg
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar (*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++) {
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
    // clean up when done
    va_end(ap);
}

int main() {
    char *name = "Peng";
    minprintf("Hello darkness, my old friend\n");
    minprintf("Hi %s\n", name);
}