#include <stdio.h>
#include <stdlib.h>

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