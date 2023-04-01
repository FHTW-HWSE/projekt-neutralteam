#ifndef ROOM_H
#define ROOM_H
typedef struct Room {
    int rows;
    int cols;
    int layout;
    char **seats;
} Room;
void printRoomLayout(Room *room);
void saveRoomToFile(Room *room);
Room *loadRoomFromFile();
void freeRoom(Room *room);
int isValidRoomFile(char *fileName);
int isValidPlace(Room *room, int row, int col);
#endif