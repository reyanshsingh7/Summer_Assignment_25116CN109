#include <stdio.h>

int main() {
    int n;
    int arr[100];
    int i;
    int j;
    int max_freq;
    int max_elem;
    int freq;
   
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

    //Find maximum frequency element
    max_freq = 0;
    max_elem = arr[0];

    for (i =0; i < n; i++){
        freq = 0;
        for (j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                freq++;
            }
        }
        if (freq > max_freq) {
            max_freq = freq;
            max_elem = arr[i];
        }
    }

    //Display maximum frequency element
    printf("\nMaximum frequency element = %d", max_elem);
    printf("\nFrequency = %d\n", max_freq);
    printf("\n");

    return 0;
}