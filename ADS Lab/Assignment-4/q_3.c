#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    char name[50];
    Date dob;  // Nested structure
} Student;

int main() {
    Student s;

    printf("Enter student id: ");
    scanf("%d", &s.id);
    printf("Enter student name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d", &s.dob.day, &s.dob.month, &s.dob.year);

    printf("\nStudent Details:\n");
    printf("ID: %d\nName: %s\nDate of Birth: %02d/%02d/%d\n", s.id, s.name, s.dob.day, s.dob.month, s.dob.year);

    return 0;
}
