#include <stdio.h>
#include <math.h>

int Decimal(long long binary) {  // Function to convert a binary number (given as a long long) to decimal
    int decimal = 0;
    int position = 0;

    while (binary != 0) {  // Loop until the binary number becomes 0
        int digit = binary % 10; // Get the last digit of the binary number
    
        if (digit != 0 && digit != 1) {  // Check if the digit is not 0 or 1, which means it's an invalid binary number
            return -1; 
        }

        decimal += digit * pow(2, position); // Convert to decimal
        binary /= 10; // Remove the last digit      
        position++;
    }

    return decimal;
}

int main() {
    long long binary;

    // Prompt the user for a binary number
    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    // Convert the binary number to decimal and print the result
    int result = Decimal(binary);
    

    // Check if the result is -1, which indicates an invalid binary number
    if (result == -1) {
        printf("Invalid binary number.\n");
    } else {
        printf("Decimal: %d\n", result);
    }

    return 0;
}