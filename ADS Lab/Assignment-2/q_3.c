#include<stdio.h>
#include<string.h>

void reverseInPlace(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Swap characters
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}


void reverseToNew(const char *original, char *reversed) {
    int len = strlen(original);
    for (int i = 0; i < len; i++) {
        reversed[i] = original[len - 1 - i];
    }
    reversed[len] = '\0';  // Null-terminate the new string
}

int main(){
    char username[100];
    char reversed[100];
    printf("Enter username: ");
    scanf("%s", username);

    reverseToNew(username, reversed);
    printf("Reversed (new array): %s\n", reversed);
    reverseInPlace(username);
    printf("Reversed (in-place): %s\n", username);
}