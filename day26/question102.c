#include <stdio.h>
#include <string.h>
#include <strings.h>

#define MIN_VOTING_AGE 18

typedef struct {
    char name[100];
    int age;
    char citizenship[50];
} Applicant;

void get_applicant_details(Applicant *a) {
    printf("Enter your name: ");
    scanf(" %99[^\n]", a->name);

    printf("Enter your age: ");
    scanf("%d", &a->age);

    printf("Enter your citizenship (e.g., Indian): ");
    scanf(" %49[^\n]", a->citizenship);
}

int is_eligible(const Applicant *a, char *reason, size_t reason_size) {
    if (a->age < MIN_VOTING_AGE) {
        snprintf(reason, reason_size,
                 "Age requirement not met (must be %d or older, you are %d).",
                 MIN_VOTING_AGE, a->age);
        return 0;
    }

    if (strcasecmp(a->citizenship, "Indian") != 0) {
        snprintf(reason, reason_size,
                 "Citizenship requirement not met (must be Indian citizen).");
        return 0;
    }

    return 1;
}

void print_result(const Applicant *a, int eligible, const char *reason) {
    printf("\n\n");
    printf("   VOTING ELIGIBILITY RESULT\n");
    printf("\n");
    printf("Name        : %s\n", a->name);
    printf("Age         : %d\n", a->age);
    printf("Citizenship : %s\n", a->citizenship);
    printf("\n");

    if (eligible) {
        printf("Status      : ELIGIBLE to vote.\n");
    } else {
        printf("Status      : NOT ELIGIBLE to vote.\n");
        printf("Reason      : %s\n", reason);
    }
    printf("\n");
}

int main(void) {
    Applicant applicant;
    char reason[150] = "";
    char choice;

    printf("\n");
    printf("   VOTING ELIGIBILITY SYSTEM\n");
    printf("\n\n");

    do {
        memset(&applicant, 0, sizeof(applicant));
        reason[0] = '\0';

        get_applicant_details(&applicant);

        int eligible = is_eligible(&applicant, reason, sizeof(reason));
        print_result(&applicant, eligible, reason);

        printf("\nCheck another applicant? (y/n): ");
        scanf(" %c", &choice);
        printf("\n");

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Voting Eligibility System.\n");

    return 0;
}