#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "enterStudents.hpp"
#include "loadRoom.hpp"
#include "room.hpp"
#include "main.hpp"

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
        char seatString[SMALL_MAGIC_NUMBER] = "";
        do {
            printf("enter seat: ");
            scanf("%s", seatString);
            if (strcmp(seatString, END_PROGRAM_KEYWORD) == 0) {
                freeRoom(room);
                exit(0);
            }
            if (strcmp(seatString, "-save") == 0) {
                char filename[SMALL_MAGIC_NUMBER];
                do {
                    printf("enter filename: ");
                    scanf("%s", filename);
                    if (strcmp(filename, END_PROGRAM_KEYWORD) == 0) {
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
        char studentId[SMALL_MAGIC_NUMBER] = "";
        while(1) {
            printf("enter student id: ");
            scanf("%s", studentId);
            if (strcmp(studentId, END_PROGRAM_KEYWORD) == 0) {
                freeRoom(room);
                exit(0);
            }
            if (strcmp(studentId, "-save") == 0) {
                char filename[SMALL_MAGIC_NUMBER];
                do {
                    printf("enter filename: ");
                    scanf("%s", filename);
                    if (strcmp(filename, END_PROGRAM_KEYWORD) == 0) {
                        freeRoom(room);
                        exit(0);
                    }
                } while(!isValidRoomFileName(filename));
                saveRoomToFile(room, filename);
                loadRoom(room);
                return;
            }
            if (strcmp(studentId, "-abort") == 0) {
                break;
            }
            if (isValidStudentId(studentId)) {
                for (int i = 0; i < room->rows*room->cols; i++) {
                    if (strcmp(room->seats[i], studentId) == 0) {
                        room->seats[i][0] = '\0';
                    }
                }
                strcpy(room->seats[seat], studentId);
                break;
            }
        }
   }
}

int isValidStudentId(char *studentId) {
    char c;
    while((c = *studentId++) != '\0') {
        if (c == '\t' || c == '\n' || c == '\r' || c == ',' || c == ':')
            return 0;

    }
    return 1;
}


int isValidRoomFileName(char * fileName) {
    char c;
    if (strcmp(fileName, ".") == 0 || strcmp(fileName, "..") == 0) {
        return 0;
    }
    while((c = *fileName++) != '\0') {
        if (! (c == '.' || isalnum(c)) ) 
            return 0;
    }
    return 1;
}