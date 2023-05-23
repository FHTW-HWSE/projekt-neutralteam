#ifndef SEAT_H
#define SEAT_H
#include "room.hpp"
typedef struct Seat {
    int row;
    int col;
    char *studentId;
} Seat;
typedef struct Seats {
    Seat *seats;
    int size;
} Seats;
Seats *getSeatsInUse(Room *room);
Seats *getAllSeats(Room *room);
Seats *getDirectNeighborSeats(Room *room, int seatNumber);
Seats *getIndirectNeighborSeats(Room *room, int seatNumber);
void printSeats(Room *room, Seats *seats);
void addSeat(Seats *seats, int row, int col, char *studentId);
int isValidSeatNumber(Room *room, int seatNumber);
#endif