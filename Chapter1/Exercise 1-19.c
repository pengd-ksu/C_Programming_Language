# include <stdio.h>
# define MAXLINE 1000                   /* maximum input line size */
# define threshold 80
int getline(char line[], int maxline);
void reverse (char s[]);             /* can't use remove as function name here, for conflicting with stdio.h*/
main(){
    int len;                            /* current line length */
    char line[MAXLINE];                 /* current input line */
    while(getline(line, MAXLINE) > 0){
        reverse(line);
        printf("%s", line);
    }
    return 0;
}
/* getline: read a line into s, return length */
int getline(char s[], int lim){
    int c, i;
    for (i = 0; i < lim-1 &&(c = getchar()) != EOF &&c != '\n'; ++i){
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* remove trailing blanks and tabs from character string s, and delete entire blank lines */
void reverse(char s[]){
    int i, j;
    char temp;
    i = 0;
    while(s[i] != '\0'){
        i++;
    }
    i--;
    if(s[i] == '\n')
        --i;                                /* find the end the input string */
    j = 0;
    while (j < i){
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        ++j;
        --i;
    }
}
