#include <stdio.h>
#include <math.h>

//Function to count number of digits
int countdigits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /=10;
    }
    return count;
}

//Function to check if number is armstrong
int armstrong(int n) {
    int original = n;
    int digits   = countdigits(n);
    int sum      = 0;
    int digit;

    //Calculate the number of digits raised to the power of digits
    while (n > 0) {
        digit = n % 10;
        sum  += (int)pow(digit, digits);
        n  /= 10;
    }
    return sum == original;  //Check if the sum is equal to the original number
}

int main() {
    int n;

    //Take number as input from the user
    printf("Enter a number: ");
    scanf("%d", &n);

    //Call armstrong unction and display the result
    if (armstrong(n))
        printf("%d is an armstrong number\n", n);
    else
        printf("%d is not anarmstrong number\n", n);
    
    return 0;

}