#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "room.h"
#include "newRoom.h"
#include "loadRoom.h"

void newRoom() {
    printf("\nnew room\n");
    
    char str[123] = "0";
    Room room = {
        .rows = 0,
        .cols = 0,
        .layout = 0,
        .seats = NULL
    };
    do {
        printf("enter number of rows: ");
        scanf("%s", str);
        room.rows = atoi(str);
        if (strcmp(str, "-abort") == 0) {
            exit(0);
        }
    } while(room.rows < 1);

    do {
        printf("enter number of columns: ");
        scanf("%s", str);
        room.cols = atoi(str);
        if (strcmp(str, "-abort") == 0) {
            exit(0);
        }
    } while(room.cols < 1);

    printf("\nroom layout\n");
    printf("  100%%\t[1]\n");
    printf("  50%%\t[2]\n");
    printf("  25%%\t[3]\n");

    do {
        printf("select layout: ");
        scanf("%s", str);
        room.layout = atoi(str);
        if (strcmp(str, "-abort") == 0) {
            exit(0);
        }
    } while(room.layout < 1 || room.layout > 3);

    room.seats = malloc(room.rows*room.cols*sizeof(char*));
    for (int i = 0; i < room.rows; i++) {
        for (int j = 0; j < room.cols; j++) {
            room.seats[i*room.cols+j] = "";
        }
    }
    printf("\nroom created\n");
    printRoomLayout(&room);
    saveRoomToFile(&room);
    loadRoom(&room);
}