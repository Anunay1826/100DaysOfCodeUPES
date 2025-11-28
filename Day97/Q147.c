//Q147: Store employee data in a binary file using fwrite() and read using fread().

#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int  id;
    char name[30];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee emp;
    int n, i;

    /* ====== WRITE TO BINARY FILE USING fwrite() ====== */
    fp = fopen("employee.dat", "wb");    // open file in write-binary mode
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &emp.id);

        printf("Name: ");
        // clear input buffer before using scanf for string (optional safety)
        scanf(" %[^\n]", emp.name);

        printf("Salary: ");
        scanf("%f", &emp.salary);

        // write one struct Employee to file
        fwrite(&emp, sizeof(struct Employee), 1, fp);
    }

    fclose(fp);
    printf("\nData written to employee.dat successfully.\n");

    /* ====== READ FROM BINARY FILE USING fread() ====== */
    fp = fopen("employee.dat", "rb");    // open file in read-binary mode
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("\nReading data from file:\n");

    // read until fread returns 0 (no more records)
    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        printf("\nEmployee ID   : %d\n", emp.id);
        printf("Employee Name : %s\n", emp.name);
        printf("Salary        : %.2f\n", emp.salary);
    }

    fclose(fp);
    return 0;
}
