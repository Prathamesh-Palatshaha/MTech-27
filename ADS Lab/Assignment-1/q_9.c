#include <stdio.h>
int main() {
    int num, reversed = 0, remainder, original;

    printf("Enter a PIN number: ");
    scanf("%d", &num);

    original = num;

    while(num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    if(original == reversed)
        printf("PIN is a palindrome.\n");
    else
        printf("PIN is not a palindrome.\n");

    return 0;
}
