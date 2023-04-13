#ifndef INDIRECTNEIGHBORS_H
#define INDIRECTNEIGHBORS_H
#include "room.hpp"
int getTopTopLeftLeftSeat(Room *room, int seat);
int getTopTopLeftSeat(Room *room, int seat);
int getTopTopSeat(Room *room, int seat);
int getTopTopRightSeat(Room *room, int seat);
int getTopTopRightRightSeat(Room *room, int seat);
int getTopRightRightSeat(Room *room, int seat);
int getRightRightSeat(Room *room, int seat);
int getBottomRightRightSeat(Room *room, int seat);
int getBottomBottomRightRightSeat(Room *room, int seat);
int getBottomBottomRightSeat(Room *room, int seat);
int getBottomBottomSeat(Room *room, int seat);
int getBottomBottomLeftSeat(Room *room, int seat);
int getBottomBottomLeftLeftSeat(Room *room, int seat);
int getBottomLeftLeftSeat(Room *room, int seat);
int getLeftLeftSeat(Room *room, int seat);
int getTopLeftLeftSeat(Room *room, int seat);
#endif