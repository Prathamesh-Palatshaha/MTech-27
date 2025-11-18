#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Outer loop: Move the boundary of the unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Assume the first element of the unsorted part is the minimum
        min_idx = i;

        // Inner loop: Find the minimum element in the remaining unsorted array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element (at index i)
        // Only swap if the minimum element is not already at the correct position
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
        
        // Print the array after the i-th element has been placed in its final sorted position
        printf("Iteration %d: ", i + 1);
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("--- Selection Sort Demonstration ---\n");
    printf("Original array: ");
    printArray(arr, n);
    printf("------------------------------------\n");
    
    selectionSort(arr, n);

    printf("------------------------------------\n");
    printf("Final sorted array: ");
    printArray(arr, n);

    return EXIT_SUCCESS;
}