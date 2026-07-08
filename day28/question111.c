#include <stdio.h>
#include <string.h>

#define MAX_SEATS 20

struct Seat {
    int seatNo;
    int isBooked; // 0 = available, 1 = booked
    char passengerName[50];
};

struct Seat seats[MAX_SEATS];

void initSeats() {
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i].seatNo = i + 1;
        seats[i].isBooked = 0;
        strcpy(seats[i].passengerName, "-");
    }
}

void displaySeats() {
    printf("\nSeat No\tStatus\t\tPassenger\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("%d\t%s\t\t%s\n",
               seats[i].seatNo,
               seats[i].isBooked ? "Booked" : "Available",
               seats[i].passengerName);
    }
}

void bookSeat() {
    int seatNo;
    printf("Enter Seat Number to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (seats[seatNo - 1].isBooked) {
        printf("Seat already booked!\n");
        return;
    }

    printf("Enter Passenger Name: ");
    scanf("%s", seats[seatNo - 1].passengerName);
    seats[seatNo - 1].isBooked = 1;
    printf("Seat %d booked successfully!\n", seatNo);
}

void cancelBooking() {
    int seatNo;
    printf("Enter Seat Number to cancel: ");
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (!seats[seatNo - 1].isBooked) {
        printf("Seat is not booked.\n");
        return;
    }

    seats[seatNo - 1].isBooked = 0;
    strcpy(seats[seatNo - 1].passengerName, "-");
    printf("Booking for seat %d cancelled.\n", seatNo);
}

void searchSeat() {
    int seatNo;
    printf("Enter Seat Number to check: ");
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    printf("Seat %d Status: %s\n", seatNo, seats[seatNo - 1].isBooked ? "Booked" : "Available");
    if (seats[seatNo - 1].isBooked) {
        printf("Passenger: %s\n", seats[seatNo - 1].passengerName);
    }
}

int main() {
    int choice;
    initSeats();

    do {
        printf("\n--- Ticket Booking System ---\n");
        printf("1. Display All Seats\n");
        printf("2. Book Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Check Seat Status\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displaySeats(); break;
            case 2: bookSeat(); break;
            case 3: cancelBooking(); break;
            case 4: searchSeat(); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}