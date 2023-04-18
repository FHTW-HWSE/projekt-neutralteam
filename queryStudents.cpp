#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "room.hpp"
#include "main.hpp"
#include "queryStudents.hpp"
#include "enterStudents.hpp"
#include "directNeighbors.hpp"
#include "indirectNeighbors.hpp"

void queryStudents(Room *room) {
    printf("\nquery students\n");
    printSeatsInUse(room);
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
        int seat = getSeatByStudentId(room, studentId);
        if (seat == -1) {
            printf("student not found\n");
        } else {
            printf("student found at seat %d\n", seat);
            printNeighbors(room, seat);
        }
    }
    freeRoom(room);
}

void printNeighbors(Room *room, int seat) {
    printf("\ndirect neighbors: \n");
    printSeat(room, getTopLeftSeat(room, seat));
    printSeat(room, getTopSeat(room, seat));
    printSeat(room, getTopRightSeat(room, seat));
    printSeat(room, getRightSeat(room, seat));
    printSeat(room, getBottomRightSeat(room, seat));
    printSeat(room, getBottomSeat(room, seat));
    printSeat(room, getBottomLeftSeat(room, seat));
    printSeat(room, getLeftSeat(room, seat));
    printf("\nindirect neighbors: \n");
    printSeat(room, getTopTopLeftLeftSeat(room, seat));
    printSeat(room, getTopTopLeftSeat(room, seat));
    printSeat(room, getTopTopSeat(room, seat));
    printSeat(room, getTopTopRightSeat(room, seat));
    printSeat(room, getTopTopRightRightSeat(room, seat));
    printSeat(room, getTopLeftLeftSeat(room, seat));
    printSeat(room, getTopRightRightSeat(room, seat));
    printSeat(room, getBottomBottomLeftLeftSeat(room, seat));
    printSeat(room, getBottomBottomLeftSeat(room, seat));
    printSeat(room, getBottomBottomSeat(room, seat));
    printSeat(room, getBottomBottomRightSeat(room, seat));
    printSeat(room, getBottomBottomRightRightSeat(room, seat));
    printSeat(room, getBottomLeftLeftSeat(room, seat));
    printSeat(room, getBottomRightRightSeat(room, seat));
    printSeat(room, getLeftLeftSeat(room, seat));
    printSeat(room, getRightRightSeat(room, seat));
}

void printSeat(Room *room, int seat) {
    if (isValidSeat(room, seat)) {
        if (strlen(room->seats[seat]) > 0) {
            printf("%d: %s\n", seat, room->seats[seat]);
        }
    }
}
  
int getSeatByStudentId(Room *room, char *studentId) {
    for (int i = 0; i < room->rows*room->cols; i++) {
        if (isValidSeat(room, i)) {
            if (strcmp(room->seats[i], studentId) == 0) {
                return i;
            }
        }
    }
    return -1;
}