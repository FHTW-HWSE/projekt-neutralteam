#ifndef ROOM_H
#define ROOM_H
typedef struct Room {
    int rows;
    int cols;
    int layout;
    char **seats;
} Room;
char *getRoomLayoutString(Room *room);
void printRoomLayout(Room *room);
void saveRoomToFile(Room *room, char *fileName);
void freeRoom(Room *room);
char *roomToString(Room *room);
#endif