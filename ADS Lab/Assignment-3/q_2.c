#include <stdio.h>

void findSubarrayWithSum(int arr[], int n, int S) {
    for (int start = 0; start < n; start++) {
        int current_sum = 0;
        for (int end = start; end < n; end++) {
            current_sum += arr[end];
            
            if (current_sum == S) {
                printf("Subarray found from index %d to %d\n", start, end);
                return;  // return after first such subarray is found
            }
        }
    }
    printf("No subarray with sum %d found\n", S);
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int S = 33;

    findSubarrayWithSum(arr, n, S);

    return 0;
}
