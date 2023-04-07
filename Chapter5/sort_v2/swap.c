#include "sortHeader.h"

// swap: interchange v[i] and v[j]
void swap(void *v[], int i, int j) {
    char *tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}