#include<stdio.h>
#include<string.h>
#define MAX_NAME_LEN 50
#define MAX_DEP_LEN 10
typedef struct 
{
    int fields_id;
    char name[MAX_NAME_LEN];
    float salary;
    char department [MAX_DEP_LEN];
}office;

int main()
{
    int n;
    printf("Number of entries: ");
    scanf("%d", &n);
    office employee[n];
    for (int i=0; i < n;i++){
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Name: ");
        fgets(employee[i].name,MAX_NAME_LEN,stdin);
        employee[i].name[strcspn(employee[i].name,"\n")] ='\0';

        printf("Department: ");
        fgets(employee[i].department, MAX_DEP_LEN, stdin);
        employee[i].department[strcspn(employee[i].department, "\n")] = '\0';

        printf("Enter field_id:\n");
        scanf("%d",&employee[i].fields_id);

        printf("Enter Salary:\n");
        scanf("%d",&employee[i].salary);
    }

    return 0;
}