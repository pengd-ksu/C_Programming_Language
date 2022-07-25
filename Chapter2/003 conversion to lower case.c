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
    if(c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
