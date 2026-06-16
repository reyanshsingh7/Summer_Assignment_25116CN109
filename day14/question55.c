#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int i;
    int first;
    int second;

    //Take number of elements as input from user
    printf("Enter number of elements: ");
    scanf("%d",  &n);
    
    //Take array elements as input from user
    printf("Enter %d elements:\n ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Initialize first and second with first element
    first = second = -2147483648;

    //Find second largest element
    for (i = 0; i < n; i++) {
        if (arr[i] > first){
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first){
                 second = arr[i];
        }
    }

      //Display array elements
    printf("\nArray elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    //Display second largest element
    printf("\nSecond largest element = %d\n", second);

    return 0;
}