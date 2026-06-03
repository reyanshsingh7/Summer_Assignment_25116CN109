#include<stdio.h>
#include<math.h>

int prime(int n) {  // Function to check if a number is prime

    // Handle numbers less than 2
    if (n < 2)
        return 0;

    // Check for factors from 2 to the square root of n
    if (n == 2)
        return 1;

        // Eliminate even numbers greater than 2 and numbers divisible by 3
    if (n % 2 == 0 || n % 3 == 0)
        return 0;

        // Check for factors from 5 to the square root of n, skipping even numbers
    for (int i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int main() {
    int low, high;

    // Prompt the user for input
    printf("Enter range: ");
    scanf("%d %d", &low, &high);

    // Print the prime numbers in the specified range
    printf("Prime numbers from %d to %d:\n", low, high);

    // Loop through the range and print prime numbers
    for (int i = low; i <= high; i++) {
        if (prime(i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
