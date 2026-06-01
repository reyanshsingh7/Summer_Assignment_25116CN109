#include <stdio.h>

int main() {
    long long n;  // Use long long to handle large numbers of digits for big N
    int count = 0;

    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%lld", &n);

    // Handle negative numbers by taking the absolute value
    if (n<0)
    n = -n;

    // Special case for 0, which has 1 digit
    if (n == 0) {
        printf("Number of digits: 1\n");
        return 0;
    }

    // Count the number of digits using a loop
    while (n != 0) {
        n /= 10;
        count++;
    }
    
    // Print the result
    printf("Number of digits: %d\n", count);

    return 0;
}