#include <stdio.h>

void checkEvenOrOdd(int num) {
    if (num % 2 == 0) {
        printf("%d is even\n", num);
    } else {
        printf("%d is odd\n", num);
    }
}

void bitwise(int num) {
    if (num & 1) {
        printf("%d is odd\n", num);
    } else {
        printf("%d is even\n", num);
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        checkEvenOrOdd(nums[i]);
        bitwise(nums[i]);
    }
    return 0;
}
