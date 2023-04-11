#include <stdio.h>
// tolower is defined in <ctype.h>
#include <ctype.h>
// to import strcmp
#include <string.h>

// lower: covert input to lower case
int main(int argc, char *argv[]) {
    int c;
    
    if (strcmp(argv[1], "lower") == 0) {
        while ((c = getchar()) != EOF) {
            putchar(tolower(c));
        }
    } else if (strcmp(argv[1], "upper") == 0) {
        while ((c = getchar()) != EOF) {
            putchar(toupper(c));
        }
    }
    return 0;
}