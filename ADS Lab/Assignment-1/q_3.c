#include <stdio.h>

int main() {
    int token;
    printf("Enter customer's token number: ");
    scanf("%d", &token);

    if(token % 2 == 0)
        printf("Token number %d is Even.\n", token);
    else
        printf("Token number %d is Odd.\n", token);

    return 0;
}
