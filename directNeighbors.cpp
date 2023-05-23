#include <stdio.h>
#include <string.h>

#include "directNeighbors.hpp"

int getTopLeftSeat(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 0 && col > 0 ? (row-1)*room->cols + (col-1) : -1;
}
int getTopSeat(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 0 ? (row-1)*room->cols + col : -1;
}
int getTopRightSeat(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 0 && col < room->cols-1 ? (row-1)*room->cols + (col+1) : -1;
}
int getRightSeat(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return col < room->cols-1 ? row*room->cols + (col+1) : -1;
}
int getBottomRightSeat(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-1 && col < room->cols-1 ? (row+1)*room->cols + (col+1) : -1;
}
int getBottomSeat(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-1 ? (row+1)*room->cols + col : -1;
}
int getBottomLeftSeat(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-1 && col > 0 ? (row+1)*room->cols + (col-1) : -1;
}
int getLeftSeat(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return col > 0 ? row*room->cols + (col-1) : -1;
}