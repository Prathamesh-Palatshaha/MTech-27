#include <stdio.h>

int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    else
        return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0) n = -n;  // Handle negative numbers

    printf("Sum of digits: %d\n", sumOfDigits(n));

    return 0;
}
