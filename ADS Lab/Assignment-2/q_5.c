#include <stdio.h>

int factorialIterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
int factorialRecursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

int main() {
    int num = 5;
    printf("Factorial of %d is %d\n", num, factorialIterative(num));
    printf("Factorial of %d is %d\n", num, factorialRecursive(num));
    return 0;
}
