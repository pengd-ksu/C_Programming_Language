# include <stdio.h>
# include <ctype.h>
/* atoi: convert s to integer; version 2 */
int atoi(char s[]);
main(){
    char str[] = "  -25a";
    int n = atoi(str);
    printf("The conversion number is %d\n", n);
}

int atoi(char s[]){
    int i, n, sign;
    for(i = 0; isspace(s[i]); i++)              /* skip white space */
        ;
    sign = (s[i] == '-')? -1:1;
    if(s[i] == '+' || s[i] == '-')              /* skip sign if there is one */
        i++;
    for(n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}
