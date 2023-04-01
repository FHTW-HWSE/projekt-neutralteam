#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void menu() {
    int option = 0;
    char str[2] = "0";
    do {
        printf("\nmenu: (exit with -abort)\n");
        printf("  new\t[1]\n");
        printf("  load\t[2]\n");
        printf("select option: ");
        scanf("%s", str);
        option = atoi(str);
    }  while(!isValidOption(option));
    switch (option) {
        case 1:
            newRoom();
            break;
        case 2:
            loadRoom();
            break;
    }
}

int isValidOption(int option) {
    return option >= 1 && option <= 2;
}

void newRoom() {
    printf("new room\n\n");
    int rows = 0;
    char str[2] = "0";
    do {
        printf("enter number of rows: ");
        scanf("%s", str);
        rows = atoi(str);
    } while(rows < 1);
    int cols = 0;
    do {
        printf("enter number of columns: ");
        scanf("%s", str);
        cols = atoi(str);
    } while(cols < 1);
    printf("rows: %d, cols: %d\n", rows, cols);
}

void loadRoom() {
    printf("load room\n");
}