#include <stdio.h>
#include <string.h>

#define MAX 50

struct Contact {
    int id;
    char name[50];
    char phone[15];
    char email[50];
};

struct Contact contacts[MAX];
int count = 0;

void addContact() {
    struct Contact c;
    printf("Enter ID: ");
    scanf("%d", &c.id);
    printf("Enter Name: ");
    scanf("%s", c.name);
    printf("Enter Phone: ");
    scanf("%s", c.phone);
    printf("Enter Email: ");
    scanf("%s", c.email);

    contacts[count] = c;
    count++;
    printf("Contact added!\n");
}

void displayAll() {
    if (count == 0) {
        printf("No contacts found.\n");
        return;
    }
    printf("\nID\tName\t\tPhone\t\tEmail\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\t%s\n",
               contacts[i].id, contacts[i].name,
               contacts[i].phone, contacts[i].email);
    }
}

void searchContact() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (contacts[i].id == id) {
            printf("Found: ID=%d, Name=%s, Phone=%s, Email=%s\n",
                   contacts[i].id, contacts[i].name,
                   contacts[i].phone, contacts[i].email);
            return;
        }
    }
    printf("Contact not found.\n");
}

void updateContact() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (contacts[i].id == id) {
            printf("Enter new Name: ");
            scanf("%s", contacts[i].name);
            printf("Enter new Phone: ");
            scanf("%s", contacts[i].phone);
            printf("Enter new Email: ");
            scanf("%s", contacts[i].email);
            printf("Contact updated!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (contacts[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            printf("Contact deleted.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. Display All\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayAll(); break;
            case 3: searchContact(); break;
            case 4: updateContact(); break;
            case 5: deleteContact(); break;
            case 6: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}