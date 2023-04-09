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
    int topLeftSeat = getTopLeftSeat(room, seat);
    if (topLeftSeat != -1) {
        if (strlen(room->seats[topLeftSeat]) > 0)
            printf("%d: %s\n", topLeftSeat, room->seats[topLeftSeat]);
    }
    int topSeat = getTopSeat(room, seat);
    if (topSeat != -1) {
        if (strlen(room->seats[topSeat]) > 0)
            printf("%d: %s\n", topSeat, room->seats[topSeat]);
    }
    int topRightSeat = getTopRightSeat(room, seat);
    if (topRightSeat != -1) {
        if (strlen(room->seats[topRightSeat]) > 0)
            printf("%d: %s\n", topRightSeat, room->seats[topRightSeat]);
    }
    int rightSeat = getRightSeat(room, seat);
    if (rightSeat != -1) {
        if (strlen(room->seats[rightSeat]) > 0)
            printf("%d: %s\n", rightSeat, room->seats[rightSeat]);
    }
    int bottomRightSeat = getBottomRightSeat(room, seat);
    if (bottomRightSeat != -1) {
        if (strlen(room->seats[bottomRightSeat]) > 0)
            printf("%d: %s\n", bottomRightSeat, room->seats[bottomRightSeat]);
    }
    int bottomSeat = getBottomSeat(room, seat);
    if (bottomSeat != -1) {
        if (strlen(room->seats[bottomSeat]) > 0)
            printf("%d: %s\n", bottomSeat, room->seats[bottomSeat]);
    }
    int bottomLeftSeat = getBottomLeftSeat(room, seat);
    if (bottomLeftSeat != -1) {
        if (strlen(room->seats[bottomLeftSeat]) > 0)
            printf("%d: %s\n", bottomLeftSeat, room->seats[bottomLeftSeat]);
    }
    int leftSeat = getLeftSeat(room, seat);
    if (leftSeat != -1) {
        if (strlen(room->seats[leftSeat]) > 0)
            printf("%d: %s\n", leftSeat, room->seats[leftSeat]);
    }
    printf("\nindirect neighbors: \n");
    int TopTopLeftLeftSeat = getTopTopLeftLeftSeat(room, seat);
    if (TopTopLeftLeftSeat != -1) {
        if (strlen(room->seats[TopTopLeftLeftSeat]) > 0)
            printf("%d: %s\n", TopTopLeftLeftSeat, room->seats[TopTopLeftLeftSeat]);
    }
    int TopTopLeftSeat = getTopTopLeftSeat(room, seat);
    if (TopTopLeftSeat != -1) {
        if (strlen(room->seats[TopTopLeftSeat]) > 0)
            printf("%d: %s\n", TopTopLeftSeat, room->seats[TopTopLeftSeat]);
    }
    int TopTopSeat = getTopTopSeat(room, seat);
    if (TopTopSeat != -1) {
        if (strlen(room->seats[TopTopSeat]) > 0)
            printf("%d: %s\n", TopTopSeat, room->seats[TopTopSeat]);
    }
    int TopTopRightSeat = getTopTopRightSeat(room, seat);
    if (TopTopRightSeat != -1) {
        if (strlen(room->seats[TopTopRightSeat]) > 0)
            printf("%d: %s\n", TopTopRightSeat, room->seats[TopTopRightSeat]);
    }
    int TopTopRightRightSeat = getTopTopRightRightSeat(room, seat);
    if (TopTopRightRightSeat != -1) {
        if (strlen(room->seats[TopTopRightRightSeat]) > 0)
            printf("%d: %s\n", TopTopRightRightSeat, room->seats[TopTopRightRightSeat]);
    }
    int TopRightRightSeat = getTopRightRightSeat(room, seat);
    if (TopRightRightSeat != -1) {
        if (strlen(room->seats[TopRightRightSeat]) > 0)
            printf("%d: %s\n", TopRightRightSeat, room->seats[TopRightRightSeat]);
    }
    int RightRightSeat = getRightRightSeat(room, seat);
    if (RightRightSeat != -1) {
        if (strlen(room->seats[RightRightSeat]) > 0)
            printf("%d: %s\n", RightRightSeat, room->seats[RightRightSeat]);
    }
    int BottomBottomRightRightSeat = getBottomBottomRightRightSeat(room, seat);
    if (BottomBottomRightRightSeat != -1) {
        if (strlen(room->seats[BottomBottomRightRightSeat]) > 0)
            printf("%d: %s\n", BottomBottomRightRightSeat, room->seats[BottomBottomRightRightSeat]);
    }
    int BottomBottomRightSeat = getBottomBottomRightSeat(room, seat);
    if (BottomBottomRightSeat != -1) {
        if (strlen(room->seats[BottomBottomRightSeat]) > 0)
            printf("%d: %s\n", BottomBottomRightSeat, room->seats[BottomBottomRightSeat]);
    }
    int BottomBottomSeat = getBottomBottomSeat(room, seat);
    if (BottomBottomSeat != -1) {
        if (strlen(room->seats[BottomBottomSeat]) > 0)
            printf("%d: %s\n", BottomBottomSeat, room->seats[BottomBottomSeat]);
    }
    int BottomBottomLeftSeat = getBottomBottomLeftSeat(room, seat);
    if (BottomBottomLeftSeat != -1) {
        if (strlen(room->seats[BottomBottomLeftSeat]) > 0)
            printf("%d: %s\n", BottomBottomLeftSeat, room->seats[BottomBottomLeftSeat]);
    }
    int BottomBottomLeftLeftSeat = getBottomBottomLeftLeftSeat(room, seat);
    if (BottomBottomLeftLeftSeat != -1) {
        if (strlen(room->seats[BottomBottomLeftLeftSeat]) > 0)
            printf("%d: %s\n", BottomBottomLeftLeftSeat, room->seats[BottomBottomLeftLeftSeat]);
    }
    int BottomLeftLeftSeat = getBottomLeftLeftSeat(room, seat);
    if (BottomLeftLeftSeat != -1) {
        if (strlen(room->seats[BottomLeftLeftSeat]) > 0)
            printf("%d: %s\n", BottomLeftLeftSeat, room->seats[BottomLeftLeftSeat]);
    }
    int LeftLeftSeat = getLeftLeftSeat(room, seat);
    if (LeftLeftSeat != -1) {
        if (strlen(room->seats[LeftLeftSeat]) > 0)
            printf("%d: %s\n", LeftLeftSeat, room->seats[LeftLeftSeat]);
    }
    printf("\n");
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