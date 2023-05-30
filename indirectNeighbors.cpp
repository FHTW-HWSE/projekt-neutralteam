#include <stdio.h>
#include <string.h>

#include "indirectNeighbors.hpp"

int getTopTopLeftLeftSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 1 && col > 1 ? (row-2)*room->cols + (col-2) : -1;
}
int getTopTopLeftSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 1 && col > 0 ? (row-2)*room->cols + (col-1) : -1;
}
int getTopTopSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 1 ? (row-2)*room->cols + col : -1;
}
int getTopTopRightSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 1 && col < room->cols-1 ? (row-2)*room->cols + (col+1) : -1;
}
int getTopTopRightRightSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 1 && col < room->cols-2 ? (row-2)*room->cols + (col+2) : -1;
}
int getTopRightRightSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 0 && col < room->cols-2 ? (row-1)*room->cols + (col+2) : -1;
}
int getRightRightSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return col < room->cols-2 ? row*room->cols + (col+2) : -1;
}
int getBottomRightRightSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-1 && col < room->cols-2 ? (row+1)*room->cols + (col+2) : -1;
}
int getBottomBottomRightRightSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-2 && col < room->cols-2 ? (row+2)*room->cols + (col+2) : -1;
}
int getBottomBottomRightSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-2 && col < room->cols-1 ? (row+2)*room->cols + (col+1) : -1;
}
int getBottomBottomSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-2 ? (row+2)*room->cols + col : -1;
}
int getBottomBottomLeftSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-2 && col > 0 ? (row+2)*room->cols + (col-1) : -1;
}
int getBottomBottomLeftLeftSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-2 && col > 1 ? (row+2)*room->cols + (col-2) : -1;
}
int getBottomLeftLeftSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row < room->rows-1 && col > 1 ? (row+1)*room->cols + (col-2) : -1;
}
int getLeftLeftSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return col > 1 ? row*room->cols + (col-2) : -1;
}
int getTopLeftLeftSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    return row > 0 && col > 1 ? (row-1)*room->cols + (col-2) : -1;
}