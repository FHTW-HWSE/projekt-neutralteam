#ifndef NEWROOM_H
#define NEWROOM_H
#include "room.hpp"
void createNewRoom();
int isValidRowNumber(int rows);
int isValidColNumber(int cols);
int isValidLayout(int layout);
Room *generateNewRoom(int rows, int cols, int layout);
#endif