#include <stdio.h>
#include <string.h>

#define MAX 20

char titles[MAX][50];
int available[MAX];
int count = 0;

void addBook() {
    printf("Enter Book Title: ");
    scanf("%s", titles[count]);
    available[count] = 1;
    count++;
    printf("Book added!\n");
}

void displayBooks() {
    if (count == 0) {
        printf("No books found.\n");
        return;
    }
    printf("\nS.No\tTitle\t\tStatus\n");
    printf("----------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\n", i + 1, titles[i], available[i] ? "Available" : "Issued");
    }
}

void issueBook() {
    char title[50];
    printf("Enter Book Title to issue: ");
    scanf("%s", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(titles[i], title) == 0) {
            if (available[i]) {
                available[i] = 0;
                printf("Book issued!\n");
            } else {
                printf("Book already issued.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

void returnBook() {
    char title[50];
    printf("Enter Book Title to return: ");
    scanf("%s", title);

    for (int i = 0; i < count; i++) {
        if (strcmp(titles[i], title) == 0) {
            if (!available[i]) {
                available[i] = 1;
                printf("Book returned!\n");
            } else {
                printf("Book was not issued.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Mini Library System ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}