#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "room.h"
#include "enterStudents.h"

void saveRoomToFile(Room *room) {
    char filename[123];
    do {
        printf("enter filename: ");
        scanf("%s", filename);
        if (strcmp(filename, "-abort") == 0) {
            exit(0);
        }
    } while(strlen(filename) < 1);
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

int isValidRoomFile(char *fileName) {
    //implementation
    return 1;
}

Room *loadRoomFromFile() {
    char filename[123];
    do {
        printf("enter filename: ");
        scanf("%s", filename);
        if (strcmp(filename, "-abort") == 0) {
            exit(0);
        }
    } while(!isValidRoomFile(filename));
    FILE *file = fopen(filename, "r");
    char fileContent[123456]; 
    fgets(fileContent, 123456, file);
    fclose(file);
    //implementation
    return NULL;
}

void printRoomLayout(Room *room) {
      for (int i = 0; i < room->rows; i++) {
        for (int j = 0; j < room->cols; j++) {
            printf("%c", '[');
            if (!isValidPlace(room, i, j)) {
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
    free(room->seats);
}