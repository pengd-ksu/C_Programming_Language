# include <stdio.h>
int binsearch(int x, int v[], int n);
main(){
    int x = 3;
    int v[] = {0,1,2,3,4,5};
    int n = 6;
    printf("The location is %d\n", binsearch(x, v, n));
}
/* binsearch: find x in v[0] <= v[1] <= ... <=v[n-1] */
int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n -1;
    mid = (low + high) / 2;
    while(low <= high && x != v[mid]){
        if(x < v[mid])
            high = mid -1;
        else
            low = mid + 1;
        mid = (high + low) / 2;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;                          /* no match */
}
