#include <stdio.h>

#include "loadRoom.h"
#include "room.h"

void loadRoom(Room *room) {
    printf("load room\n");

    freeRoom(room);
}