#include <stdio.h>

int main() {
    int n;
    long long sum = 0; // Use long long to handle large sums for big N

    // Prompt the user for input
    printf("Enter a positive integer N: ");
    scanf("%d" , &n);
    
    // Check if the input is a positive integer
    if (n < 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Calculate the sum of the first N natural numbers using a loop
    for (int i = 1; i <= n; i++) {
        sum += i;
    }


    // Print the result
    printf("Sum of first %d natural numbers = %lld\n", n, sum);
    printf("Using formula N*(N+1)/2 = %lld\n", (long long)n * (n+1)/2);

    return 0;
}