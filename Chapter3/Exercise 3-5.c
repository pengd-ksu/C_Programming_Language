# include <stdio.h>
# define abs(x) ((x < 0)? -(x):(x))
void itoa(int n, char s[], int b);
void reverse(char s[]);
main(){
    char str[10];
    int n = 24;
    itoa(n, str, 16);
    printf("%s\n", str);
}
void itoa(int n, char s[], int b){
    int i, j, sign;
    sign = n;                           /* record sign */
    i = 0;
    do{                                 /* generate digtis in reverse order*/
        j = abs(n % b);
        s[i++] =  ((j <= 9)? (j + '0'):(j + 'a' - 10));           /* get next digit */
    }while((n /= b) != 0);              /* delete it */
    if (sign < 0)
        s[i++] ='-';
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
