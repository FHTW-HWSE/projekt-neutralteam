#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loadRoom.h"

#include "room.h"
#include "menu.h"
#include "enterStudents.h"
#include "queryStudents.h"

void loadRoom(Room *room) {
    printf("\nroom loaded\n");
    printRoomLayout(room);
    printf("\nwhat do you want to do?\n");
    printf("  query students  [1]\n");
    printf("  enter students  [2]\n");

    char str[123] = "0";
    int option = 0;
    do {
        printf("select option: ");
        scanf("%s", str);
        option = atoi(str);
        if (strcmp(str, "-abort") == 0) {
            exit(0);
        }
    } while(!isValidOption(option));
    switch (option) {
        case 1:
            queryStudents(room);
            break;
        case 2:
            enterStudents(room);
            break;
    }
    freeRoom(room);
}