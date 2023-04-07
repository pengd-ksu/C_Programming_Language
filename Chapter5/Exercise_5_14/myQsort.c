#include "sortHeader.h"

// myQsort: sort v[left]...v[right] into increasing order
void myQsort(void *v[], int left, int right,
            int (*comp)(void *, void *)) {
    int i, last;
    
    if (left >= right) {
        // do nothing if array contains fewer than two elements
        return;
    }
    swap(v, left, left + (right - left) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    myQsort(v, left, last - 1, comp);
    myQsort(v, last + 1, right, comp);
}