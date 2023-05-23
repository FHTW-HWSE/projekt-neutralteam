#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loadRoom.hpp"

#include "main.hpp"
#include "menu.hpp"
#include "newRoom.hpp"
#include "seat.hpp"
#include "enterStudents.hpp"
#include "queryStudents.hpp"

void loadRoom(Room *room) {
    printf("\nroom loaded\n");
    printRoomLayout(room);
    printf("\nwhat do you want to do?\n");
    printf("  query students  [1]\n");
    printf("  enter students  [2]\n");
    char str[MAX_UIMENU_SELECTION_LENGTH] = "0";
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

Room *getRoomFromFileContent(char *fileContent) {
    char **fileContentSubstrings = (char**)malloc(sizeof(char*) * strlen(fileContent));
    int substringCount = 0;
    char *substring = strtok(fileContent, ",");
    while (substring != NULL) {
        fileContentSubstrings[substringCount++] = substring;
        substring = strtok(NULL, ",");
    }
    if (substringCount < 3) {
        printf("invalid file format1\n");
        free(fileContentSubstrings);
        return NULL;
    }
    int rows = atoi(fileContentSubstrings[0]);
    int cols = atoi(fileContentSubstrings[1]);
    int layout = atoi(fileContentSubstrings[2]);
    if (rows < 1 || cols < 1 || layout < 1 || layout > 3) {
        printf("invalid file format2\n");
        free(fileContentSubstrings);
        return NULL;
    }
    Room *room = generateNewRoom(rows, cols, layout);
    for (int i = 3; i < substringCount; i++) {
        char *seatString = fileContentSubstrings[i];
        char *split = strchr(seatString, ':');
        if (split == NULL) {
            printf("invalid file format3\n");
            free(fileContentSubstrings);
            return NULL;
        }
        *split = '\0';
        int seatNumber = atoi(seatString);
        if (!isValidSeatNumber(room, seatNumber)) {
            printf("invalid file format4\n");
            free(fileContentSubstrings);
            return NULL;
        }
        char *studentId = split+1;
        if (strlen(studentId) > MAX_STUDENTID_LENGTH) {
            printf("invalid file format5\n");
            free(fileContentSubstrings);
            return NULL;
        }
        strcpy(room->seats[seatNumber], studentId);
    }
    free(fileContentSubstrings);
    return room;
}

Room *loadRoomFromFile(char *fileName) {
    char *fileContent = getFileContent(fileName);
    if (fileContent == NULL) {
        printf("file not found\n");
        return NULL;
    }
    Room *room = getRoomFromFileContent(fileContent);
    free(fileContent);
    return room;
}

char *getFileContent(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    int fileLength = ftell(file);
    rewind(file);
    char *fileContent = (char*)malloc(sizeof(char) * fileLength+1);
    fread(fileContent,1, fileLength+1, file);
    fclose(file);
    return fileContent;
}