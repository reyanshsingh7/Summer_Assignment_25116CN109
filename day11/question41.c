#include <stdio.h>

//Function to calculate sum of two integers
int sum(int a, int b) {
    return a + b;
}

int main() {
    int a, b;

    //Prompt user for Input
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    //Call sum function and display the result
    printf("Sum of %d and %d = %d\n", a, b, sum(a, b));

    return 0;
}