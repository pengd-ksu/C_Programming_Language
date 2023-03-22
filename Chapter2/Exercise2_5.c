# include <stdio.h>
int any(char s1[], char s2[]);
main(){
    char c1[] = "Hello, world!\n";
    char c2[] = "00o";
    int loc = any(c1, c2);
    printf("%d\n", loc);
}

/* any: return first location in s1 where any char from s2 occurs */
int any(char s1[], char s2[]){
    int i, j;
    for(i = 0; s1[i] != '\0'; i++){
        for(j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
            ;
        if(s2[j] != '\0')
            return i;
    }
    return -1;
}
