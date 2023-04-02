#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "room.h"
#include "main.h"
#include "queryStudents.h"
#include "enterStudents.h"

void queryStudents(Room *room) {
    printf("\nquery students\n");
    for (int i = 0; i < room->rows*room->cols; i++) {
        if (isValidSeat(room, i)) {
            if (strlen(room->seats[i]) > 0) {
                printf("%s: %d\n", room->seats[i], i);
            }
        }
    }
   
    while(1) {
        char studentId[MAGIC_NUMBER];
        do {
            printf("\nenter student id: ");
            scanf("%s", studentId);
            if (strcmp(studentId, "-abort") == 0) {
                freeRoom(room);
                exit(0);
            }
        } while(!isValidStudentId(studentId));
        int seat = -1;
        for (int i = 0; i < room->rows*room->cols; i++) {
            if (isValidSeat(room, i)) {
                if (strcmp(room->seats[i], studentId) == 0) {
                    seat = i;
                    break;
                }
            }
        }
        if (seat == -1) {
            printf("student not found\n");
        } else {
            printf("student found at seat %d\n", seat);
        }
    }
    
    freeRoom(room);
}