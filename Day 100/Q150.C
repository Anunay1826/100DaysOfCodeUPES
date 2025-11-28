//Use pointer to struct to modify and display data using -> operator.
#include <stdio.h>

struct Student {
    int roll;
    char name[30];
    float marks;
};

int main() {
    struct Student s;        // normal structure variable
    struct Student *ptr;     // pointer to structure

    ptr = &s;                // pointer pointing to structure variable

    // Modify data using -> operator
    printf("Enter Student Details:\n");

    printf("Roll Number: ");
    scanf("%d", &ptr->roll);

    printf("Name: ");
    scanf(" %[^\n]", ptr->name);

    printf("Marks: ");
    scanf("%f", &ptr->marks);

    // Display data using -> operator
    printf("\n=== Student Details ===\n");
    printf("Roll  : %d\n", ptr->roll);
    printf("Name  : %s\n", ptr->name);
    printf("Marks : %.2f\n", ptr->marks);

    return 0;
}
