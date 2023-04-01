#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enterStudents.h"
#include "loadRoom.h"
#include "room.h"
#include "main.h"

void enterStudents(Room *room) {
    printf("\nentering students\n");
    printf("valid seats: ");
    for (int i = 0; i < room->rows*room->cols; i++) {
        if (isValidSeat(room, i)) {
            printf("%d ", i);
        }
    }
    printf("\nconfirm with -save\n");

   while(1) {
        printf("\n");

        int seat = 0;
        char seatString[MAGIC_NUMBER] = "";
        do {
            printf("enter seat: ");
            scanf("%s", seatString);
            if (strcmp(seatString, "-abort") == 0) {
                freeRoom(room);
                exit(0);
            }
            if (strcmp(seatString, "-save") == 0) {
                saveRoomToFile(room);
                loadRoom(room);
                return;
            }
            seat = atoi(seatString);
        } while (!isValidSeat(room, seat));

        char studentId[MAGIC_NUMBER] = "";
        do {
            printf("enter student id: ");
            scanf("%s", studentId);
            if (strcmp(studentId, "-abort") == 0) {
                freeRoom(room);
                exit(0);
            }
            if (strcmp(studentId, "-save") == 0) {
                saveRoomToFile(room);
                loadRoom(room);
                return;
            }
        } while (!isValidStudentId(studentId));
        strcpy(room->seats[seat], studentId);
   }
}

int isValidStudentId(char *studentId) {
    char c;
    while((c = *studentId++) != '\0') {
        if (c == '-')
            return 0;

    }
    return 1;
}