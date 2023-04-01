#include <stdio.h>

#include "loadRoom.h"
#include "room.h"

void loadRoom(Room *room) {
    printf("\nroom loaded\n");
    printRoomLayout(room);

    freeRoom(room);
}