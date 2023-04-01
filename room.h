#ifndef ROOM_H
#define ROOM_H
typedef struct Room {
    int rows;
    int cols;
    int layout;
    char **seats;
} Room;
void printRoom(Room *room);
void saveRoomToFile(Room *room);
Room *loadRoomFromFile();
void freeRoom(Room *room);
int isValidPlace(Room *room, int row, int col);
#endif