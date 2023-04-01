#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "room.h"

void saveRoomToFile(Room *room) {

}

Room *loadRoomFromFile() {
    return NULL;
}

void printRoom(Room *room) {
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

int isValidPlace(Room *room, int row, int col) {
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
}