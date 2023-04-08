#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "room.h"
#include "main.h"
#include "queryStudents.h"
#include "enterStudents.h"
#include "directNeighbors.h"
#include "indirectNeighbors.h"

void queryStudents(Room *room) {
    printf("\nquery students\n");
    printSeatsInUse(room);
    while(1) {
        char studentId[MAGIC_NUMBER];
        printf("\nenter student id: ");
        scanf("%s", studentId);
        if (strcmp(studentId, "-abort") == 0) {
            freeRoom(room);
            exit(0);
        }
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

void printNeighbors(Room *room, int seat) {
    printf("\ndirect neighbors: \n");
    printTopLeftSeat(room, seat);
    printTopSeat(room, seat);
    printTopRightSeat(room, seat);
    printRightSeat(room, seat);
    printBottomRightSeat(room, seat);
    printBottomSeat(room, seat);
    printBottomLeftSeat(room, seat);
    printLeftSeat(room, seat);

    printf("\nindirect neighbors: \n");
    printTopTopLeftLeftSeat(room, seat);
    printTopTopLeftSeat(room, seat);
    printTopTopSeat(room, seat);
    printTopTopRightSeat(room, seat);
    printTopTopRightRightSeat(room, seat);
    printTopRightRightSeat(room, seat);
    printRightRightSeat(room, seat);
    printBottomRightRightSeat(room, seat);
    printBottomBottomRightRightSeat(room, seat);
    printBottomBottomRightSeat(room, seat);
    printBottomBottomSeat(room, seat);
    printBottomBottomLeftSeat(room, seat);
    printBottomBottomLeftLeftSeat(room, seat);
    printBottomLeftLeftSeat(room, seat);
    printLeftLeftSeat(room, seat);
    printTopLeftLeftSeat(room, seat);
}