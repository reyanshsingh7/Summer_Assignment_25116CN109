#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int i;
    int even = 0;
    int odd = 0;

    //Take number of elements as input from user
    printf("Enter number of elements: ");
    scanf("%d",  &n);
    
    //Take array elements as input from user
    printf("Enter %d elements:\n ");
    for (i = 0; i < n; i++) {
        scanf("%d", arr[i]);
    }

    //Count even and odd elements 
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

      //Display array elements
    printf("\nArray elements: ");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

    //Display even and odd element
    printf("\nEven elements count = %d\n", even);
    printf("Odd elements count = %d\n", odd);

    return 0;
}