#ifndef ROOM_H
#define ROOM_H
typedef struct Room {
    int rows;
    int cols;
    int layout;
    char **seats;
} Room;
void printRoomLayout(Room *room);
void saveRoomToFile(Room *room, char *fileName);
void freeRoom(Room *room);
int isValidRoomFileName(char *fileName);
int isValidSeat(Room *room, int seat);
Room *roomFromFile(char *fileName);
void printStudentIds(Room *room);
#endif