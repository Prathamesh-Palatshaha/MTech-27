#include <stdio.h>

void swapArithmetic(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swapXOR(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    int x = 5, y = 10;
    int a = 5, b = 10;
    swapArithmetic(&x, &y);
    swapXOR(&a, &b);
    printf("After swap: x = %d, y = %d\n", x, y);
    printf("After swap: x = %d, y = %d\n", a, b);
    return 0;
}
