#include <stdio.h>

long long reverse(int n, long long rev) {   // Function to reverse the digits of a number using recursion

    // Base case: when n is reduced to 0, return the reversed number
    if (n == 0) 
        return rev;  
    return reverse(n / 10, rev * 10 + n % 10);  // Recursive case: add the last digit to rev and call reverse on the remaining digits
}

int main() {
    int n;

    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate and print the reversed number
    long long rev = reverse(n, 0);  
    printf("Reversed number of %d is %lld\n", n, rev);
    
    return 0;
}