#include <stdio.h>
#include <string.h>

#define maxwords 100   // Maximum number of words the program can handle
#define maxlength 50   // Maximum length of each word

// Function to sort an array of words by their length using Bubble Sort
void sortByLength(char words[][maxlength], int n) {
    char temp[maxlength];  // Temporary array used for swapping words

    //number of passes needed
    for (int i = 0; i < n - 1; i++) {

        //compare adjacent words in each pass
        for (int j = 0; j < n - i - 1; j++) {

            // If the current word is longer than the next word, swap them
            if (strlen(words[j]) > strlen(words[j + 1])) {
                strcpy(temp, words[j]);          
                strcpy(words[j], words[j + 1]);  
                strcpy(words[j + 1], temp);      
            }
        }
    }
}

int main() {
    char words[maxwords][maxlength];  // 2D array to store words (each row = one word)
    int n;                           

    // Ask the user how many words they want to enter
    printf("Enter number of words: ");
    scanf("%d", &n);

    // Read each word into the array
    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);   
    }

    // Call the function to sort words by length
    sortByLength(words, n);

    // Print the sorted words
    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0; 
}
