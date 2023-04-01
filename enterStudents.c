#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enterStudents.h"
#include "room.h"
void enterStudents(Room *room) {
    printf("\nentering students\n");
    printf("valid seats: ");
    for (int i = 0; i < room->rows*room->cols; i++) {
        if (isValidSeat(room, i)) {
            printf("%d ", i);
        }
    }
    printf("\nconfirm with -save\n\n");

   while(1) {
        int seat = 0;
        char seatString[123] = "";
        do {
            printf("enter seat: ");
            scanf("%s", seatString);
            if (strcmp(seatString, "-abort") == 0) {
                exit(0);
            }
            if (strcmp(seatString, "-save") == 0) {
                saveRoomToFile(room);
                return;
            }
            seat = atoi(seatString);
        } while (!isValidSeat(room, seat));

        printf("enter studentId: ");
        char studentId[123] = "";
        scanf("%s", studentId);
        if (strcmp(studentId, "-abort") == 0) {
            exit(0);
        }   
        if (strcmp(studentId, "-save") == 0) {
            saveRoomToFile(room);
            return;
        }
        strcpy(room->seats[seat], studentId);
   }
}