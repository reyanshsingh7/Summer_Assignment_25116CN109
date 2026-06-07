#include <stdio.h>

int sum(int n) {  // Function to calculate the sum of digits of a number

    // Handle negative numbers by converting them to positive
    if (n <= 0) 
        n = -n;

    // Base case: if n is a single digit, return n
    if (n < 10)
        return n;
    return (n % 10) + sum(n / 10);  // Recursive case: add the last digit to the sum of the remaining digits
}

int main() {
    int n;

    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate and print the sum of digits
    printf("Sum of digits of %d is %d\n", n, sum(n));
    return 0;
}