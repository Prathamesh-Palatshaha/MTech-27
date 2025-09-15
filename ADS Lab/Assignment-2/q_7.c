#include <stdio.h>

void printNaturalNumbersRecursive(int n) {
    if (n > 0) {
        printNaturalNumbersRecursive(n - 1);
        printf("%d ", n);
    }
}

void printNaturalNumbers(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n = 10;
    printNaturalNumbers(n);
    printf("\n");
    printNaturalNumbersRecursive(n);
    return 0;
}
