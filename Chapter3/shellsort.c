# include <stdio.h>
void shellsort(int v[], int n);
int main() {
    int v1[10] = {2, 8, 10, 4, 7, 9, 1, 3, 7};
    int i = 0, n = 9;
    shellsort(v1, n);
    while(v1[i] != '\0'){
        printf("%d ", v1[i]);
        ++i;
    }
    printf("\n");
    return 0;
}
void shellsort(int v[], int n){
    int gap, i, j, temp;
    for(gap = n/2; gap > 0; gap /= 2){
        for(i = gap; i < n; i++){
            for(j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}
