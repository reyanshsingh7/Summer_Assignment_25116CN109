#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int result[100];
    int i;
    int j;
    int k;
    int is_duplicate;
   
    //Take number of elements as input from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    //Take array elements as input from user
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Display original array
    printf("\nArray elements: ");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    //Remove duplicates from array
    k = 0;
    for (i = 0; i < n; i++){
        is_duplicate = 0;
        for (j = 0; j < k; j++) {
            if (arr[i] == result[j]) {
                is_duplicate = 1;
                break;
            }
        }
    

    if (is_duplicate == 0) {
        result[k] = arr[i];
        k++;
    }
}
    //Display updated array
    printf("\nUpdated array: ");
    for (i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}