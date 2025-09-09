#include <stdio.h>

int main() {
    int a, b, temp;
    printf("Enter two numbers (cashier entered in reverse): ");
    scanf("%d %d", &a, &b);

    // Swap
    temp = a;
    a = b;
    b = temp;

    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0;
}
