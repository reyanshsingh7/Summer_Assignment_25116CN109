#include<stdio.h>
int main() {
    int n;

    // Prompt the user for the number of terms in the Fibonacci series
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Validate the input to ensure it's a positive integer
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1; 
    }

    // Initialize the first two terms of the Fibonacci series
    long long a = 0, b = 1;

    printf("Fibonacci Series:\n");

    // Generate and print the Fibonacci series up to n terms
    for (int i = 1; i <= n; i++) {
        printf("%lld ", a);
        if ( i < n ) 
        printf(", ");
        
        long long next = a + b; 
        a = b; 
        b = next; 
    }

    printf("\n");
    return 0;
}