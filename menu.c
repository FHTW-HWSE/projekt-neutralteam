#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "room.h"
#include "newRoom.h"
#include "loadRoom.h"


void menu() {
    char str[123] = "0";
    int option = 0;
    do {
        printf("\nmenu\n");
        printf("  new\t[1]\n");
        printf("  load\t[2]\n");
        printf("select option: ");

        scanf("%s", str);
        option = atoi(str);

        if (strcmp(str, "-abort") == 0) {
            exit(0);
        }
    }  while(!isValidOption(option));

    switch (option) {
        case 1:
            newRoom();
            break;
        case 2: {
            loadRoom(loadRoomFromFile());
            }   
            break;
    }
}

int isValidOption(int option) {
    return option >= 1 && option <= 2;
}