#include <stdio.h>

//Function to print fibonacci series upto n terms
void fibonacci(int n) {
    int first = 0;
    int second = 1;
    int next;
    int i;

    //Print Fibonacci Series
    printf("Fibonacci Series: ");

    for (i = 1; i <= n; i++) {
        printf("%d ", first);

        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}

int main() {
    int n;

    //Take number of terms as input from user
    printf("Enter number of terms: ");
    scanf("%d", &n);

    //Call fibonacci function and display the result
    fibonacci(n);

    return 0;
}