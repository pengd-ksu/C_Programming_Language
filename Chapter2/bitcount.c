# include <stdio.h>
int bitcount(unsigned x);
int main() {
    // bianry 1111001
    unsigned x = 121;
    printf("The 1 bits in %u is %d\n", x, (bitcount(x)));
}
/* bitcount: count 1 bits in x */
int bitcount(unsigned x){
    int b;
    for(b = 0; x != 0; x >>= 1){
        if(x & 01) {
            b++;
        }
    }
    return b;
}
