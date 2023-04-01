#ifndef ROOM_H
#define ROOM_H
typedef struct Room {
    int rows;
    int cols;
    char **seats;
} Room;
void printRoom(Room *room);
void saveRoomToFile(Room *room);
Room *loadRoomFromFile(char *filename);
void freeRoom(Room *room);
#endif