#include <stdio.h>
#include <string.h>
/* reverse: reverse string s in place */
void reverse(char s[]);

int main() {
    int i = 0;
    char str[7] = "abcdefg";
    printf("Original string: %s\n", str);
    reverse(str);
    printf("Reversed to string: %s\n", str);
    return 0;
}
/* reverse: reverse string s in place */
void reverse (char s[]){
    int c, i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i], s[i] = s[j], s[j] = c;
    }
}
