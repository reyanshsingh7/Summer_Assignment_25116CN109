#include <stdio.h>

#define MAX 100

int arr[MAX];
int size = 0;

void insertElement() {
    if (size >= MAX) {
        printf("Array is full.\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &arr[size]);
    size++;
    printf("Element inserted!\n");
}

void displayArray() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void searchElement() {
    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d (index %d).\n", i + 1, i);
            return;
        }
    }
    printf("Element not found.\n");
}

void deleteElement() {
    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            printf("Element deleted!\n");
            return;
        }
    }
    printf("Element not found.\n");
}

void sortArray() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted!\n");
    displayArray();
}

void reverseArray() {
    int start = 0, end = size - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    printf("Array reversed!\n");
    displayArray();
}

void sumAndAverage() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    double average = (double)sum / size;
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
}

void findMaxMin() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    int max = arr[0], min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
}

int main() {
    int choice;

    do {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Insert Element\n");
        printf("2. Display Array\n");
        printf("3. Search Element\n");
        printf("4. Delete Element\n");
        printf("5. Sort Array\n");
        printf("6. Reverse Array\n");
        printf("7. Sum and Average\n");
        printf("8. Find Max and Min\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertElement(); break;
            case 2: displayArray(); break;
            case 3: searchElement(); break;
            case 4: deleteElement(); break;
            case 5: sortArray(); break;
            case 6: reverseArray(); break;
            case 7: sumAndAverage(); break;
            case 8: findMaxMin(); break;
            case 9: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 9);

    return 0;
}