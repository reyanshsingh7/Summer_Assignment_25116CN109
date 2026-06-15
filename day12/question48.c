#include <stdio.h>

//Function to check if a number is perfect
int perfect(int n) {
    int sum = 0;
    int i;
    
    if (n <= 1)    //Numbers less than or equal to 1 are not perfect
        return 0;

    //Calculate sum of divisors
    for (i = 1; i < n; i++) {
        if(n % i == 0)
           sum += i;
    }

    return sum == n;
}

int main() {
    int n;

    //Take number as input from user
    printf("Enter a number: ");
    scanf("%d", &n);

    //Call perfect function and display the result
    if (perfect(n))
        printf("%d is a perfect number\n", n);
    else
        printf("%d is not a perfect number\n", n);

    return 0;
}