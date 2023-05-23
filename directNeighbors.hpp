#ifndef DIRECTNEIGHBORS_H
#define DIRECTNEIGHBORS_H
#include "room.hpp"
int getTopLeftSeat(Room *room, int seatNumber);
int getTopSeat(Room *room, int seatNumber);
int getTopRightSeat(Room *room, int seatNumber);
int getRightSeat(Room *room, int seatNumber);
int getBottomRightSeat(Room *room, int seatNumber);
int getBottomSeat(Room *room, int seatNumber);
int getBottomLeftSeat(Room *room, int seatNumber);
int getLeftSeat(Room *room, int seatNumber);
#endif