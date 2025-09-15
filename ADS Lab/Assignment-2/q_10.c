#include <stdio.h>
#include <string.h>

int isPalindrome(int num) {
    char str[20];
    sprintf(str, "%d", num);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int reverse(int num) {
    int original = num;
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

int main() {
    int num = 121;
    if (isPalindrome(num)) {
        printf("%d is a palindrome number\n", num);
    } else {
        printf("%d is not a palindrome number\n", num);
    }

     if (reverse(num)) {
        printf("%d is a palindrome number\n", num);
    } else {
        printf("%d is not a palindrome number\n", num);
    }
    return 0;
}
