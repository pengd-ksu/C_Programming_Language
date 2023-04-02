#include <stdio.h>

#define ARRSIZE 6

void qsort(int [], int, int);
void swap(int [], int, int);

int main () {
    int init[ARRSIZE] = {-3, 5, 2, 6, -8, 9};
    int left = 0, right = ARRSIZE - 1;
    printf("Init int array: \n");
    for (int i = 0; i < ARRSIZE; i++) {
        printf("%d ", init[i]);
    }
    printf("\n");
    qsort(init, left, right);
    printf("After qsrot, init became: \n");
    for (int i = 0; i < ARRSIZE; i++) {
        printf("%d ", init[i]);
    }
    printf("\n");
}

// qsort: sort v[left]...v[right] into increasing order
void qsort(int v[], int left, int right) {
    int i, last;
    if (left >= right) {
        // do nothing if array contains fewer than two ele
        return;
    }
    // move partition elem, changed mid index to prevent overflow
    swap(v, left, left + (right - left) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    // restore partition elem
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

// swap: interchange v[i] and v[j]
void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}