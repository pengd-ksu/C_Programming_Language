# include <stdio.h>
int binsearch(int x, int v[], int n);
int main() {
    int n = 599999;
    int target = n - 1;
    int v[n];
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
    binsearch(target, v, n) < 0 ?
        printf("%d not in the array\n", target) :
        printf("The index of %d is %d\n", target, binsearch(target, v, n));
    return 0;
}
/* binsearch: find x in v[0] <= v[1] <= ... <=v[n-1] */
int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n -1;
    while(low <= high) {
        // Changed it to minus, in case low and high are 
        // both large numbers that could cause overflow.
        mid = low + (high - low)/2;
        if(x < v[mid])
            high = mid -1;
        else if (x > v[mid])
            low = mid + 1;
        else                            /* found match */
            return mid;
    }
    return -1;                          /* no match */
}
