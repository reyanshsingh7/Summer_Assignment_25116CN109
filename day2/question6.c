#include <stdio.h>

int reversenumber(int n) {  // Function to reverse the digits of a number
    int rev = 0;
    int sign = (n < 0) ? -1 : 1;   // Store the sign of the number

    // Handle negative numbers by taking the absolute value
    if (n < 0)
    n = -n;

    // Special case for 0, which reverses to 0
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }   
    return sign * rev;  // Restore the original sign of the number
}

int main() {
    int num;

    // Prompt the user for input    
    printf("Enter a number: ");
    scanf("%d", &num);

    // Print the result
    printf("Reversed number: %d\n", reversenumber(num));
    return 0;
}