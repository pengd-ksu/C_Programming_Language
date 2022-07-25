# include <stdio.h>
# define before 0
# define after 1
# define initial -1
main(){
    int i, c, prev = initial, current, status;
    for(status = before; (c = getchar()) != EOF; ){
        if(c == '\n')
            ;
        else if(c != '-'){
            if(status == before)
                prev = c;
            else{
                current = c;
                for(i = 0; i <= current - prev; i++)
                    putchar(prev + i);
                putchar('\n');
                status = before;
                prev = initial;
            }
        }
        else{
            if(prev != initial)
                status = after;
        }
    }
}
