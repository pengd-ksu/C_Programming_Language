# include <stdio.h>
unsigned setbits(unsigned x, int p, int n, unsigned y);
main(){
    unsigned x = 27;                            /* binary: 11011 */
    unsigned y = 21;                            /* binary: 10101 */
    printf("%u\n", setbits(x, 3, 2, y));        /* binary: 10111, decimal: 23 */
}
unsigned setbits(unsigned x, int p, int n, unsigned y){
    return (x & ~(~(~0 << n) << (p+1-n)))|(y & (~(~0 << n) << (p+1-n)));
}
