#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_QUESTIONS 10
#define NUM_OPTIONS 4

typedef struct {
    char question[200];
    char options[NUM_OPTIONS][100];
    char correctAnswer; // 'A', 'B', 'C', or 'D'
} Question;

void printHeader(void) {
    printf("========================================\n");
    printf("           C QUIZ APPLICATION\n");
    printf("========================================\n\n");
}

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

char getValidatedAnswer(void) {
    char answer;
    int valid = 0;

    while (!valid) {
        printf("Your answer (A/B/C/D): ");
        if (scanf(" %c", &answer) != 1) {
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        answer = toupper(answer);
        if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D') {
            valid = 1;
        } else {
            printf("Invalid input. Please enter A, B, C, or D.\n");
        }
    }
    return answer;
}

void showResult(int score, int total) {
    double percentage = (double)score / total * 100.0;

    printf("\n========================================\n");
    printf("               QUIZ RESULTS\n");
    printf("========================================\n");
    printf("Score: %d / %d\n", score, total);
    printf("Percentage: %.2f%%\n", percentage);

    if (percentage >= 90) {
        printf("Grade: A+  Excellent work!\n");
    } else if (percentage >= 75) {
        printf("Grade: A   Great job!\n");
    } else if (percentage >= 60) {
        printf("Grade: B   Good effort!\n");
    } else if (percentage >= 40) {
        printf("Grade: C   You can do better!\n");
    } else {
        printf("Grade: F   Keep studying!\n");
    }
    printf("========================================\n");
}

int main(void) {
    Question quiz[NUM_QUESTIONS] = {
        {"What is the capital of France?",
         {"A. Berlin", "B. Madrid", "C. Paris", "D. Rome"}, 'C'},

        {"Which planet is known as the Red Planet?",
         {"A. Earth", "B. Mars", "C. Jupiter", "D. Venus"}, 'B'},

        {"Who developed the C programming language?",
         {"A. James Gosling", "B. Guido van Rossum", "C. Dennis Ritchie", "D. Bjarne Stroustrup"}, 'C'},

        {"What is the chemical symbol for Gold?",
         {"A. Go", "B. Gd", "C. Au", "D. Ag"}, 'C'},

        {"How many continents are there on Earth?",
         {"A. 5", "B. 6", "C. 7", "D. 8"}, 'C'},

        {"Which data structure uses LIFO (Last In First Out)?",
         {"A. Queue", "B. Stack", "C. Array", "D. Linked List"}, 'B'},

        {"What is the largest ocean on Earth?",
         {"A. Atlantic", "B. Indian", "C. Arctic", "D. Pacific"}, 'D'},

        {"In C, which keyword is used to define a constant?",
         {"A. final", "B. const", "C. static", "D. define"}, 'B'},

        {"Who wrote the play 'Romeo and Juliet'?",
         {"A. Charles Dickens", "B. William Shakespeare", "C. Mark Twain", "D. Leo Tolstoy"}, 'B'},

        {"What is the time complexity of binary search?",
         {"A. O(n)", "B. O(n^2)", "C. O(log n)", "D. O(1)"}, 'C'}
    };

    int score = 0;
    char userAnswer;
    char playAgain = 'Y';

    do {
        score = 0;
        printHeader();
        printf("Answer the following %d questions.\n\n", NUM_QUESTIONS);

        for (int i = 0; i < NUM_QUESTIONS; i++) {
            printf("Q%d: %s\n", i + 1, quiz[i].question);
            for (int j = 0; j < NUM_OPTIONS; j++) {
                printf("   %s\n", quiz[i].options[j]);
            }

            userAnswer = getValidatedAnswer();

            if (userAnswer == quiz[i].correctAnswer) {
                printf("Correct!\n\n");
                score++;
            } else {
                printf("Wrong! The correct answer was %c.\n\n", quiz[i].correctAnswer);
            }
        }

        showResult(score, NUM_QUESTIONS);

        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
        clearInputBuffer();
        playAgain = toupper(playAgain);
        printf("\n");

    } while (playAgain == 'Y');

    printf("Thank you for playing the quiz! Goodbye.\n");

    return 0;
}