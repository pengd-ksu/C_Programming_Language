# include <stdio.h>
void squeeze(char s[], int c);
int main() {
    char original[] = "Hello, world!";
    char remove = 'o';
    printf("Original string: %s\n", original);
    squeeze(original, remove);
    printf("After removing char %c: %s\n", remove, original);
}

/* squeeze: delete all c from s */
void squeeze(char s[], int c){
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++){
        if(s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}
