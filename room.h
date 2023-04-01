#ifndef ROOM_H
#define ROOM_H
typedef struct Room {
    int rows;
    int cols;
    char **seats;
} Room;
void printRoom(Room *room);
void saveRoomToFile(Room *room);
Room *loadRoomFromFile();
void freeRoom(Room *room);
#endif