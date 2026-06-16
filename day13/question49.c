#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int i;

    //Take number of elements as input from user
    printf("Enter number of elements: ");
    scanf("%d",  &n);
    
    //Take array elements as input from user
    printf("Enter %d elements:\n ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Display array elements
    printf("\nArray elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}