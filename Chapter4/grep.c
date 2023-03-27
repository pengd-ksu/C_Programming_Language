# include <stdio.h>
// maximum input line length
# define MAXLINE 1000
int myGetline (char line[], int max);
int strindex(char source[], char searchfor[]);
// pattern to search for
char pattern[] = "ould";
// find all lines matching pattern

int main() {
    char line[MAXLINE];
    int found = 0;
    while (myGetline(line, MAXLINE) > 0){
        if (strindex (line, pattern) >= 0){
            printf("%s", line);
            found++;
        }
    }
    return found;
}
/* myGetline: get line int s, return length */
int myGetline(char s[], int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]){
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++){
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        // k > 0 will ensure that t is not a empty string.
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}
