#include <stdio.h>

//Function to find maximum of two integers
int maximum(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    int a, b;

    //Prompt user for Input
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    //Call maximum function and display the result
    printf("Maximum of %d and %d = %d\n", a, b, maximum(a, b));

    return 0;
}