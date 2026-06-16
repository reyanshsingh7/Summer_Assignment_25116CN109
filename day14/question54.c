#include <stdio.h>

//Function to find frequency of an element
int frequency(int arr[], int n, int key) {
    int i;
    int count = 0;

    //Count frequency of key in array
    for(i = 0; i < n; i++) {
        if (arr[i] == key)
            count++;
    }
    return count;
}

int main() {
    int n;
    int arr[100];
    int i;
    int key;
    int result;

    //Take number of elements as input from user
    printf("Enter number of elements: ");
    scanf("%d",  &n);
    
    //Take array elements as input from user
    printf("Enter %d elements:\n ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Take search element as input from user
    printf("\nEnter element to find frequency: ");
    scanf("%d", &key);

    result = frequency(arr, n, key);  //Search for key in array

      //Display array elements
    printf("\nArray elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    //Display frequency result
    if (result == 0)
        printf("\n%d not found in array\n", key);
    else
        printf("\nFrequency of %d = %d\n", key, result);

    return 0;
}