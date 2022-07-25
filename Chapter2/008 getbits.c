# include <stdio.h>
unsigned getbits(unsigned x, int p, int n);
main(){
    unsigned x = 27;                            /* binary: 11011 */
    printf("%u\n", getbits(x, 3, 3));           /* should be 101 */
}
unsigned getbits(unsigned x, int p, int n){
    return (x >> (p+1-n) & ~(~0 << n));
}
