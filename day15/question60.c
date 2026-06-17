#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int i;
    int j;
   
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

    //Move zeroes to end
    j = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] != 0) {
             arr[j] = arr[i];
             j++;
        }
    }

    //Fill remaining positions with zeroes
    while (j < n) {
        arr[j] = 0;
        j++;
    }
    //Display updated array
    printf("\nUpdated array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}