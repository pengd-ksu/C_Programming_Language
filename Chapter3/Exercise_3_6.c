# include <stdio.h>
# define abs(x) ((x < 0)? -(x):(x))
void itoa(int n, char s[], int width);
void reverse(char s[]);
main(){
    char str1[20], str2[20];
    itoa(-24, str1, 16);
    itoa(1150, str2, 16);
    printf("%s\n%s\n", str1, str2);
}
void itoa(int n, char s[], int width){
    int i, j, sign;
    sign = n;                           /* record sign */
    i = 0;
    do{                                 /* generate digtis in reverse order*/
        j = abs(n % 10);
        s[i++] =  j + '0';           /* get next digit */
    }while((n /= 10) != 0);              /* delete it */
    if (sign < 0)
        s[i++] ='-';
    while (i < width - 1)
        s[i++] = ' ';
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
