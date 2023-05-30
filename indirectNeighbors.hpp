#ifndef INDIRECTNEIGHBORS_H
#define INDIRECTNEIGHBORS_H
#include "room.hpp"
int getTopTopLeftLeftSeatNumber(Room *room, int seatNumber);
int getTopTopLeftSeatNumber(Room *room, int seatNumber);
int getTopTopSeatNumber(Room *room, int seatNumber);
int getTopTopRightSeatNumber(Room *room, int seatNumber);
int getTopTopRightRightSeatNumber(Room *room, int seatNumber);
int getTopRightRightSeatNumber(Room *room, int seatNumber);
int getRightRightSeatNumber(Room *room, int seatNumber);
int getBottomRightRightSeatNumber(Room *room, int seatNumber);
int getBottomBottomRightRightSeatNumber(Room *room, int seatNumber);
int getBottomBottomRightSeatNumber(Room *room, int seatNumber);
int getBottomBottomSeatNumber(Room *room, int seatNumber);
int getBottomBottomLeftSeatNumber(Room *room, int seatNumber);
int getBottomBottomLeftLeftSeatNumber(Room *room, int seatNumber);
int getBottomLeftLeftSeatNumber(Room *room, int seatNumber);
int getLeftLeftSeatNumber(Room *room, int seatNumber);
int getTopLeftLeftSeatNumber(Room *room, int seatNumber);
#endif