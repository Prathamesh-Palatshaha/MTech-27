#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int marks;
} Student;

int main() {
    int n, new_n;

    printf("Enter initial number of students: ");
    scanf("%d", &n);

    Student *students = (Student*)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input initial students
    for(int i = 0; i < n; i++) {
        printf("Enter name and marks for student %d: ", i+1);
        scanf(" %[^\n]%d", students[i].name, &students[i].marks);
    }

    printf("Enter new total number of students: ");
    scanf("%d", &new_n);

    students = (Student*)realloc(students, new_n * sizeof(Student));
    if (students == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // Input new student details
    for(int i = n; i < new_n; i++) {
        printf("Enter name and marks for new student %d: ", i+1);
        scanf(" %[^\n]%d", students[i].name, &students[i].marks);
    }

    printf("\nAll students:\n");
    for(int i = 0; i < new_n; i++) {
        printf("Name: %s, Marks: %d\n", students[i].name, students[i].marks);
    }

    free(students);

    return 0;
}
