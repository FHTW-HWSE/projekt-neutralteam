#include <stdio.h>
#include <string.h>

#include "directNeighbors.hpp"

int getTopLeftSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 0 && col > 0 ? (row-1)*room->cols + (col-1) : -1;
}
int getTopSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 0 ? (row-1)*room->cols + col : -1;
}
int getTopRightSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 0 && col < room->cols-1 ? (row-1)*room->cols + (col+1) : -1;
}
int getRightSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return col < room->cols-1 ? row*room->cols + (col+1) : -1;
}
int getBottomRightSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-1 && col < room->cols-1 ? (row+1)*room->cols + (col+1) : -1;
}
int getBottomSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-1 ? (row+1)*room->cols + col : -1;
}
int getBottomLeftSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-1 && col > 0 ? (row+1)*room->cols + (col-1) : -1;
}
int getLeftSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return col > 0 ? row*room->cols + (col-1) : -1;
}