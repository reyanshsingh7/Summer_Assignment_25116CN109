#include <stdio.h>

//Function to find factorial of the number
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;

    //Prompt user for Input
    printf("Enter a number: ");
    scanf("%d", &n);

    //Call factorial function and display the result
        printf("Factorial of %d = %lld\n", n, factorial(n));

    return 0;
}