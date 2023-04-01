#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void newRoom() {
    printf("\nnew room\n");
    char str[123] = "0";

    int rows = 0;
    do {
        printf("enter number of rows: ");
        scanf("%s", str);
        rows = atoi(str);
        if (strcmp(str, "-abort") == 0) {
            exit(0);
        }
    } while(rows < 1);

    int cols = 0;
    do {
        printf("enter number of columns: ");
        scanf("%s", str);
        cols = atoi(str);
        if (strcmp(str, "-abort") == 0) {
            exit(0);
        }
    } while(cols < 1);

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

    char *room[rows][cols];
    switch (layout) {
        case 1:
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    room[i][j] = ":";
                }
            }
            break;
        case 2:
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if ( (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1) ) {
                        room[i][j] = ":";
                    } else {
                        room[i][j] = "";
                    }
                }
            }
            break;
        case 3:
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (i % 2 == 0 && j % 2 == 0) {
                       room[i][j] = ":";
                    } else {
                        room[i][j] = "";
                    }
                }
            }
            break;
    }
    printf("\nroom created\n");
    printf("valid seats:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i*cols+j;
            if(index == 0) {
                printf("%d", index);
            } else {
                if (strcmp(room[i][j], ":") == 0) {
                    printf(", %d", index);
                }
            }
        }
    }
    printf("\n\nenter student id: ");
    scanf("%s", str);
    if (strcmp(str, "-abort") == 0) {
        exit(0);
    }
    
}