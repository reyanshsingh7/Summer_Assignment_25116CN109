#include <stdio.h>
#include <string.h>

#define MAX 50

struct Employee {
    int id;
    char name[50];
    float basicSalary;
    float allowances;
    float deductions;
    float netSalary;
};

struct Employee employees[MAX];
int count = 0;

void calculateNetSalary(struct Employee *e) {
    e->netSalary = e->basicSalary + e->allowances - e->deductions;
}

void addEmployee() {
    struct Employee e;
    printf("Enter ID: ");
    scanf("%d", &e.id);
    printf("Enter Name: ");
    scanf("%s", e.name);
    printf("Enter Basic Salary: ");
    scanf("%f", &e.basicSalary);
    printf("Enter Allowances: ");
    scanf("%f", &e.allowances);
    printf("Enter Deductions: ");
    scanf("%f", &e.deductions);

    calculateNetSalary(&e);

    employees[count] = e;
    count++;
    printf("Employee salary record added! Net Salary = %.2f\n", e.netSalary);
}

void displayAll() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }
    printf("\nID\tName\t\tBasic\t\tAllow.\t\tDeduct.\t\tNet Salary\n");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
               employees[i].id, employees[i].name,
               employees[i].basicSalary, employees[i].allowances,
               employees[i].deductions, employees[i].netSalary);
    }
}

void searchEmployee() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Found: ID=%d, Name=%s\n", employees[i].id, employees[i].name);
            printf("Basic Salary: %.2f\n", employees[i].basicSalary);
            printf("Allowances : %.2f\n", employees[i].allowances);
            printf("Deductions : %.2f\n", employees[i].deductions);
            printf("Net Salary : %.2f\n", employees[i].netSalary);
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
            printf("Enter new Basic Salary: ");
            scanf("%f", &employees[i].basicSalary);
            printf("Enter new Allowances: ");
            scanf("%f", &employees[i].allowances);
            printf("Enter new Deductions: ");
            scanf("%f", &employees[i].deductions);

            calculateNetSalary(&employees[i]);
            printf("Salary updated! Net Salary = %.2f\n", employees[i].netSalary);
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
            printf("Record deleted.\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

void totalPayroll() {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += employees[i].netSalary;
    }
    printf("Total Payroll (Net Salaries): %.2f\n", total);
}

int main() {
    int choice;

    do {
        printf("\n--- Salary Management System ---\n");
        printf("1. Add Employee Salary Record\n");
        printf("2. Display All\n");
        printf("3. Search Employee\n");
        printf("4. Update Salary\n");
        printf("5. Delete Employee\n");
        printf("6. Show Total Payroll\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAll(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: totalPayroll(); break;
            case 7: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}