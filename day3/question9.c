#include<stdio.h>
#include<math.h>

int prime(int n) {  // Function to check if a number is prime

    // Handle numbers less than or equal to 1
    if (n <= 1)
    return 0;

    // Check for factors from 2 to the square root of n
    if (n <= 3)
    return 1;

    // Eliminate even numbers greater than 2 and numbers divisible by 3
    if (n % 2 == 0 || n % 3 == 0)
    return 0;

    // Check for factors from 5 to the square root of n, skipping even numbers
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
        return 0;
    }
    return 1;
}

int main() {
    int num;

    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Print the result
    if (prime(num))
        printf("%d is a Prime number\n", num);
    else
        printf("%d is not a Prime number\n", num);
    return 0;
}