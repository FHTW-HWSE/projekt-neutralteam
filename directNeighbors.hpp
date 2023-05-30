#ifndef DIRECTNEIGHBORS_H
#define DIRECTNEIGHBORS_H
#include "room.hpp"
int getTopLeftSeatNumber(Room *room, int seatNumber);
int getTopSeatNumber(Room *room, int seatNumber);
int getTopRightSeatNumber(Room *room, int seatNumber);
int getRightSeatNumber(Room *room, int seatNumber);
int getBottomRightSeatNumber(Room *room, int seatNumber);
int getBottomSeatNumber(Room *room, int seatNumber);
int getBottomLeftSeatNumber(Room *room, int seatNumber);
int getLeftSeatNumber(Room *room, int seatNumber);
#endif