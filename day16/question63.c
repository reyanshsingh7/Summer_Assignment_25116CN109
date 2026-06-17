#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int i;
    int j;
    int target;
    int found;
   
    //Take number of elements as input from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    //Take array elements as input from user
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Take target sum as input from user
    printf("Enter target sum: ");
    scanf("%d", &target);

    //Display original array
    printf("\nArray elements: ");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    //Find pair with given sum
    found = 0;
    printf("\nPairs with sum %d:\n", target);

    for (i =0; i < n; i++){
        for (j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("(%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (found == 0) {
        printf("No pair found with sum %d\n", target);
    }

    return 0;
}