# include <stdio.h>
/* strlen: return length of s */
int strlen(const char s[]);                         /* make sure the function doesn't change s[]*/
main(){
    char str[] = "Hello, world !";
    int length = strlen(str);
    printf("The length of str is %d\n", length);
    str[0] = 'h';                                   /* outside this function we could still change str[] */
    printf(str);
}

int strlen(const char s[]){
    int i;
    i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}
