#include <stdio.h>
#include <string.h>

#define MAX 50

struct Account {
    int accNo;
    char name[50];
    float balance;
};

struct Account accounts[MAX];
int count = 0;

void createAccount() {
    struct Account a;
    printf("Enter Account Number: ");
    scanf("%d", &a.accNo);
    printf("Enter Name: ");
    scanf("%s", a.name);
    printf("Enter Initial Deposit: ");
    scanf("%f", &a.balance);

    accounts[count] = a;
    count++;
    printf("Account created successfully!\n");
}

void displayAll() {
    if (count == 0) {
        printf("No accounts found.\n");
        return;
    }
    printf("\nAcc No\tName\t\tBalance\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\n", accounts[i].accNo, accounts[i].name, accounts[i].balance);
    }
}

void checkBalance() {
    int accNo;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accNo == accNo) {
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void depositMoney() {
    int accNo;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accNo == accNo) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful! New Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdrawMoney() {
    int accNo;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accNo == accNo) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New Balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void deleteAccount() {
    int accNo;
    printf("Enter Account Number to delete: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) {
        if (accounts[i].accNo == accNo) {
            for (int j = i; j < count - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            count--;
            printf("Account deleted.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Bank Account Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Check Balance\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Delete Account\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAll(); break;
            case 3: checkBalance(); break;
            case 4: depositMoney(); break;
            case 5: withdrawMoney(); break;
            case 6: deleteAccount(); break;
            case 7: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}