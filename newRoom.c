#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void newRoom() {
    printf("new room\n\n");
    char str[7] = "0";

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
    
    printf("rows: %d, cols: %d\n", rows, cols);
}