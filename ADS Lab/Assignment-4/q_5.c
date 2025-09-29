#include <stdio.h>

typedef struct {
    char name[50];
    int marks;
} Student;

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student students[n];
    for(int i = 0; i < n; i++) {
        printf("Enter name and marks for student %d: ", i+1);
        scanf(" %[^\n]%d", students[i].name, &students[i].marks);
    }

    int highestIndex = 0;
    for(int i = 1; i < n; i++) {
        if(students[i].marks > students[highestIndex].marks) {
            highestIndex = i;
        }
    }

    printf("Highest marks scored by %s: %d\n", students[highestIndex].name, students[highestIndex].marks);

    return 0;
}
