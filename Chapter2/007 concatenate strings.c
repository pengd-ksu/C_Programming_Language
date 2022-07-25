# include <stdio.h>
void strcat(char s[], char t[]);
main(){
    char s[] = "Hello,";
    char t[] = "world\n";
    strcat(s, t);
    printf("New s = %s", s);
}
/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char s[], char t[]){
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}
