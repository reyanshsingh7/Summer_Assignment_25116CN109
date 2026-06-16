#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int i;
    int sum = 0;
    float average;

    //Take number of elements as input from user
    printf("Enter number of elements: ");
    scanf("%d",  &n);
    
    //Take array elements as input from user
    printf("Enter %d elements:\n ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Calculate sum of array elements
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    //Calculate average of array elements
    average = (float)sum / n;

    //Display array elements
    printf("\nArray elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    //Display sum and average
    printf("Sum of array = %d\n", sum);
    printf("Average of array = %.2f\n", average);

    return 0;
}