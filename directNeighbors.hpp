#ifndef DIRECTNEIGHBORS_H
#define DIRECTNEIGHBORS_H
#include "room.hpp"
int getTopLeftSeat(Room *room, int seat);
int getTopSeat(Room *room, int seat);
int getTopRightSeat(Room *room, int seat);
int getRightSeat(Room *room, int seat);
int getBottomRightSeat(Room *room, int seat);
int getBottomSeat(Room *room, int seat);
int getBottomLeftSeat(Room *room, int seat);
int getLeftSeat(Room *room, int seat);
#endif