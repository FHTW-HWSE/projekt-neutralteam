#ifndef INDIRECTNEIGHBORS_H
#define INDIRECTNEIGHBORS_H
#include "room.hpp"
int getTopTopLeftLeftSeat(Room *room, int seatNumber);
int getTopTopLeftSeat(Room *room, int seatNumber);
int getTopTopSeat(Room *room, int seatNumber);
int getTopTopRightSeat(Room *room, int seatNumber);
int getTopTopRightRightSeat(Room *room, int seatNumber);
int getTopRightRightSeat(Room *room, int seatNumber);
int getRightRightSeat(Room *room, int seatNumber);
int getBottomRightRightSeat(Room *room, int seatNumber);
int getBottomBottomRightRightSeat(Room *room, int seatNumber);
int getBottomBottomRightSeat(Room *room, int seatNumber);
int getBottomBottomSeat(Room *room, int seatNumber);
int getBottomBottomLeftSeat(Room *room, int seatNumber);
int getBottomBottomLeftLeftSeat(Room *room, int seatNumber);
int getBottomLeftLeftSeat(Room *room, int seatNumber);
int getLeftLeftSeat(Room *room, int seatNumber);
int getTopLeftLeftSeat(Room *room, int seatNumber);
#endif