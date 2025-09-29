#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    Employee employees[n];

    // Input employee details
    for(int i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i+1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf(" %[^\n]", employees[i].name);  // to read string with spaces
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    // Display employee details
    printf("\nEmployee Details:\n");
    for(int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }

    return 0;
}
