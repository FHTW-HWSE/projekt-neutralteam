#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "queryStudents.h"
void queryStudents(Room *room) {
    printf("querying students\n");
    for (int i = 0; i < room->rows*room->cols; i++) {
        if (isValidSeat(room, i)) {
            if (strlen(room->seats[i]) > 0) {
                printf("%s: %d\n", room->seats[i], i);
            }
        }
    }
    freeRoom(room);
}