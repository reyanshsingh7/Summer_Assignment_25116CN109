#include <stdio.h>

//Function to perform linear search
int linearsearch(int arr[], int n, int key) {
    int i;

    //Search for key in array
    for(i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
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
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    result = linearsearch(arr, n, key);  //Search for key in array

      //Display array elements
    printf("\nArray elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    //Display search result
    if (result == -1)
        printf("\n%d not found in array\n", key);
    else
        printf("\n%d found at index %d\n", key, result);

    return 0;
}