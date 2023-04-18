#ifndef LOADROOM_H
#define LOADROOM_H
#include "room.hpp"
void loadRoom(Room *room);
Room *loadRoomFromFile(char *fileName);
char *getFileContent(char *fileName);
Room *getRoomFromFileContent(char *fileContent);
#endif