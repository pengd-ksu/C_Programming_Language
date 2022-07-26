#include <stdio.h>

void swap(int *px, int *py);

int main() {
    int x = 3;
    int y = 5;
    printf("Before swaping, x is %d, y is %d\n", x, y);
    swap(&x, &y);
    printf("After swaping, x is %d, y is %d\n", x, y);
}

void swap(int *px, int *py) {
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}