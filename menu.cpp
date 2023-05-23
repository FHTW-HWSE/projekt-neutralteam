#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.hpp"
#include "menu.hpp"
#include "room.hpp"
#include "newRoom.hpp"
#include "loadRoom.hpp"
#include "enterStudents.hpp"

void showMenu() {
    char str[MAX_UIMENU_SELECTION_LENGTH] = "0";
    int option = 0;
    do {
        printf("\nmenu\n");
        printf("  new\t[1]\n");
        printf("  load\t[2]\n");
        printf("select option: ");
        scanf("%s", str);
        option = atoi(str);
        if (strcmp(str, END_PROGRAM_KEYWORD) == 0) {
            exit(0);
        }
    }  while(!isValidOption(option));
    switch (option) {
    case 1:
        createNewRoom();
        break;
    case 2: {
            char fileName[MAX_FILENAME_LENGTH+1];
            Room *room = NULL;
            do {
                printf("enter filename: ");
                scanf("%s", fileName);
                if (strcmp(fileName, END_PROGRAM_KEYWORD) == 0) {
                    exit(0);
                }
            } while(!isValidRoomFileName(fileName) || (room = loadRoomFromFile(fileName)) == NULL);
            loadRoom(room); 
        }
        break;
    }
}

int isValidOption(int option) {
    return option >= 1 && option <= 2;
}