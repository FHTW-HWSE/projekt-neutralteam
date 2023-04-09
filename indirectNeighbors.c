#include <stdio.h>
#include <string.h>

#include "indirectNeighbors.h"

int getTopTopLeftLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1 && col > 1) {
        return (row-2)*room->cols + (col-2);
    } 
    return -1;
}
int getTopTopLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1 && col > 0) {
        return (row-2)*room->cols + (col-1);
    }  
    return -1;
}
int getTopTopSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1) {
        return (row-2)*room->cols + col;
    } 
    return -1;
}
int getTopTopRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1 && col < room->cols-1) {
        return (row-2)*room->cols + (col+1);
    } 
    return -1;
}
int getTopTopRightRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1 && col < room->cols-2) {
        return (row-2)*room->cols + (col+2);
    } else {
        return -1;
    }
}
int getTopRightRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0 && col < room->cols-2) {
        return (row-1)*room->cols + (col+2);
    } 
    return -1;
}
int getRightRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (col < room->cols-2) {
        return row*room->cols + (col+2);
    } 
    return -1;
}
int getBottomRightRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1 && col < room->cols-2) {
        return (row+1)*room->cols + (col+2);
    } 
    return -1;
}
int getBottomBottomRightRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2 && col < room->cols-2) {
        return (row+2)*room->cols + (col+2);
    } 
    return -1;
}
int getBottomBottomRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2 && col < room->cols-1) {
        return (row+2)*room->cols + (col+1);
    } 
    return -1;
}
int getBottomBottomSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2) {
        return (row+2)*room->cols + col;
    } 
    return -1;
}
int getBottomBottomLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2 && col > 0) {
        return (row+2)*room->cols + (col-1);
    } 
    return -1;
}
int getBottomBottomLeftLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2 && col > 1) {
        return (row+2)*room->cols + (col-2);
    } 
    return -1;
}
int getBottomLeftLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1 && col > 1) {
        return (row+1)*room->cols + (col-2);
    } 
    return -1;
}
int getLeftLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (col > 1) {
        return row*room->cols + (col-2);
    } 
    return -1;
}
int getTopLeftLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0 && col > 1) {
        return (row-1)*room->cols + (col-2);
    } 
    return -1;
}