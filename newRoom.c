#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "main.h"
#include "room.h"
#include "newRoom.h"
#include "enterStudents.h"

Room *genRoom(int rows, int cols, int layout) {
    Room *room = malloc(sizeof(Room));
    room->rows = rows;
    room->cols = cols;
    room->layout = layout;
    room->seats = malloc(sizeof(char*) * rows * cols);
    for (int i = 0; i < rows*cols; i++) {
        room->seats[i] = malloc(sizeof(char) * MAGIC_NUMBER);
        strcpy(room->seats[i], "");
    }
    return room;
}

void newRoom() {
    printf("\nnew room\n");
    char str[MAGIC_NUMBER] = "0";
    int rows = 0;
    int cols = 0;
    int layout = 0;
    do {
        printf("enter number of rows: ");
        scanf("%s", str);
        rows = atoi(str);
        if (strcmp(str, "-quit") == 0) {
            exit(0);
        }
    } while(rows < 1);
    do {
        printf("enter number of columns: ");
        scanf("%s", str);
        cols = atoi(str);
        if (strcmp(str, "-quit") == 0) {
            exit(0);
        }
    } while(cols < 1);
    printf("\nroom layout\n");
    printf("  100%%\t[1]\n");
    printf("  50%%\t[2]\n");
    printf("  25%%\t[3]\n");
    do {
        printf("select layout: ");
        scanf("%s", str);
        layout = atoi(str);
        if (strcmp(str, "-quit") == 0) {
            exit(0);
        }
    } while(layout < 1 || layout > 3);
    Room *room = genRoom(rows, cols, layout);
    printf("\nroom created\n");
    enterStudents(room);
}