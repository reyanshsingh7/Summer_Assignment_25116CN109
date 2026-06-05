#include <stdio.h>

int perfect(int n) {  // Function to check if a number is perfect

    if (n <= 1)
        return 0;
    
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {  // Loop to find divisors up to the square root of n
        if (n % i == 0) {  
            sum += i;
            if (i * i != n) {
                sum += n / i;
            }
        }
    }
    return sum == n;
}

int main() {
    int n;

    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%d", &n);

    // Check if the number is perfect and print the result
    if (perfect(n))
        printf("%d is a Perfect Number\n", n);
    else      
        printf("%d is not a Perfect Number\n", n);
    
    return 0;
}
