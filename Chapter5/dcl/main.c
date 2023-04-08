#include "dclHeader.h"

// convert declaration to words
int main() {
    while (gettoken() != EOF) {
        // 1st token on line is the datatype
        strcpy(datatype, token);
        // ready to copy strings to the end of out.
        out[0] = '\0';
        // parse rest of lines
        dcl();
        if (tokentype != '\n') {
            printf("syntax error\n");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}