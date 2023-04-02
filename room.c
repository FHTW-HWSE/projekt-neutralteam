#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "room.h"
#include "main.h"

void saveRoomToFile(Room *room) {
    char filename[MAGIC_NUMBER];
    do {
        printf("enter filename: ");
        scanf("%s", filename);
        if (strcmp(filename, "-abort") == 0) {
            freeRoom(room);
            exit(0);
        }
    } while(!isValidRoomFileName(filename));
    FILE *file = fopen(filename, "w");
    fprintf(file, "%d,%d,%d", room->rows, room->cols, room->layout);
    for (int i = 0; i < room->rows; i++) {
        for (int j = 0; j < room->cols; j++) {
            if(strlen(room->seats[i*room->cols+j]) > 0) {
                fprintf(file, ",%d:%s", i*room->cols+j, room->seats[i*room->cols+j]);
            }
        }
    }
    fclose(file);
}

Room *loadRoomFromFile() {
    char filename[MAGIC_NUMBER];
    Room *room = NULL;
    do {
        printf("enter filename: ");
        scanf("%s", filename);
        if (strcmp(filename, "-abort") == 0) {
            exit(0);
        }
    } while((room = roomFromFile(filename)) == NULL);
    return room;
}

void printRoomLayout(Room *room) {
      for (int i = 0; i < room->rows; i++) {
        for (int j = 0; j < room->cols; j++) {
            printf("%c", '[');
            if (!isValidSeat(room, i*room->cols+j)) {
                printf("%c", ' ');
            } else {
                printf("%c", 'X');
            }
            printf("%c", ']');
        }
        printf("\n");
    }
}

void freeRoom(Room *room) {
    for (int i = 0; i < room->rows*room->cols; i++) {
        free(room->seats[i]);
    }
    free(room->seats);
    free(room);
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
        break;
    case 2:
        if ( (row % 2 == 0 && col % 2 == 0) || (row % 2 == 1 && col % 2 == 1) ) {
            return 1;
        } else {
            return 0;
        }
        break;
    case 3:
        if (row % 2 == 0 && col % 2 == 0) {
            return 1;
        } else {
            return 0;
        }
        break;
    }
    return 0;
}

int isValidRoomFileName(char *fileName) {
    char c;
    while((c = *fileName++) != '\0') {
        if (c == '.' || c == '/' || c == '\\')
            return 0;
    }
    return 1;
}

Room *roomFromFile(char *fileName) {
    if (!isValidRoomFileName(fileName)) {
        printf("invalid filename\n");
        return NULL;
    }
    FILE *file = fopen(fileName, "r");
    Room *room =  malloc(sizeof(Room));
    if (file == NULL) {
        printf("file not found\n");
        return NULL;
    }
    char fileContent[MORE_MAGICAL_NUMBER];
    fgets(fileContent, MORE_MAGICAL_NUMBER, file);
    fclose(file);
    char **substrings = malloc(sizeof(char*) * MORE_MAGICAL_NUMBER);
    int substringCount = 0;
    char *substring = strtok(fileContent, ",");
    while (substring != NULL) {
        substrings[substringCount++] = substring;
        substring = strtok(NULL, ",");
    }
    if (substringCount < 3) {
        printf("invalid file format\n");
        return NULL;
    }
    room->rows = atoi(substrings[0]);
    room->cols = atoi(substrings[1]);
    room->layout = atoi(substrings[2]);
    room->seats = malloc(sizeof(char*) * room->rows * room->cols);
    for (int i = 0; i < room->rows*room->cols; i++) {
        room->seats[i] = malloc(sizeof(char) * MAGIC_NUMBER);
        room->seats[i][0] = '\0';
    }
    for (int i = 3; i < substringCount; i++) {
        char *seatString = substrings[i];
        char *name = strchr(seatString, ':');
        if (name == NULL) {
            printf("invalid file format\n");
            return NULL;
        }
        *name = '\0';
        name++;
        int seat = atoi(seatString);
        if (!isValidSeat(room, seat)) {
            printf("invalid file format\n");
            return NULL;
        }
        strcpy(room->seats[seat], name);
    }
    free(substrings);
    return room;
}