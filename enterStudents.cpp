#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "enterStudents.hpp"
#include "room.hpp"
#include "seat.hpp"
#include "loadRoom.hpp"
#include "main.hpp"

void enterStudents(Room *room) {
    printf("\nentering students\n");
    printf("\nconfirm with -save\n");
    while(1) {
        printf("\nvalid seats:\n");
        Seats *allSeats = getAllSeats(room);
        printSeats(room, allSeats);
        free(allSeats->seats);
        free(allSeats);

        int seatNumber = 0;
        char seatString[MAX_UIMENU_SELECTION_LENGTH] = "";
        do {
            printf("enter seat: ");
            scanf("%s", seatString);
            if (strcmp(seatString, END_PROGRAM_KEYWORD) == 0) {
                freeRoom(room);
                exit(0);
            }
            if (strcmp(seatString, "-save") == 0) {
                char filename[MAX_FILENAME_LENGTH+1];
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
            seatNumber = atoi(seatString);
        } while (!isValidSeatNumber(room, seatNumber));

        char studentId[MAX_STUDENTID_LENGTH+1];
        do {
            printf("enter student id: ");
            scanf("%s", studentId);
            if (strcmp(studentId, END_PROGRAM_KEYWORD) == 0) {
                freeRoom(room);
                exit(0);
            }
            if (strcmp(studentId, "-save") == 0) {
                char filename[MAX_FILENAME_LENGTH+1];
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
        } while(!isValidStudentId(studentId));

        writeStudentIdToSeatNumber(studentId, room, seatNumber);
   }
}

void writeStudentIdToSeatNumber(char studentId[MAX_STUDENTID_LENGTH+1], Room *room, int seatNumber) {
    if (!isValidStudentId(studentId) || !isValidSeatNumber(room, seatNumber)) {
        printf("invalid student id\n");
        return;
    }
    for (int i = 0; i < room->rows*room->cols; i++) {
        if (strcmp(room->seats[i], studentId) == 0) {
            room->seats[i][0] = '\0';
        }
    }
    strcpy(room->seats[seatNumber], studentId);
}

int isValidStudentId(const char *studentId) {
    char *p = (char*)studentId;
    char c;
    while((c = *p++) != '\0') {
        if (c == '\t' || c == '\n'|| c == ',' || c == ':')
            return 0;

    }
    if (strlen(studentId) == 0 || strlen(studentId) > MAX_STUDENTID_LENGTH) { 
        return 0;
    }
    return 1;
}

int isValidRoomFileName(const char *fileName) {
    int i = 0;
    char c;
    if (fileName == NULL) {
        return 0;
    }
    if (fileName[0] == '\0') {
        return 0;
    }
    if (strlen(fileName) > MAX_FILENAME_LENGTH) {
        return 0;
    }
    if (fileName[0] == '/' || fileName[0] == '\\') {
        return 0;
    }
    if (fileName[0] == '.' && (fileName[1] == '\0' || fileName[1] == '/' || fileName[1] == '\\') ) {
        return 0;
    }
    if (fileName[0] == '.' && fileName[1] == '.' && (fileName[2] == '\0' || fileName[2] == '/' || fileName[2] == '\\') ) {
        return 0;
    }
    return 1;
}