#ifndef ROOM_H
#define ROOM_H
typedef struct Room {
    int rows;
    int cols;
    int layout;
    char **seats;
} Room;
typedef struct Seat {
    int row;
    int col;
    char *studentId;
} Seat;
typedef struct SeatsInUse {
    Seat *seats;
    int size;
} SeatsInUse;
char *getRoomLayoutString(Room *room);
void printRoomLayout(Room *room);
void saveRoomToFile(Room *room, char *fileName);
void freeRoom(Room *room);
int isValidSeat(Room *room, int seat);
SeatsInUse *getSeatsInUse(Room *room);
void printSeatsInUse(Room *room);
char *roomToString(Room *room);
#endif