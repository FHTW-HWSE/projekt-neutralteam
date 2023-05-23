#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "directNeighbors.hpp"
#include "indirectNeighbors.hpp"
#include "seat.hpp"
#include "room.hpp"

void printSeats(Room *room, Seats *seats) {
    for (int i = 0; i < seats->size; i++) {
        printf("%d: %s\n", seats->seats[i].row*room->cols+seats->seats[i].col, seats->seats[i].studentId);
    }
}

int isValidSeatNumber(Room *room, int seatNumber) {
    int row = seatNumber / room->cols;
    int col = seatNumber % room->cols;
    if (row < 0 || row >= room->rows) {
        return 0;
    }
    if (col < 0 || col >= room->cols) {
        return 0;
    }
    switch(room->layout) {
    case 1:
        return 1;
    case 2:
        return (row % 2 == 0 && col % 2 == 0) || (row % 2 == 1 && col % 2 == 1);
    case 3:
        return row % 2 == 0 && col % 2 == 0;
    default:
        return 0;
    }
}

Seats *getSeatsInUse(Room *room) {
    Seats *seatsInUse = (Seats*)malloc(sizeof(Seats));
    seatsInUse->size = 0;
    seatsInUse->seats = (Seat*)malloc(sizeof(Seat) * room->rows*room->cols);
    for (int i = 0; i < room->rows*room->cols; i++) {
        if (isValidSeatNumber(room, i)) {
            if (strlen(room->seats[i]) > 0) {
                addSeat(seatsInUse, i / room->cols, i % room->cols, room->seats[i]);
            }
        }
    }
    return seatsInUse;
}

Seats *getAllSeats(Room *room) {
    Seats *allSeats = (Seats*)malloc(sizeof(Seats));
    allSeats->size = 0;
    allSeats->seats = (Seat*)malloc(sizeof(Seat) * room->rows*room->cols);
    for (int i = 0; i < room->rows*room->cols; i++) {
        if (isValidSeatNumber(room, i)) {
            addSeat(allSeats, i / room->cols, i % room->cols, room->seats[i]);
        }
    }
    return allSeats;
}

Seats *getDirectNeighborSeats(Room *room, int seatNumber) {
    Seats *directNeighborSeats = (Seats*)malloc(sizeof(Seats));
    directNeighborSeats->size = 0;
    directNeighborSeats->seats = (Seat*)malloc(sizeof(Seat) * 8);
    
    int topSeat = getTopSeat(room, seatNumber);
    if (topSeat != -1) {
        addSeat(directNeighborSeats, topSeat / room->cols, topSeat % room->cols, room->seats[topSeat]);
    }
    int topRightSeat = getTopRightSeat(room, seatNumber);
    if (topRightSeat != -1) {
        addSeat(directNeighborSeats, topRightSeat / room->cols, topRightSeat % room->cols, room->seats[topRightSeat]);
    }
    int rightSeat = getRightSeat(room, seatNumber);
    if (rightSeat != -1) {
        addSeat(directNeighborSeats, rightSeat / room->cols, rightSeat % room->cols, room->seats[rightSeat]);
    }
    int bottomRightSeat = getBottomRightSeat(room, seatNumber);
    if (bottomRightSeat != -1) {
        addSeat(directNeighborSeats, bottomRightSeat / room->cols, bottomRightSeat % room->cols, room->seats[bottomRightSeat]);
    }
    int bottomSeat = getBottomSeat(room, seatNumber);
    if (bottomSeat != -1) {
        addSeat(directNeighborSeats, bottomSeat / room->cols, bottomSeat % room->cols, room->seats[bottomSeat]);
    }
    int bottomLeftSeat = getBottomLeftSeat(room, seatNumber);
    if (bottomLeftSeat != -1) {
        addSeat(directNeighborSeats, bottomLeftSeat / room->cols, bottomLeftSeat % room->cols, room->seats[bottomLeftSeat]);
    }
    int leftSeat = getLeftSeat(room, seatNumber);
    if (leftSeat != -1) {
        addSeat(directNeighborSeats, leftSeat / room->cols, leftSeat % room->cols, room->seats[leftSeat]);
    }
    int topLeftSeat = getTopLeftSeat(room, seatNumber);
    if (topLeftSeat != -1) {
        addSeat(directNeighborSeats, topLeftSeat / room->cols, topLeftSeat % room->cols, room->seats[topLeftSeat]);
    }
    return directNeighborSeats;
}

