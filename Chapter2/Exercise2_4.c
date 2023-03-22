# include <stdio.h>
void squeeze(char s1[], char s2[]);
main(){
    char c1[] = "Hello, world!\n";
    char c2[] = "wow";
    squeeze(c1, c2);
    printf("%s\n", c1);
}

/* squeeze: delete each char in s1 which is in s2 */
void squeeze(char s1[], char s2[]){
    int i, j, k;
    k = 0;
    while(s2[k] != '\0'){
        for (i = j = 0; s1[i] != '\0'; i++){
            if(s1[i] != s2[k])
                s1[j++] = s1[i];
        }
        s1[j] = '\0';
        k++;
    }
}
