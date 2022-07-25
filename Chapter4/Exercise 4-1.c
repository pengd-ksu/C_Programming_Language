# include <stdio.h>
# define MAXLINE 1000                               /* maximum input line length */
int getline (char line[], int max);
int strrindex(char source[], char searchfor[]);
char pattern[] = "ould";                            /* pattern to search for */
/* find all lines matching pattern */
main(){
    char line[MAXLINE];
    int found = 0, position;
    while (getline(line, MAXLINE) > 0){
        if ((position = strrindex (line, pattern)) >= 0){
            printf("%s\n", line);
            printf("Postion: %d\n", position);
            found++;
        }
    }
    return found;
}
/* getline: get line int s, return length */
int getline(char s[], int lim){
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
/* strrindex: returns the position of the rightmost occurrence of t in s, or −1 if there is none */
int strrindex(char s[], char t[]){
    int rindex = -1, i, j, k;
    for(i = 0; s[i] != '\0'; i++){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            rindex = i;
    }
    return rindex;
}
