#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int i;
    int largest;
    int smallest;

    //Take number of elements as input from user
    printf("Enter number of elements: ");
    scanf("%d",  &n);
    
    //Take array elements as input from user
    printf("Enter %d elements:\n ");
    for (i = 0; i < n; i++) {
        scanf("%d", arr[i]);
    }

    //Initialize largest and smallest with first element
    largest = arr[0];
    smallest = arr[0];

    //Find largest and smallest element
    for (i = 1; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];
        if (arr[i] < smallest)
            smallest = arr[i];
    }

      //Display array elements
    printf("\nArray elements: ");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

    //Display largest and smallest element
    printf("\nLargest element = %d\n", largest);
    printf("Smallest element = %d\n", smallest);

    return 0;
}