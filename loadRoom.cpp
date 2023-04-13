#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loadRoom.hpp"

#include "main.hpp"
#include "menu.hpp"
#include "newRoom.hpp"
#include "enterStudents.hpp"
#include "queryStudents.hpp"

void loadRoom(Room *room) {
    printf("\nroom loaded\n");
    printRoomLayout(room);
    printf("\nwhat do you want to do?\n");
    printf("  query students  [1]\n");
    printf("  enter students  [2]\n");
    char str[SMALL_MAGIC_NUMBER] = "0";
    int option = 0;
    do {
        printf("select option: ");
        scanf("%s", str);
        option = atoi(str);
        if (strcmp(str, END_PROGRAM_KEYWORD) == 0) {
            freeRoom(room);
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
}

Room *loadRoomFromFile(char *fileName) {
    char *fileContent = getFileContent(fileName);
    if (fileContent == NULL) {
        printf("file not found\n");
        return NULL;
    }
    char **fileContentSubstrings = (char**)malloc(sizeof(char*) * BIG_MAGIC_NUMBER);
    int substringCount = 0;
    char *substring = strtok(fileContent, ",");
    while (substring != NULL) {
        fileContentSubstrings[substringCount++] = substring;
        substring = strtok(NULL, ",");
    }
    if (substringCount < 3) {
        printf("invalid file format\n");
        free(fileContentSubstrings);
        return NULL;
    }
    int rows = atoi(fileContentSubstrings[0]);
    int cols = atoi(fileContentSubstrings[1]);
    int layout = atoi(fileContentSubstrings[2]);
    if (rows < 1 || cols < 1 || layout < 1 || layout > 3) {
        printf("invalid file format\n");
        free(fileContentSubstrings);
        return NULL;
    }
    Room *room = genRoom(rows, cols, layout);
    for (int i = 3; i < substringCount; i++) {
        char *seatString = fileContentSubstrings[i];
        char *name = strchr(seatString, ':');
        if (name == NULL) {
            printf("invalid file format\n");
            free(fileContentSubstrings);
            return NULL;
        }
        *name = '\0';
        name++;
        int seat = atoi(seatString);
        if (!isValidSeat(room, seat)) {
            printf("invalid file format\n");
            free(fileContentSubstrings);
            return NULL;
        }
        strcpy(room->seats[seat], name);
    }
    free(fileContentSubstrings);
    free(fileContent);
    return room;
}

char *getFileContent(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }
    char *fileContent = (char*)malloc(sizeof(char) * BIG_MAGIC_NUMBER);
    fgets(fileContent, BIG_MAGIC_NUMBER, file);
    fclose(file);
    return fileContent;
}