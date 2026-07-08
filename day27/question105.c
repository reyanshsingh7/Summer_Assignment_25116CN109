#include <stdio.h>
#include <string.h>

#define MAX 50

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    students[count] = s;
    count++;
    printf("Student added!\n");
}

void displayAll() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }
    printf("\nID\tName\t\tMarks\n");
    printf("--------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Found: ID=%d, Name=%s, Marks=%.2f\n",
                   students[i].id, students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Student Record Management ---\n");
        printf("1. Add Student\n");
        printf("2. Display All\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}