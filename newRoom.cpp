#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.hpp"
#include "main.hpp"
#include "newRoom.hpp"
#include "enterStudents.hpp"

void createNewRoom() {
    printf("\nnew room\n");
    char str[MAX_UIMENU_SELECTION_LENGTH] = "0";
    int rows = 0;
    int cols = 0;
    int layout = 0;
    do {
        printf("enter number of rows: ");
        scanf("%s", str);
        rows = atoi(str);
        if (strcmp(str, END_PROGRAM_KEYWORD) == 0) {
            exit(0);
        }
    } while(!isValidRowNumber(rows));
    do {
        printf("enter number of columns: ");
        scanf("%s", str);
        cols = atoi(str);
        if (strcmp(str, END_PROGRAM_KEYWORD) == 0) {
            exit(0);
        }
    } while(!isValidColNumber(cols));
    printf("\nroom layout\n");
    printf("  100%%\t[1]\n");
    printf("  50%%\t[2]\n");
    printf("  25%%\t[3]\n");
    do {
        printf("select layout: ");
        scanf("%s", str);
        layout = atoi(str);
        if (strcmp(str, END_PROGRAM_KEYWORD) == 0) {
            exit(0);
        }
    } while(!isValidLayout(layout));
    Room *room = generateNewRoom(rows, cols, layout);
    printf("\nroom created\n");
    enterStudents(room);
}

int isValidRowNumber(int rows) {
    return rows >= 1 && rows <= MAX_ROWS;
}

int isValidColNumber(int cols) {
    return cols >= 1 && cols <= MAX_COLS;
}

int isValidLayout(int layout) {
    return layout >= 1 && layout <= 3;
}

Room *generateNewRoom(int rows, int cols, int layout) {
    if (!isValidRowNumber(rows) || !isValidColNumber(cols) || !isValidLayout(layout)) {
        return NULL;
    }
    Room *room = (Room*)malloc(sizeof(Room));
    room->rows = rows;
    room->cols = cols;
    room->layout = layout;
    room->seats = (char**)malloc(sizeof(char*) * rows * cols);
    for (int i = 0; i < rows*cols; i++) {
        room->seats[i] = (char*)malloc(sizeof(char) * (MAX_STUDENTID_LENGTH+1));
        strcpy(room->seats[i], "");
    }
    return room;
}