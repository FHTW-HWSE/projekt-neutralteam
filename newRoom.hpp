#ifndef NEWROOM_H
#define NEWROOM_H
#include "room.hpp"
void newRoom();
int isValidRowNumber(int rows);
int isValidColNumber(int cols);
int isValidLayout(int layout);
Room *genRoom(int rows, int cols, int layout);
#endif