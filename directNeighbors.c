#include <stdio.h>
#include <string.h>

#include "directNeighbors.h"

int getTopLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0 && col > 0) {
        return (row-1)*room->cols + (col-1);
    }
    return -1;
}
int getTopSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0) {
        return (row-1)*room->cols + col;
    }
    return -1;
}
int getTopRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0 && col < room->cols-1) {
        return (row-1)*room->cols + (col+1);
    }
    return -1;
}
int getRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (col < room->cols-1) {
        return row*room->cols + (col+1);
    }
    return -1;
}
int getBottomRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1 && col < room->cols-1) {
        return (row+1)*room->cols + (col+1);
    }
    return -1;
}
int getBottomSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1) {
        return (row+1)*room->cols + col;
    }
    return -1;
}
int getBottomLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1 && col > 0) {
        return (row+1)*room->cols + (col-1);
    }
    return -1;
}
int getLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (col > 0) {
        return row*room->cols + (col-1);
    }
    return -1;
}