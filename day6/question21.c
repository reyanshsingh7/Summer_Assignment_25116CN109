#include <stdio.h>

void Binary(int n) {  // Function to convert a decimal number to binary and print it
    if (n == 0) {
        printf("0");
        return;
    }

    // Array to store binary digits, and an index variable
    int binary[32];
    int i = 0;

    while (n > 0) {  // Loop until n becomes 0
        binary[i++] = n % 2; 
        n /= 2;
    }

    // Print the binary number in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main() {
    int num;

    // Prompt the user for a decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    // Check if the number is negative, as binary representation for negative numbers is not handled in this function
    if (num < 0) {
        printf("Negative numbers are not supported.\n");
        return 1;
    }

    // Print the decimal number and its binary representation
    printf("\n  Number   : %d\n", num);
    printf("Binary: ");
    Binary(num);
    printf("\n");

    return 0;
}