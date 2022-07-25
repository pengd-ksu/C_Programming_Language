# include <stdio.h>
# define TABINC 8
main(){
    int c, nb, pos;
    pos = 0;
    nb = 0;
    while((c = getchar()) != EOF){
        if(c == '\t'){
            nb = TABINC - pos % TABINC;
            while(nb > 0){
                putchar(' ');
                ++pos;
                --nb;
            }
        }
        else if(c == '\n'){
            putchar(c);
            pos = 0;
        }
        else{
            putchar(c);
            ++pos;
        }
    }
}
