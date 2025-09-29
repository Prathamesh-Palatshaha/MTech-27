#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float salary;
} Employee;

void printEmployees(Employee *arr, int n, const char *msg) {
    printf("%s\n", msg);
    for(int i = 0; i < n; i++) {
        printf("Employee %d -> ID: %d, Salary: %.2f\n", i+1, arr[i].id, arr[i].salary);
    }
    printf("\n");
}

int main() {
    int n = 3;

    // Using malloc
    Employee *arr_malloc = (Employee *)malloc(n * sizeof(Employee));
    if(arr_malloc == NULL) {
        printf("Memory allocation failed using malloc\n");
        return 1;
    }

    // Using calloc
    Employee *arr_calloc = (Employee *)calloc(n, sizeof(Employee));
    if(arr_calloc == NULL) {
        printf("Memory allocation failed using calloc\n");
        free(arr_malloc);
        return 1;
    }

    // Print contents right after allocation (before initialization)
    printEmployees(arr_malloc, n, "Contents of malloc allocated array (uninitialized):");
    printEmployees(arr_calloc, n, "Contents of calloc allocated array (zero-initialized):");

    // Manually initialize malloc array
    for(int i = 0; i < n; i++) {
        arr_malloc[i].id = i + 1;
        arr_malloc[i].salary = 1000.0f + i * 500;
    }

    // Manually initialize calloc array
    for(int i = 0; i < n; i++) {
        arr_calloc[i].id = i + 1;
        arr_calloc[i].salary = 2000.0f + i * 700;
    }

    // Print contents after initialization
    printEmployees(arr_malloc, n, "Contents of malloc allocated array (after initialization):");
    printEmployees(arr_calloc, n, "Contents of calloc allocated array (after initialization):");

    // Free memory
    free(arr_malloc);
    free(arr_calloc);

    return 0;
}