Seats *getIndirectNeighborSeats(Room *room, int seatNumber) {
    Seats *indirectNeighborSeats = (Seats*)malloc(sizeof(Seats));
    indirectNeighborSeats->size = 0;
    indirectNeighborSeats->seats = (Seat*)malloc(sizeof(Seat) * 16);

    int topTopSeat = getTopTopSeat(room, seatNumber);
    if (topTopSeat != -1) {
        addSeat(indirectNeighborSeats, topTopSeat / room->cols, topTopSeat % room->cols, room->seats[topTopSeat]);
    }
    int topTopRightSeat = getTopTopRightSeat(room, seatNumber);
    if (topTopRightSeat != -1) {
        addSeat(indirectNeighborSeats, topTopRightSeat / room->cols, topTopRightSeat % room->cols, room->seats[topTopRightSeat]);
    }
    int topRightRightSeat = getTopRightRightSeat(room, seatNumber);
    if (topRightRightSeat != -1) {
        addSeat(indirectNeighborSeats, topRightRightSeat / room->cols, topRightRightSeat % room->cols, room->seats[topRightRightSeat]);
    }
    int rightRightSeat = getRightRightSeat(room, seatNumber);
    if (rightRightSeat != -1) {
        addSeat(indirectNeighborSeats, rightRightSeat / room->cols, rightRightSeat % room->cols, room->seats[rightRightSeat]);
    }
    int bottomRightRightSeat = getBottomRightRightSeat(room, seatNumber);
    if (bottomRightRightSeat != -1) {
        addSeat(indirectNeighborSeats, bottomRightRightSeat / room->cols, bottomRightRightSeat % room->cols, room->seats[bottomRightRightSeat]);
    }
    int bottomBottomRightSeat = getBottomBottomRightSeat(room, seatNumber);
    if (bottomBottomRightSeat != -1) {
        addSeat(indirectNeighborSeats, bottomBottomRightSeat / room->cols, bottomBottomRightSeat % room->cols, room->seats[bottomBottomRightSeat]);
    }
    int bottomBottomSeat = getBottomBottomSeat(room, seatNumber);
    if (bottomBottomSeat != -1) {
        addSeat(indirectNeighborSeats, bottomBottomSeat / room->cols, bottomBottomSeat % room->cols, room->seats[bottomBottomSeat]);
    }
    int bottomBottomLeftSeat = getBottomBottomLeftSeat(room, seatNumber);
    if (bottomBottomLeftSeat != -1) {
        addSeat(indirectNeighborSeats, bottomBottomLeftSeat / room->cols, bottomBottomLeftSeat % room->cols, room->seats[bottomBottomLeftSeat]);
    }
    int bottomLeftLeftSeat = getBottomLeftLeftSeat(room, seatNumber);
    if (bottomLeftLeftSeat != -1) {
        addSeat(indirectNeighborSeats, bottomLeftLeftSeat / room->cols, bottomLeftLeftSeat % room->cols, room->seats[bottomLeftLeftSeat]);
    }
    int leftLeftSeat = getLeftLeftSeat(room, seatNumber);
    if (leftLeftSeat != -1) {
        addSeat(indirectNeighborSeats, leftLeftSeat / room->cols, leftLeftSeat % room->cols, room->seats[leftLeftSeat]);
    }
    int topLeftLeftSeat = getTopLeftLeftSeat(room, seatNumber);
    if (topLeftLeftSeat != -1) {
        addSeat(indirectNeighborSeats, topLeftLeftSeat / room->cols, topLeftLeftSeat % room->cols, room->seats[topLeftLeftSeat]);
    }
    int topTopLeftSeat = getTopTopLeftSeat(room, seatNumber);
    if (topTopLeftSeat != -1) {
        addSeat(indirectNeighborSeats, topTopLeftSeat / room->cols, topTopLeftSeat % room->cols, room->seats[topTopLeftSeat]);
    }
    return indirectNeighborSeats;
}

void addSeat(Seats *seats, int row, int col, char *studentId) {
    seats->seats[seats->size].row = row;
    seats->seats[seats->size].col = col;
    seats->seats[seats->size].studentId = studentId;
    seats->size++;
}
