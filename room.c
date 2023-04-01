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
    } while(!isValidRoomFile(filename));
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
    do {
        printf("enter filename: ");
        scanf("%s", filename);
        if (strcmp(filename, "-abort") == 0) {
            exit(0);
        }
    } while(!isValidRoomFile(filename));
    FILE *file = fopen(filename, "r");
    char fileContent[MORE_MAGICAL_NUMBER]; 
    fgets(fileContent, MORE_MAGICAL_NUMBER, file);
    fclose(file);
    //implementation
    return NULL;
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

int isValidRoomFile(char *fileName) {
    //implementation
    return 1;
}