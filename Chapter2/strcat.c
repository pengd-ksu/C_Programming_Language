# include <stdio.h>
void mystrcat(char s[], char t[]);
int main() {
    char s[] = "Hello ";
    char t[] = "world";
    printf("s: [%s], t: [%s]\n", s, t);
    mystrcat(s, t);
    printf("After strcat, s became: %s\n", s);
}
/* strcat: concatenate t to end of s; s must be big enough */
void mystrcat(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}
