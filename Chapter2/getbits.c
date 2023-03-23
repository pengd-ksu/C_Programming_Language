# include <stdio.h>
unsigned getbits(unsigned x, int p, int n);
int main() {
    unsigned x = 27;                            /* binary: 11011 */
    printf("%u\n", getbits(x, 3, 3));           /* should be 101 */
    return 0;
}
unsigned getbits(unsigned x, int p, int n){
    return (x >> (p+1-n) & ~(~0 << n));
}
