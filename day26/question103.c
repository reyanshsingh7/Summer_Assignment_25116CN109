#include <stdio.h>
#include <stdlib.h>

#define CORRECT_PIN_INIT 1234
#define MAX_PIN_ATTEMPTS 3

double balance = 5000.00;   // starting balance
int pin = CORRECT_PIN_INIT;

/* ---------- Function prototypes ---------- */
int  authenticate(void);
void show_menu(void);
void check_balance(void);
void deposit_cash(void);
void withdraw_cash(void);
void change_pin(void);
void clear_input_buffer(void);

/* ---------- Main ---------- */
int main(void) {
    printf("=========================================\n");
    printf("      WELCOME TO SIMPLE-C ATM MACHINE\n");
    printf("=========================================\n");

    if (!authenticate()) {
        printf("\nToo many incorrect PIN attempts. Card blocked.\n");
        printf("Please contact your bank.\n");
        return 0;
    }

    int choice;
    int running = 1;

    while (running) {
        show_menu();
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                check_balance();
                break;
            case 2:
                deposit_cash();
                break;
            case 3:
                withdraw_cash();
                break;
            case 4:
                change_pin();
                break;
            case 5:
                printf("\nThank you for using Simple-C ATM. Goodbye!\n");
                running = 0;
                break;
            default:
                printf("\nInvalid choice. Please select a valid option.\n\n");
        }
    }

    return 0;
}

/* ---------- PIN authentication ---------- */
int authenticate(void) {
    int entered_pin;
    int attempts = 0;

    while (attempts < MAX_PIN_ATTEMPTS) {
        printf("\nEnter your 4-digit PIN: ");

        if (scanf("%d", &entered_pin) != 1) {
            printf("Invalid input.\n");
            clear_input_buffer();
            attempts++;
            continue;
        }

        if (entered_pin == pin) {
            printf("\nPIN accepted. Access granted.\n");
            return 1;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n",
                   MAX_PIN_ATTEMPTS - attempts);
        }
    }

    return 0;
}

/* ---------- Menu display ---------- */
void show_menu(void) {
    printf("\n----------- MAIN MENU -----------\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Cash\n");
    printf("3. Withdraw Cash\n");
    printf("4. Change PIN\n");
    printf("5. Exit\n");
    printf("----------------------------------\n");
}

/* ---------- Option 1: Check balance ---------- */
void check_balance(void) {
    printf("\nYour current balance is: %.2f\n", balance);
}

/* ---------- Option 2: Deposit ---------- */
void deposit_cash(void) {
    double amount;

    printf("\nEnter amount to deposit: ");
    if (scanf("%lf", &amount) != 1 || amount <= 0) {
        printf("Invalid deposit amount.\n");
        clear_input_buffer();
        return;
    }

    balance += amount;
    printf("Deposit successful! New balance: %.2f\n", balance);
}

/* ---------- Option 3: Withdraw ---------- */
void withdraw_cash(void) {
    double amount;

    printf("\nEnter amount to withdraw: ");
    if (scanf("%lf", &amount) != 1 || amount <= 0) {
        printf("Invalid withdrawal amount.\n");
        clear_input_buffer();
        return;
    }

    if (amount > balance) {
        printf("Insufficient balance. Your balance is %.2f\n", balance);
        return;
    }

    /* Optional: enforce notes of 100 like real ATMs */
    if ((long)amount % 100 != 0) {
        printf("Please enter an amount in multiples of 100.\n");
        return;
    }

    balance -= amount;
    printf("Withdrawal successful! New balance: %.2f\n", balance);
}

/* ---------- Option 4: Change PIN ---------- */
void change_pin(void) {
    int old_pin, new_pin, confirm_pin;

    printf("\nEnter current PIN: ");
    if (scanf("%d", &old_pin) != 1) {
        printf("Invalid input.\n");
        clear_input_buffer();
        return;
    }

    if (old_pin != pin) {
        printf("Incorrect current PIN. PIN not changed.\n");
        return;
    }

    printf("Enter new 4-digit PIN: ");
    if (scanf("%d", &new_pin) != 1 || new_pin < 1000 || new_pin > 9999) {
        printf("Invalid PIN. Must be a 4-digit number.\n");
        clear_input_buffer();
        return;
    }

    printf("Confirm new PIN: ");
    if (scanf("%d", &confirm_pin) != 1) {
        printf("Invalid input.\n");
        clear_input_buffer();
        return;
    }

    if (new_pin != confirm_pin) {
        printf("PINs do not match. PIN not changed.\n");
        return;
    }

    pin = new_pin;
    printf("PIN changed successfully!\n");
}

/* ---------- Utility: clear bad input from stdin ---------- */
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}