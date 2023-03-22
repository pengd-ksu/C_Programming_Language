# include <stdio.h>
/* lower: convert c to lower case; ASCII only */
int lower(int c);
main(){
    int c;
    while((c = getchar()) != EOF){
        if(c != '\n'){
            char letter = lower(c);
            printf("The corresponding letter is %c\n", letter);
        }
    }
}

int lower(int c){
    return c >= 'A' && c <= 'Z'? c +'a' - 'A': c;
}
