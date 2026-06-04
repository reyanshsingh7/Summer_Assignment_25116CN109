#include <stdio.h>
#include <math.h>

int main() {
    int n, original, remainder, digits = 0;  // Variable to store the input number, its original value, the remainder, and the count of digits
    double result = 0;  // Variable to store the calculated result of the sum of the digits raised to the power of the number of digits

    // Prompt the user for input
    printf("Enter an number: ");
    scanf("%d", &n);

    original = n;

    int temp = n;

    // Count the number of digits in the input number
    while(temp != 0) {
        digits++;
        temp /= 10;
    }
    temp = n;

    // Calculate the sum of the digits raised to the power of the number of digits
    while(temp != 0) {
        remainder = temp % 10;
        result += pow(remainder, digits);
        temp /= 10;
    }

    // Check if the calculated result is equal to the original number and print the appropriate message
    if((int)result == original) {
        printf("%d is an Armstrong number.\n", original);   
    }
    
    // If the calculated result is not equal to the original number, print that it is not an Armstrong number
    else {
        printf("%d is not an Armstrong number.\n", original);
    }
    return 0;
}