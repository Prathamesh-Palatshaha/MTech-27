#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int marks;
} Student;

int compareStudents(Student s1, Student s2) {
    if(strcmp(s1.name, s2.name) == 0 && s1.marks == s2.marks)
        return 1;  // equal
    else
        return 0;  // not equal
}

int main() {
    Student s1 = {"Alice", 90};
    Student s2 = {"Alice", 90};
    Student s3 = {"Bob", 85};

    printf("s1 and s2 are %s\n", compareStudents(s1, s2) ? "equal" : "not equal");
    printf("s1 and s3 are %s\n", compareStudents(s1, s3) ? "equal" : "not equal");

    return 0;
}
