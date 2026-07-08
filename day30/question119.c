#include <stdio.h>
#include <string.h>

#define MAX 20

char names[MAX][50];
float salaries[MAX];
int count = 0;

void addEmployee() {
    printf("Enter Employee Name: ");
    scanf("%s", names[count]);
    printf("Enter Salary: ");
    scanf("%f", &salaries[count]);
    count++;
    printf("Employee added!\n");
}

void displayEmployees() {
    if (count == 0) {
        printf("No employees found.\n");
        return;
    }
    printf("\nS.No\tName\t\tSalary\n");
    printf("----------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\n", i + 1, names[i], salaries[i]);
    }
}

void searchEmployee() {
    char name[50];
    printf("Enter Employee Name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("Found: Name=%s, Salary=%.2f\n", names[i], salaries[i]);
            return;
        }
    }
    printf("Employee not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Mini Employee Management System ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}