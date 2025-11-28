//Use malloc() to allocate structure memory dynamically and print details.
#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    // Dynamically allocate memory for 1 structure
    struct Employee *emp;

    emp = (struct Employee *) malloc(sizeof(struct Employee));

    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter Employee Details:\n");

    printf("ID: ");
    scanf("%d", &emp->id);

    printf("Name: ");
    scanf(" %[^\n]", emp->name);

    printf("Salary: ");
    scanf("%f", &emp->salary);

    printf("\n=== Employee Details ===\n");
    printf("ID      : %d\n", emp->id);
    printf("Name    : %s\n", emp->name);
    printf("Salary  : %.2f\n", emp->salary);

    free(emp);  // free allocated memory
    return 0;
}
