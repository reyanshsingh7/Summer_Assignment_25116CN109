#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int secret, guess, attempts = 0, max_attempts = 10;
    int min = 1, max = 100;

    srand((unsigned int)time(NULL));
    secret = rand() % (max - min + 1) + min;

    printf("\n");
    printf("   NUMBER GUESSING GAME\n");
    printf("\n");
    printf("I'm thinking of a number between %d and %d.\n", min, max);
    printf("You have %d attempts to guess it.\n\n", max_attempts);

    while (attempts < max_attempts) {
        printf("Attempt %d/%d - Enter your guess: ", attempts + 1, max_attempts);

        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // clear bad input from buffer
            while (getchar() != '\n');
            continue;
        }

        attempts++;

        if (guess < min || guess > max) {
            printf("Please guess a number within the range %d-%d.\n\n", min, max);
            attempts--; // don't penalize out-of-range input
            continue;
        }

        if (guess < secret) {
            printf("Too low! Try again.\n\n");
        } else if (guess > secret) {
            printf("Too high! Try again.\n\n");
        } else {
            printf("\nCongratulations! You guessed it in %d attempt%s!\n",
                   attempts, attempts == 1 ? "" : "s");
            return 0;
        }
    }

    printf("\nGame over! You've used all your attempts.\n");
    printf("The number was: %d\n", secret);

    return 0;
}