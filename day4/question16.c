#include <stdio.h>
#include <math.h>

int Armstrong(int n) {  // Function to check if a number is an Armstrong number
    int original = n, remainder, digits = 0;  // Variable to store the original number, the remainder, and the count of digits
    double result = 0;  // Variable to store the calculated result of the sum of the digits raised to the power of the number of digits

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
    // Check if the calculated result is equal to the original number
    return (int)result == original;
}

int main() {
    int start, end;

    // Prompt the user for the start and end of the range
    printf("Enter start of range: ");
    scanf("%d", &start);

    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("\nArmstrong numbers between %d and %d :\n", start, end);

    // Loop through the range and check for Armstrong numbers, printing them if found
    int found = 0;
    for(int i = start; i <= end; i++) { 
        if(Armstrong(i)) {
            printf("%d ", i);
            found = 1;
        }
    }

    // If no Armstrong numbers are found, print a message indicating that
    if(!found) {
        printf("No Armstrong numbers found in the given range.");
    }
    return 0;
}