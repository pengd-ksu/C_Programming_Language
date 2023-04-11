#include <stdio.h>
// tolower is defined in <ctype.h>
#include <ctype.h>

// lower: covert input to lower case
int main() {
    int c;
    
    while ((c = getchar()) != EOF) {
        putchar(tolower(c));
    }
    return 0;
}