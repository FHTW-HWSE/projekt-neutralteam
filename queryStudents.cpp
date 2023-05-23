#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "main.hpp"
#include "queryStudents.hpp"
#include "enterStudents.hpp"
#include "directNeighbors.hpp"
#include "indirectNeighbors.hpp"
#include "seat.hpp"

void queryStudents(Room *room) {
    printf("\nquery students\n");
    Seats *seatsInUse = getSeatsInUse(room);
    printSeats(room, seatsInUse);
    free (seatsInUse->seats);
    free (seatsInUse);
    while(1) {
        char studentId[MAX_STUDENTID_LENGTH+1];
        do {
            printf("\nenter student id: ");
            scanf("%s", studentId);
            if (strcmp(studentId, END_PROGRAM_KEYWORD) == 0) {
                freeRoom(room);
                exit(0);
            }
        } while(!isValidStudentId(studentId));
        int seatNumber = getSeatNumberByStudentId(room, studentId);
        if (seatNumber == -1) {
            printf("student not found\n");
        } else {
            printf("student found at seat %d\n", seatNumber);
            Seats *directNeighbors = getDirectNeighborSeats(room, seatNumber);
            Seats *indirectNeighbors = getIndirectNeighborSeats(room, seatNumber);
            printf("direct neighbors:\n");
            printSeats(room, directNeighbors);
            printf("indirect neighbors:\n");
            printSeats(room, indirectNeighbors);
            free(directNeighbors->seats);
            free(directNeighbors);
            free(indirectNeighbors->seats);
            free(indirectNeighbors);
        }
    }
    freeRoom(room);
}
  
int getSeatNumberByStudentId(Room *room, char *studentId) {
    for (int i = 0; i < room->rows*room->cols; i++) {
        if (isValidSeatNumber(room, i)) {
            if (strcmp(room->seats[i], studentId) == 0) {
                return i;
            }
        }
    }
    return -1;
}