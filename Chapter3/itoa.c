#include <stdio.h>
#include <string.h>
#define MAX 100

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    int n = -15;
    char str[MAX];
    itoa(n, str);
    printf("Int %d to string %s\n", n, str);
    return 0;
}

void itoa(int n, char s[]){
    int i, sign;
    if((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do{
        // generate digtis in reverse order
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);
    if (sign < 0) {
        s[i++] ='-';
    }
    s[i] = '\0';
    reverse(s);
}
void reverse(char s[]){
    int c, i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
