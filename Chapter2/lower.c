# include <stdio.h>
/* lower: convert c to lower case; ASCII only */
int lower(int c);
int main() {
    int c;
    while((c = getchar()) != EOF){
        if(c != '\n'){
            char letter = lower(c);
            printf("%c to lower case: %c\n", c, letter);
        }
    }
}

int lower(int c){
    if(c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
