#include <stdio.h>

/*If you're typing at the terminal and you want to provoke
an end-of-file, use CTRL-D (unix-style systems) or CTRL-Z (Windows).*/

int main(){

    int c;

    while((c = getchar()) != EOF)
        putchar(c);
    printf("%d - at EOF\n",c);

}
