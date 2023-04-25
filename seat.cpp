#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "directNeighbors.hpp"
#include "indirectNeighbors.hpp"
#include "seat.hpp"
#include "room.hpp"

int isValidSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
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

void printSeats(Room *room, Seats *seats) {
    for (int i = 0; i < seats->size; i++) {
        printf("%d: %s\n", seats->seats[i].row*room->cols+seats->seats[i].col, seats->seats[i].studentId);
    }
}

Seats *getSeatsInUse(Room *room) {
    Seats *seatsInUse = (Seats*)malloc(sizeof(Seats));
    seatsInUse->size = 0;
    seatsInUse->seats = (Seat*)malloc(sizeof(Seat) * room->rows*room->cols);
    for (int i = 0; i < room->rows*room->cols; i++) {
        if (isValidSeat(room, i)) {
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
        if (isValidSeat(room, i)) {
            addSeat(allSeats, i / room->cols, i % room->cols, room->seats[i]);
        }
    }
    return allSeats;
}

Seats *getDirectNeighborSeats(Room *room, int seat) {
    Seats *directNeighborSeats = (Seats*)malloc(sizeof(Seats));
    directNeighborSeats->size = 0;
    directNeighborSeats->seats = (Seat*)malloc(sizeof(Seat) * 8);
    
    int topSeat = getTopSeat(room, seat);
    if (topSeat != -1) {
        addSeat(directNeighborSeats, topSeat / room->cols, topSeat % room->cols, room->seats[topSeat]);
    }
    int topRightSeat = getTopRightSeat(room, seat);
    if (topRightSeat != -1) {
        addSeat(directNeighborSeats, topRightSeat / room->cols, topRightSeat % room->cols, room->seats[topRightSeat]);
    }
    int rightSeat = getRightSeat(room, seat);
    if (rightSeat != -1) {
        addSeat(directNeighborSeats, rightSeat / room->cols, rightSeat % room->cols, room->seats[rightSeat]);
    }
    int bottomRightSeat = getBottomRightSeat(room, seat);
    if (bottomRightSeat != -1) {
        addSeat(directNeighborSeats, bottomRightSeat / room->cols, bottomRightSeat % room->cols, room->seats[bottomRightSeat]);
    }
    int bottomSeat = getBottomSeat(room, seat);
    if (bottomSeat != -1) {
        addSeat(directNeighborSeats, bottomSeat / room->cols, bottomSeat % room->cols, room->seats[bottomSeat]);
    }
    int bottomLeftSeat = getBottomLeftSeat(room, seat);
    if (bottomLeftSeat != -1) {
        addSeat(directNeighborSeats, bottomLeftSeat / room->cols, bottomLeftSeat % room->cols, room->seats[bottomLeftSeat]);
    }
    int leftSeat = getLeftSeat(room, seat);
    if (leftSeat != -1) {
        addSeat(directNeighborSeats, leftSeat / room->cols, leftSeat % room->cols, room->seats[leftSeat]);
    }
    int topLeftSeat = getTopLeftSeat(room, seat);
    if (topLeftSeat != -1) {
        addSeat(directNeighborSeats, topLeftSeat / room->cols, topLeftSeat % room->cols, room->seats[topLeftSeat]);
    }
   
    
}

Seats *getIndirectNeighborSeats(Room *room, int seat) {
     Seats *directNeighborSeats = (Seats*)malloc(sizeof(Seats));
    directNeighborSeats->size = 0;
    directNeighborSeats->seats = (Seat*)malloc(sizeof(Seat) * 16);

    int topTopSeat = getTopTopSeat(room, seat);
    if (topTopSeat != -1) {
        addSeat(directNeighborSeats, topTopSeat / room->cols, topTopSeat % room->cols, room->seats[topTopSeat]);
    }
    int topTopRightSeat = getTopTopRightSeat(room, seat);
    if (topTopRightSeat != -1) {
        addSeat(directNeighborSeats, topTopRightSeat / room->cols, topTopRightSeat % room->cols, room->seats[topTopRightSeat]);
    }
    int topRightRightSeat = getTopRightRightSeat(room, seat);
    if (topRightRightSeat != -1) {
        addSeat(directNeighborSeats, topRightRightSeat / room->cols, topRightRightSeat % room->cols, room->seats[topRightRightSeat]);
    }
    int rightRightSeat = getRightRightSeat(room, seat);
    if (rightRightSeat != -1) {
        addSeat(directNeighborSeats, rightRightSeat / room->cols, rightRightSeat % room->cols, room->seats[rightRightSeat]);
    }
    int bottomRightRightSeat = getBottomRightRightSeat(room, seat);
    if (bottomRightRightSeat != -1) {
        addSeat(directNeighborSeats, bottomRightRightSeat / room->cols, bottomRightRightSeat % room->cols, room->seats[bottomRightRightSeat]);
    }
    int bottomBottomRightSeat = getBottomBottomRightSeat(room, seat);
    if (bottomBottomRightSeat != -1) {
        addSeat(directNeighborSeats, bottomBottomRightSeat / room->cols, bottomBottomRightSeat % room->cols, room->seats[bottomBottomRightSeat]);
    }
    int bottomBottomSeat = getBottomBottomSeat(room, seat);
    if (bottomBottomSeat != -1) {
        addSeat(directNeighborSeats, bottomBottomSeat / room->cols, bottomBottomSeat % room->cols, room->seats[bottomBottomSeat]);
    }
    int bottomBottomLeftSeat = getBottomBottomLeftSeat(room, seat);
    if (bottomBottomLeftSeat != -1) {
        addSeat(directNeighborSeats, bottomBottomLeftSeat / room->cols, bottomBottomLeftSeat % room->cols, room->seats[bottomBottomLeftSeat]);
    }
    int bottomLeftLeftSeat = getBottomLeftLeftSeat(room, seat);
    if (bottomLeftLeftSeat != -1) {
        addSeat(directNeighborSeats, bottomLeftLeftSeat / room->cols, bottomLeftLeftSeat % room->cols, room->seats[bottomLeftLeftSeat]);
    }
    int leftLeftSeat = getLeftLeftSeat(room, seat);
    if (leftLeftSeat != -1) {
        addSeat(directNeighborSeats, leftLeftSeat / room->cols, leftLeftSeat % room->cols, room->seats[leftLeftSeat]);
    }
    int topLeftLeftSeat = getTopLeftLeftSeat(room, seat);
    if (topLeftLeftSeat != -1) {
        addSeat(directNeighborSeats, topLeftLeftSeat / room->cols, topLeftLeftSeat % room->cols, room->seats[topLeftLeftSeat]);
    }
    int topTopLeftSeat = getTopTopLeftSeat(room, seat);
    if (topTopLeftSeat != -1) {
        addSeat(directNeighborSeats, topTopLeftSeat / room->cols, topTopLeftSeat % room->cols, room->seats[topTopLeftSeat]);
    }
}

void addSeat(Seats *seats, int row, int col, char *studentId) {
    seats->seats[seats->size].row = row;
    seats->seats[seats->size].col = col;
    seats->seats[seats->size].studentId = studentId;
    seats->size++;
}
