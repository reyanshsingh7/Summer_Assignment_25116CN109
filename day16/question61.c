#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int i;
    int expected_sum;
    int actual_sum;
    int missing;
   
    //Take number of elements as input from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    //Take array elements as input from user
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Display original array
    printf("\nOriginal array: ");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    //Calculate expected sum of 1 to n+1
    expected_sum = (n + 1) * (n + 2) / 2;

    //Calculate actual sum of array elements
    actual_sum = 0;
    for (i =0; i < n; i++){
        actual_sum += arr[i];
    }

    //Find missing number
    missing = expected_sum - actual_sum;

    //Display missing number
    printf("\nMissing number = %d\n", missing);

    printf("\n");

    return 0;
}