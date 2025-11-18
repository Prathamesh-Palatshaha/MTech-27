#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void partialSelectionSort(int arr[], int n, int k) {
    int i, j, min_idx;

    if (k < 0 || k > n) {
        printf("Error: k must be between 0 and array size (%d).\n", n);
        return;
    }

    for (i = 0; i < k; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
        
        printf("After placing the %d%s smallest element (at index %d): ", i + 1, (i==0)?"st":(i==1)?"nd":(i==2)?"rd":"th", i);
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {80, 10, 50, 20, 90, 40, 30, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4; 

    printf("--- Partial Selection Sort Demonstration ---\n");
    printf("Original array: ");
    printArray(arr, n);
    printf("We aim to sort the first k=%d smallest elements.\n", k);
    printf("--------------------------------------------\n");
    
    partialSelectionSort(arr, n, k);

    printf("--------------------------------------------\n");
    printf("Final array state (First %d elements are sorted): ", k);
    printArray(arr, n);

    return EXIT_SUCCESS;
}