#include <stdio.h>
#include <string.h>

#define MAX 50

struct Book {
    int id;
    char title[50];
    char author[50];
    int isIssued; // 0 = available, 1 = issued
};

struct Book books[MAX];
int count = 0;

void addBook() {
    struct Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Title: ");
    scanf("%s", b.title);
    printf("Enter Author: ");
    scanf("%s", b.author);
    b.isIssued = 0;

    books[count] = b;
    count++;
    printf("Book added!\n");
}

void displayAll() {
    if (count == 0) {
        printf("No books found.\n");
        return;
    }
    printf("\nID\tTitle\t\tAuthor\t\tStatus\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n",
               books[i].id, books[i].title, books[i].author,
               books[i].isIssued ? "Issued" : "Available");
    }
}

void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("Found: ID=%d, Title=%s, Author=%s, Status=%s\n",
                   books[i].id, books[i].title, books[i].author,
                   books[i].isIssued ? "Issued" : "Available");
            return;
        }
    }
    printf("Book not found.\n");
}

void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].isIssued) {
                printf("Book is already issued.\n");
            } else {
                books[i].isIssued = 1;
                printf("Book issued successfully!\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (!books[i].isIssued) {
                printf("Book was not issued.\n");
            } else {
                books[i].isIssued = 0;
                printf("Book returned successfully!\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                books[j] = books[j + 1];
            }
            count--;
            printf("Book deleted.\n");
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayAll(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: deleteBook(); break;
            case 7: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}