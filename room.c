#include <stdio.h>
#include <string.h>

#include "room.h"

void saveRoomToFile(Room room) {

}

void printRoom(Room room) {
      for (int i = 0; i < room.rows; i++) {
        for (int j = 0; j < room.cols; j++) {
            printf("%c", '[');
            if (strcmp(room.seats[i*room.cols+j], ":") == 0) {
                printf("%c", ' ');
            } else {
                printf("%c", 'X');
            }
            printf("%c", ']');
        }
        printf("\n");
    }
}

void freeRoom(Room room) {
    free(room.seats);
}