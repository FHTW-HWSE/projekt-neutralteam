#ifndef NEWROOM_H
#define NEWROOM_H
typedef struct Room {
    int rows;
    int cols;
    char **seats;
} Room;
void newRoom();
void printRoom(Room room);
#endif