# include <stdio.h>
# include <string.h>
int trim (char s[]);
main(){
    char str[20] = "Hello, world\n";
    int n = trim(str);
    printf("The string now is: %s\nThe number is: %d\n", str, n);
}
/* trim: remove trailing blanks, tabs and newlines */
int trim(char s[]){
    int n;
    for (n = strlen(s) - 1; n >= 0; n--){
        if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    }
    s[n+1] = '0';
    return n;
}
