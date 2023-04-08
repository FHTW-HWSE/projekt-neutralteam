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
                char filename[MAGIC_NUMBER];
                do {
                    printf("enter filename: ");
                    scanf("%s", filename);
                    if (strcmp(filename, "-abort") == 0) {
                        freeRoom(room);
                        exit(0);
                    }
                } while(!isValidRoomFileName(filename));
                saveRoomToFile(room, filename);
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
                char filename[MAGIC_NUMBER];
                do {
                    printf("enter filename: ");
                    scanf("%s", filename);
                    if (strcmp(filename, "-abort") == 0) {
                        freeRoom(room);
                        exit(0);
                    }
                } while(!isValidRoomFileName(filename));
                saveRoomToFile(room, filename);
                loadRoom(room);
                return;
            }
        } while (!isValidStudentId(studentId, room));
        strcpy(room->seats[seat], studentId);
   }
}

int isValidStudentId(char *studentId, Room *room) {
    char *initialPointerPosition = studentId;
    char c;
    while((c = *initialPointerPosition++) != '\0') {
        if (c == '-' || c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == ',')
            return 0;

    }
    SeatsInUse *seatsInUse = getSeatsInUse(room);
    for (int i = 0; i < seatsInUse->size; i++) {
        if (strcmp(seatsInUse->seats[i].studentId, studentId) == 0) {
            printf("  studentId \"%s\" already in use\n", studentId);
            free(seatsInUse->seats);
            free(seatsInUse);
            return 0;
        }
    }
    free(seatsInUse->seats);
    free(seatsInUse);
    return 1;
}