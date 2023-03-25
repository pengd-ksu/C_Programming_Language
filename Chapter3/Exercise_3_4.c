# include <stdio.h>
# define abs(x) ((x < 0)? -(x):(x))
void itoa(int n, char s[]);
void reverse(char s[]);
main(){
    char str[10];
    int n = 15;
    itoa(n, str);
    printf("%s\n", str);
}
void itoa(int n, char s[]){
    int i, sign;
    sign = n;                           /* record sign */
    i = 0;
    do{                                 /* generate digtis in reverse order*/
        s[i++] = abs(n % 10) +'0';           /* get next digit */
    }while((n /= 10) != 0);              /* delete it */
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
