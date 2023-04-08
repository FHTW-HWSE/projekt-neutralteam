#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "room.h"
#include "main.h"

Room *loadRoomFromFile(char *fileName) {
    char *fileContent = getFileContent(fileName);
    if (fileContent == NULL) {
        printf("file not found\n");
        return NULL;
    }
    Room *room = malloc(sizeof(Room));
    char **fileContentSubstrings = malloc(sizeof(char*) * MORE_MAGICAL_NUMBER);
    int substringCount = 0;
    char *substring = strtok(fileContent, ",");
    while (substring != NULL) {
        fileContentSubstrings[substringCount++] = substring;
        substring = strtok(NULL, ",");
    }
    if (substringCount < 3) {
        printf("invalid file format\n");
        free(fileContentSubstrings);
        freeRoom(room);
        return NULL;
    }
    room->rows = atoi(fileContentSubstrings[0]);
    room->cols = atoi(fileContentSubstrings[1]);
    room->layout = atoi(fileContentSubstrings[2]);
    room->seats = malloc(sizeof(char*) * room->rows * room->cols);
    for (int i = 0; i < room->rows*room->cols; i++) {
        room->seats[i] = malloc(sizeof(char) * MAGIC_NUMBER);
        room->seats[i][0] = '\0';
    }
    for (int i = 3; i < substringCount; i++) {
        char *seatString = fileContentSubstrings[i];
        char *name = strchr(seatString, ':');
        if (name == NULL) {
            printf("invalid file format\n");
            free(fileContentSubstrings);
            freeRoom(room);
            return NULL;
        }
        *name = '\0';
        name++;
        int seat = atoi(seatString);
        if (!isValidSeat(room, seat)) {
            printf("invalid file format\n");
            free(fileContentSubstrings);
            freeRoom(room);
            return NULL;
        }
        strcpy(room->seats[seat], name);
    }
    free(fileContentSubstrings);
    free(fileContent);
    return room;
}

void saveRoomToFile(Room *room, char *fileName) {
    FILE *file = fopen(fileName, "w");
    char *roomString = roomToString(room);
    fprintf(file, "%s", roomString);
    free(roomString);
    fclose(file);
}

void printSeatsInUse(Room *room) {
    SeatsInUse *seatsInUse = getSeatsInUse(room);
    for (int i = 0; i < seatsInUse->size; i++) {
        printf("%d: %s\n", seatsInUse->seats[i].row*room->cols+seatsInUse->seats[i].col, seatsInUse->seats[i].studentId);
    }
    free(seatsInUse->seats);
    free(seatsInUse);
}

void printRoomLayout(Room *room) {
    char *roomLayoutString = getRoomLayoutString(room);
    printf("%s", roomLayoutString);
    free(roomLayoutString);
}

void freeRoom(Room *room) {
    for (int i = 0; i < room->rows*room->cols; i++) {
        free(room->seats[i]);
    }
    free(room->seats);
    free(room);
}



char *roomToString(Room *room) {
    char *roomString = malloc(sizeof(char) * MORE_MAGICAL_NUMBER);
    sprintf(roomString, "%d,%d,%d", room->rows, room->cols, room->layout);
    for (int i = 0; i < room->rows; i++) {
        for (int j = 0; j < room->cols; j++) {
            if(strlen(room->seats[i*room->cols+j]) > 0) {
                char *seatString = malloc(sizeof(char) * MORE_MAGICAL_NUMBER);
                sprintf(seatString, ",%d:%s", i*room->cols+j, room->seats[i*room->cols+j]);
                strcat(roomString, seatString);
                free(seatString);
            }
        }
    }
    return roomString;
}

char *getRoomLayoutString(Room *room) {
    char *roomLayoutString = malloc(sizeof(char) * MORE_MAGICAL_NUMBER);
    int currentIndex = 0;
    for (int i = 0; i < room->rows; i++) {
        for (int j = 0; j < room->cols; j++) {
            if (!isValidSeat(room, i*room->cols+j)) {
                roomLayoutString[currentIndex++] = ' ';
            } else {
                roomLayoutString[currentIndex++] = 'X';
            }
        }
        roomLayoutString[currentIndex++] = '\n';
    }
    roomLayoutString[currentIndex] = '\0';
    return roomLayoutString;
}

int isValidSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < 0 || row >= room->rows) {
        return 0;
    }
    if (col < 0 || col >= room->cols) {
        return 0;
    }
    switch(room->layout) {
    case 1:
        return 1;
    case 2:
        return (row % 2 == 0 && col % 2 == 0) || (row % 2 == 1 && col % 2 == 1);
    case 3:
        return row % 2 == 0 && col % 2 == 0;
    default:
        return 0;
    }
}

SeatsInUse *getSeatsInUse(Room *room) {
    SeatsInUse *studentIds = malloc(sizeof(SeatsInUse));
    studentIds->size = 0;
    studentIds->seats = malloc(sizeof(Seat) * room->rows*room->cols);
    for (int i = 0; i < room->rows*room->cols; i++) {
        if (isValidSeat(room, i)) {
            if (strlen(room->seats[i]) > 0) {
                studentIds->seats[studentIds->size].row = i / room->cols;
                studentIds->seats[studentIds->size].col = i % room->cols;
                studentIds->seats[studentIds->size].studentId = room->seats[i];
                studentIds->size++;
            }
        }
    }
    return studentIds;
}

int isValidRoomFileName(char *fileName) {
    char c;
    while((c = *fileName++) != '\0') {
        if (c == '.' || c == '/' || c == '\\')
            return 0;
    }
    return 1;
}

char *getFileContent(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }
    char *fileContent = malloc(sizeof(char) * MORE_MAGICAL_NUMBER);
    fgets(fileContent, MORE_MAGICAL_NUMBER, file);
    fclose(file);
    return fileContent;
}