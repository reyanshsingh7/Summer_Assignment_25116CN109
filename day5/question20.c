#include <stdio.h>

int main() {
    int n, largest = -1;

    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%d", &n);    

    // Check for the smallest prime factor 2
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }

    // Check for odd factors from 3 to the square root of n
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }

    // If n is a prime number greater than 2, then it is the largest prime factor
    if (n > 2)  
        largest = n;

    printf("The Largest Prime Factor is: %d\n", largest);
    return 0;
}