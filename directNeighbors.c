#include <stdio.h>
#include <string.h>

#include "directNeighbors.h"

void printTopLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0 && col > 0) {
        int topLeftSeat = (row-1)*room->cols + (col-1);
        if (isValidSeat(room, topLeftSeat)) {
            if (strlen(room->seats[topLeftSeat]) > 0) {
                printf("%s: %d\n", room->seats[topLeftSeat], topLeftSeat);
            }
        }
    }
}
void printTopSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0) {
        int topSeat = (row-1)*room->cols + col;
        if (isValidSeat(room, topSeat)) {
            if (strlen(room->seats[topSeat]) > 0) {
                printf("%s: %d\n", room->seats[topSeat], topSeat);
            }
        }
    }
}
void printTopRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0 && col < room->cols-1) {
        int topRightSeat = (row-1)*room->cols + (col+1);
        if (isValidSeat(room, topRightSeat)) {
            if (strlen(room->seats[topRightSeat]) > 0) {
                printf("%s: %d\n", room->seats[topRightSeat], topRightSeat);
            }
        }
    }
}
void printRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (col < room->cols-1) {
        int rightSeat = row*room->cols + (col+1);
        if (isValidSeat(room, rightSeat)) {
            if (strlen(room->seats[rightSeat]) > 0) {
                printf("%s: %d\n", room->seats[rightSeat], rightSeat);
            }
        }
    }
}
void printBottomRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1 && col < room->cols-1) {
        int bottomRightSeat = (row+1)*room->cols + (col+1);
        if (isValidSeat(room, bottomRightSeat)) {
            if (strlen(room->seats[bottomRightSeat]) > 0) {
                printf("%s: %d\n", room->seats[bottomRightSeat], bottomRightSeat);
            }
        }
    }
}
void printBottomSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1) {
        int bottomSeat = (row+1)*room->cols + col;
        if (isValidSeat(room, bottomSeat)) {
            if (strlen(room->seats[bottomSeat]) > 0) {
                printf("%s: %d\n", room->seats[bottomSeat], bottomSeat);
            }
        }
    }
}
void printBottomLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1 && col > 0) {
        int bottomLeftSeat = (row+1)*room->cols + (col-1);
        if (isValidSeat(room, bottomLeftSeat)) {
            if (strlen(room->seats[bottomLeftSeat]) > 0) {
                printf("%s: %d\n", room->seats[bottomLeftSeat], bottomLeftSeat);
            }
        }
    }
}
void printLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (col > 0) {
        int leftSeat = row*room->cols + (col-1);
        if (isValidSeat(room, leftSeat)) {
            if (strlen(room->seats[leftSeat]) > 0) {
                printf("%s: %d\n", room->seats[leftSeat], leftSeat);
            }
        }
    }
}