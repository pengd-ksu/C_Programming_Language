# include <stdio.h>
# include <string.h>

int trim (char s[]);

int main() {
    char str[20] = "Hello, world\t ";
    printf("String: [%s], with ending index %lu\n", str, strlen(str));
    int n = trim(str);
    printf("After trimming: [%s] with new ending index %d\n", str, n);
    return 0;
}

// trim: remove trailing blanks, tabs and newlines
int trim(char s[]) {
    int n;
    for (n = strlen(s) - 1; n >= 0; n--){
        if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n') {
            break;
        }
    }
    s[n+1] = '\0';
    return n;
}
