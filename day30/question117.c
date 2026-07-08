#include <stdio.h>
#include <string.h>

#define MAX 50

int rollNumbers[MAX];
char names[MAX][50];
float marks[MAX];
int count = 0;

void addStudent() {
    printf("Enter Roll Number: ");
    scanf("%d", &rollNumbers[count]);
    printf("Enter Name: ");
    scanf("%s", names[count]);
    printf("Enter Marks: ");
    scanf("%f", &marks[count]);

    count++;
    printf("Student added!\n");
}

void displayAll() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }
    printf("\nRoll No\tName\t\tMarks\n");
    printf("--------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\n", rollNumbers[i], names[i], marks[i]);
    }
}

void searchStudent() {
    int roll;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (rollNumbers[i] == roll) {
            printf("Found: Roll=%d, Name=%s, Marks=%.2f\n", rollNumbers[i], names[i], marks[i]);
            return;
        }
    }
    printf("Student not found.\n");
}

void updateStudent() {
    int roll;
    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (rollNumbers[i] == roll) {
            printf("Enter new Name: ");
            scanf("%s", names[i]);
            printf("Enter new Marks: ");
            scanf("%f", &marks[i]);
            printf("Student updated!\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent() {
    int roll;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (rollNumbers[i] == roll) {
            for (int j = i; j < count - 1; j++) {
                rollNumbers[j] = rollNumbers[j + 1];
                strcpy(names[j], names[j + 1]);
                marks[j] = marks[j + 1];
            }
            count--;
            printf("Student deleted.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void sortByMarks() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (marks[j] < marks[j + 1]) {
                float tempMark = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = tempMark;

                int tempRoll = rollNumbers[j];
                rollNumbers[j] = rollNumbers[j + 1];
                rollNumbers[j + 1] = tempRoll;

                char tempName[50];
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempName);
            }
        }
    }
    printf("Sorted by marks (descending)!\n");
    displayAll();
}

int main() {
    int choice;

    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Sort by Marks\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: sortByMarks(); break;
            case 7: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}