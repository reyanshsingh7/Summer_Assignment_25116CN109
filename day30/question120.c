#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MENU_SIZE 8
#define MAX_ORDER 20

/* ---------- Menu data (arrays of strings and prices) ---------- */
char menuItems[MENU_SIZE][30] = {
    "Burger", "Pizza", "Pasta", "Fries",
    "Sandwich", "Coke", "Ice Cream", "Salad"
};
float menuPrices[MENU_SIZE] = {
    120.00, 250.00, 180.00, 80.00,
    100.00, 40.00, 90.00, 70.00
};

/* ---------- Order storage (parallel arrays) ---------- */
char orderItems[MAX_ORDER][30];
int orderQty[MAX_ORDER];
float orderSubtotal[MAX_ORDER];
int orderCount = 0;

/* ---------- Function prototypes ---------- */
void displayMenu(void);
int findMenuIndex(char *itemName);
void toLowerStr(char *str);
void takeOrder(void);
void viewOrder(void);
float calculateTotal(void);
void generateBill(void);
void printMenu(void);

/* ---------- Helper: convert string to lowercase for matching ---------- */
void toLowerStr(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

/* ---------- Show the restaurant menu ---------- */
void displayMenu(void) {
    printf("\n===== RESTAURANT MENU =====\n");
    printf("No.\tItem\t\tPrice\n");
    printf("----------------------------------\n");
    for (int i = 0; i < MENU_SIZE; i++) {
        printf("%d\t%s\t\t%.2f\n", i + 1, menuItems[i], menuPrices[i]);
    }
    printf("===================================\n");
}

/* ---------- Find a menu item by name (case-insensitive) ---------- */
int findMenuIndex(char *itemName) {
    char search[30], compare[30];
    strcpy(search, itemName);
    toLowerStr(search);

    for (int i = 0; i < MENU_SIZE; i++) {
        strcpy(compare, menuItems[i]);
        toLowerStr(compare);
        if (strcmp(search, compare) == 0) {
            return i;
        }
    }
    return -1;
}

/* ---------- Take a new order from the customer ---------- */
void takeOrder(void) {
    if (orderCount >= MAX_ORDER) {
        printf("Order list is full. Please generate the bill.\n");
        return;
    }

    char itemName[30];
    int qty;

    displayMenu();
    printf("Enter item name to order: ");
    scanf("%s", itemName);

    int index = findMenuIndex(itemName);
    if (index == -1) {
        printf("Item not found on the menu.\n");
        return;
    }

    printf("Enter quantity: ");
    scanf("%d", &qty);

    if (qty <= 0) {
        printf("Quantity must be greater than zero.\n");
        return;
    }

    strcpy(orderItems[orderCount], menuItems[index]);
    orderQty[orderCount] = qty;
    orderSubtotal[orderCount] = menuPrices[index] * qty;
    orderCount++;

    printf("%d x %s added to order!\n", qty, menuItems[index]);
}

/* ---------- Show the current order ---------- */
void viewOrder(void) {
    if (orderCount == 0) {
        printf("No items ordered yet.\n");
        return;
    }

    printf("\n===== CURRENT ORDER =====\n");
    printf("Item\t\tQty\tSubtotal\n");
    printf("----------------------------------\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%s\t\t%d\t%.2f\n", orderItems[i], orderQty[i], orderSubtotal[i]);
    }
    printf("==========================\n");
}

/* ---------- Calculate the grand total of the order ---------- */
float calculateTotal(void) {
    float total = 0;
    for (int i = 0; i < orderCount; i++) {
        total += orderSubtotal[i];
    }
    return total;
}

/* ---------- Generate and print the final bill ---------- */
void generateBill(void) {
    if (orderCount == 0) {
        printf("No items ordered yet.\n");
        return;
    }

    float total = calculateTotal();
    float tax = total * 0.05f;      /* 5% tax */
    float grandTotal = total + tax;

    printf("\n========== FINAL BILL ==========\n");
    printf("Item\t\tQty\tSubtotal\n");
    printf("---------------------------------\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%s\t\t%d\t%.2f\n", orderItems[i], orderQty[i], orderSubtotal[i]);
    }
    printf("---------------------------------\n");
    printf("Subtotal        : %.2f\n", total);
    printf("Tax (5%%)        : %.2f\n", tax);
    printf("Grand Total     : %.2f\n", grandTotal);
    printf("=================================\n");
    printf("Thank you for dining with us!\n");

    /* reset order after billing */
    orderCount = 0;
}

/* ---------- Menu display for main loop ---------- */
void printMenu(void) {
    printf("\n================================================\n");
    printf("   MINI PROJECT: RESTAURANT ORDERING SYSTEM\n");
    printf("================================================\n");
    printf("1. View Menu\n");
    printf("2. Place Order\n");
    printf("3. View Current Order\n");
    printf("4. Generate Bill\n");
    printf("5. Exit\n");
    printf("================================================\n");
    printf("Enter choice: ");
}

int main(void) {
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayMenu(); break;
            case 2: takeOrder(); break;
            case 3: viewOrder(); break;
            case 4: generateBill(); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}