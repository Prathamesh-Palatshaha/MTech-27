#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Element found
        }
    }
    return -1;  // Element not found
}

int linearSearchWithSentinel(int arr[], int size, int target) {
    int last = arr[size - 1];
    arr[size - 1] = target;  // Place target as sentinel

    int i = 0;
    while (arr[i] != target) {
        i++;
    }

    arr[size - 1] = last;  // Restore the original last element
    if (i < size - 1 || arr[size - 1] == target) {
        return i;  // Element found
    }
    return -1;  // Element not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int target = 7;
    int index = linearSearch(arr, 5, target);
    if (index != -1) {
        printf("Found %d at index %d\n", target, index);
    } else {
        printf("Element not found\n");
    }

    int index = linearSearchWithSentinel(arr, 5, target);
    if (index != -1) {
        printf("Found %d at index %d\n", target, index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
