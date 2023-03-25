# include <stdio.h>
/* reverse: reverse string s in place */
void reverse(char s[]);
main(){
    int i = 0;
    char str[7] = "abcdefg";
    reverse(str);
    while(str[i] != '\0'){
        printf("%c\n", str[i]);
        ++i;
    }
}
/* reverse: reverse string s in place */
void reverse (char s[]){
    int c, i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i], s[i] = s[j], s[j] = c;
    }
}
