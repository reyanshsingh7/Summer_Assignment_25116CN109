#include <stdio.h>
#include <string.h>

#define MAX 50

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Item items[MAX];
int count = 0;

void addItem() {
    struct Item it;
    printf("Enter Item ID: ");
    scanf("%d", &it.id);
    printf("Enter Item Name: ");
    scanf("%s", it.name);
    printf("Enter Quantity: ");
    scanf("%d", &it.quantity);
    printf("Enter Price per Unit: ");
    scanf("%f", &it.price);

    items[count] = it;
    count++;
    printf("Item added!\n");
}

void displayAll() {
    if (count == 0) {
        printf("No items found.\n");
        return;
    }
    printf("\nID\tName\t\tQty\tPrice\t\tTotal Value\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t%.2f\t\t%.2f\n",
               items[i].id, items[i].name, items[i].quantity,
               items[i].price, items[i].quantity * items[i].price);
    }
}

void searchItem() {
    int id;
    printf("Enter Item ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("Found: ID=%d, Name=%s, Quantity=%d, Price=%.2f\n",
                   items[i].id, items[i].name, items[i].quantity, items[i].price);
            return;
        }
    }
    printf("Item not found.\n");
}

void updateStock() {
    int id, qty;
    printf("Enter Item ID to update stock: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("1. Add Stock\n2. Remove Stock\nEnter choice: ");
            int op;
            scanf("%d", &op);
            printf("Enter quantity: ");
            scanf("%d", &qty);

            if (op == 1) {
                items[i].quantity += qty;
                printf("Stock added! New quantity: %d\n", items[i].quantity);
            } else if (op == 2) {
                if (qty > items[i].quantity) {
                    printf("Not enough stock available.\n");
                } else {
                    items[i].quantity -= qty;
                    printf("Stock removed! New quantity: %d\n", items[i].quantity);
                }
            } else {
                printf("Invalid option.\n");
            }
            return;
        }
    }
    printf("Item not found.\n");
}

void deleteItem() {
    int id;
    printf("Enter Item ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                items[j] = items[j + 1];
            }
            count--;
            printf("Item deleted.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void lowStockReport() {
    int threshold;
    printf("Enter low stock threshold: ");
    scanf("%d", &threshold);

    printf("\n--- Items Below Threshold (%d) ---\n", threshold);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (items[i].quantity < threshold) {
            printf("ID=%d, Name=%s, Quantity=%d\n", items[i].id, items[i].name, items[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("No items below threshold.\n");
    }
}

void totalInventoryValue() {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += items[i].quantity * items[i].price;
    }
    printf("Total Inventory Value: %.2f\n", total);
}

int main() {
    int choice;

    do {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item\n");
        printf("4. Update Stock\n");
        printf("5. Delete Item\n");
        printf("6. Low Stock Report\n");
        printf("7. Total Inventory Value\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayAll(); break;
            case 3: searchItem(); break;
            case 4: updateStock(); break;
            case 5: deleteItem(); break;
            case 6: lowStockReport(); break;
            case 7: totalInventoryValue(); break;
            case 8: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 8);

    return 0;
}