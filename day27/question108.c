#include <stdio.h>
#include <string.h>

#define MAX 50
#define SUBJECTS 5

struct Student {
    int id;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float percentage;
    char grade;
};

struct Student students[MAX];
int count = 0;

char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 75) return 'B';
    else if (percentage >= 60) return 'C';
    else if (percentage >= 40) return 'D';
    else return 'F';
}

void addStudent() {
    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);

    s.total = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        printf("Enter marks for Subject %d (out of 100): ", i + 1);
        scanf("%f", &s.marks[i]);
        s.total += s.marks[i];
    }

    s.percentage = s.total / SUBJECTS;
    s.grade = calculateGrade(s.percentage);

    students[count] = s;
    count++;
    printf("Marksheet record added!\n");
}

void printMarksheet(struct Student *s) {
    printf("\n==========================================\n");
    printf("               MARKSHEET\n");
    printf("==========================================\n");
    printf("ID     : %d\n", s->id);
    printf("Name   : %s\n", s->name);
    printf("------------------------------------------\n");
    for (int i = 0; i < SUBJECTS; i++) {
        printf("Subject %d      : %.2f\n", i + 1, s->marks[i]);
    }
    printf("------------------------------------------\n");
    printf("Total          : %.2f / %d\n", s->total, SUBJECTS * 100);
    printf("Percentage     : %.2f%%\n", s->percentage);
    printf("Grade          : %c\n", s->grade);
    printf("==========================================\n");
}

void displayAll() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printMarksheet(&students[i]);
    }
}

void searchStudent() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printMarksheet(&students[i]);
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
            printf("Record deleted.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Marksheet Generation System ---\n");
        printf("1. Add Student Marks\n");
        printf("2. Display All Marksheets\n");
        printf("3. Search Marksheet by ID\n");
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