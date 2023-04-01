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

    int layout = 0;
    do {
        printf("select layout: ");
        scanf("%s", str);
        layout = atoi(str);
        if (strcmp(str, "-abort") == 0) {
            exit(0);
        }
    } while(layout < 1 || layout > 3);

    room.seats = (char**) malloc(room.rows * sizeof(char*));
    switch (layout) {
        case 1:
            for (int i = 0; i < room.rows; i++) {
                for (int j = 0; j < room.cols; j++) {
                    room.seats[i*room.cols+j] = ":";
                }
            }
            
            break;
        case 2:
            for (int i = 0; i < room.rows; i++) {
                for (int j = 0; j < room.cols; j++) {
                    if ( (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1) ) {
                        room.seats[i*room.cols+j] = ":";
                    } else {
                        room.seats[i*room.cols+j] = "";
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < room.rows; i++) {
                for (int j = 0; j < room.cols; j++) {
                    if (i % 2 == 0 && j % 2 == 0) {
                        room.seats[i*room.cols+j] = ":";
                    } else {
                        room.seats[i*room.cols+j] = "";
                    }
                }
            }
            break;
    }
    printf("\nroom created\n");
    printRoom(&room);
    saveRoomToFile(&room);
    loadRoom(&room);
    freeRoom(&room);
}