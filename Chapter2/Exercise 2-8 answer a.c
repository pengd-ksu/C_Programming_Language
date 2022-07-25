# include<stdio.h>
unsigned rightrot(unsigned x, int n);
int wordlength(void);
main(){
    unsigned x = 121;                                   /* binary: 1111001 */
    printf("The unsigned word length on this machine is %d\n", wordlength());           /* on this machine it's 32*/
    printf("rotate %u to the right by 3 positions is: %u\n", x, rightrot(x, 3));        /* it would be 00100000000000000000000000001111*/
}
/* rightrot: rotate x to the right by n positions */
unsigned rightrot(unsigned x, int n){
    int wordlength(void);
    int rbit;                                           /* rightmost bit */
    while(n-- > 0){
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;                                     /* shift x 1 pposition right */;
        x = x | rbit;
    }
    return x;
}
/* wordlength: computes word length of the machine */
int wordlength(void){
    int i;
    unsigned v = (unsigned) ~0;
    for(i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}

