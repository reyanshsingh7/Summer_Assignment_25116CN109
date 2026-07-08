#include <stdio.h>
#include <string.h>

#define MAX 50

struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

struct Employee employees[MAX];
int count = 0;

void addEmployee() {
    struct Employee e;
    printf("Enter ID: ");
    scanf("%d", &e.id);
    printf("Enter Name: ");
    scanf("%s", e.name);
    printf("Enter Department: ");
    scanf("%s", e.department);
    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    employees[count] = e;
    count++;
    printf("Employee added!\n");
}

void displayAll() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }
    printf("\nID\tName\t\tDepartment\tSalary\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\t\t%.2f\n",
               employees[i].id, employees[i].name,
               employees[i].department, employees[i].salary);
    }
}

void searchEmployee() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Found: ID=%d, Name=%s, Department=%s, Salary=%.2f\n",
                   employees[i].id, employees[i].name,
                   employees[i].department, employees[i].salary);
            return;
        }
    }
    printf("Employee not found.\n");
}

void updateEmployee() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Enter new Name: ");
            scanf("%s", employees[i].name);
            printf("Enter new Department: ");
            scanf("%s", employees[i].department);
            printf("Enter new Salary: ");
            scanf("%f", &employees[i].salary);
            printf("Employee updated!\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

void deleteEmployee() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            count--;
            printf("Employee deleted.\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Employee Management System ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAll(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}