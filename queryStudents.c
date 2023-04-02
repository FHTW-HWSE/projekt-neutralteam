#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "room.h"
#include "main.h"
#include "queryStudents.h"
#include "enterStudents.h"


void printTopLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0 && col > 0) {
        int topLeftSeat = (row-1)*room->cols + (col-1);
        if (isValidSeat(room, topLeftSeat)) {
            printf("%s: %d\n", room->seats[topLeftSeat], topLeftSeat);
        }
    }
}
void printTopSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0) {
        int topSeat = (row-1)*room->cols + col;
        if (isValidSeat(room, topSeat)) {
            printf("%s: %d\n", room->seats[topSeat], topSeat);
        }
    }
}
void printTopRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0 && col < room->cols-1) {
        int topRightSeat = (row-1)*room->cols + (col+1);
        if (isValidSeat(room, topRightSeat)) {
            printf("%s: %d\n", room->seats[topRightSeat], topRightSeat);
        }
    }
}
void printRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (col < room->cols-1) {
        int rightSeat = row*room->cols + (col+1);
        if (isValidSeat(room, rightSeat)) {
            printf("%s: %d\n", room->seats[rightSeat], rightSeat);
        }
    }
}
void printBottomRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1 && col < room->cols-1) {
        int bottomRightSeat = (row+1)*room->cols + (col+1);
        if (isValidSeat(room, bottomRightSeat)) {
            printf("%s: %d\n", room->seats[bottomRightSeat], bottomRightSeat);
        }
    }
}
void printBottomSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1) {
        int bottomSeat = (row+1)*room->cols + col;
        if (isValidSeat(room, bottomSeat)) {
            printf("%s: %d\n", room->seats[bottomSeat], bottomSeat);
        }
    }
}
void printBottomLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1 && col > 0) {
        int bottomLeftSeat = (row+1)*room->cols + (col-1);
        if (isValidSeat(room, bottomLeftSeat)) {
            printf("%s: %d\n", room->seats[bottomLeftSeat], bottomLeftSeat);
        }
    }
}
void printLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (col > 0) {
        int leftSeat = row*room->cols + (col-1);
        if (isValidSeat(room, leftSeat)) {
            printf("%s: %d\n", room->seats[leftSeat], leftSeat);
        }
    }
}


void printIndirectTopLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1 && col > 1) {
        int topLeftSeat = (row-2)*room->cols + (col-2);
        if (isValidSeat(room, topLeftSeat)) {
            printf("%s: %d\n", room->seats[topLeftSeat], topLeftSeat);
        }
    }
}
void printIndirectTopTopLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1 && col > 0) {
        int topTopLeftSeat = (row-2)*room->cols + (col-1);
        if (isValidSeat(room, topTopLeftSeat)) {
            printf("%s: %d\n", room->seats[topTopLeftSeat], topTopLeftSeat);
        }
    }
}
void printIndirectTopSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1) {
        int topSeat = (row-2)*room->cols + col;
        if (isValidSeat(room, topSeat)) {
            printf("%s: %d\n", room->seats[topSeat], topSeat);
        }
    }
}
void printIndirectTopTopRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1 && col < room->cols-1) {
        int topTopRightSeat = (row-2)*room->cols + (col+1);
        if (isValidSeat(room, topTopRightSeat)) {
            printf("%s: %d\n", room->seats[topTopRightSeat], topTopRightSeat);
        }
    }
}
void printIndirectTopRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1 && col < room->cols-2) {
        int topRightSeat = (row-2)*room->cols + (col+2);
        if (isValidSeat(room, topRightSeat)) {
            printf("%s: %d\n", room->seats[topRightSeat], topRightSeat);
        }
    }
}
void printIndirectRightRightTopSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0 && col < room->cols-2) {
        int rightRightTopSeat = (row-1)*room->cols + (col+2);
        if (isValidSeat(room, rightRightTopSeat)) {
            printf("%s: %d\n", room->seats[rightRightTopSeat], rightRightTopSeat);
        }
    }
}
void printIndirectRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (col < room->cols-2) {
        int rightSeat = row*room->cols + (col+2);
        if (isValidSeat(room, rightSeat)) {
            printf("%s: %d\n", room->seats[rightSeat], rightSeat);
        }
    }
}
void printIndirectRightRightBottomSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1 && col < room->cols-2) {
        int rightRightBottomSeat = (row+1)*room->cols + (col+2);
        if (isValidSeat(room, rightRightBottomSeat)) {
            printf("%s: %d\n", room->seats[rightRightBottomSeat], rightRightBottomSeat);
        }
    }
}
void printIndirectBottomRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2 && col < room->cols-2) {
        int bottomRightSeat = (row+2)*room->cols + (col+2);
        if (isValidSeat(room, bottomRightSeat)) {
            printf("%s: %d\n", room->seats[bottomRightSeat], bottomRightSeat);
        }
    }
}
void printIndirectBottomBottomRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2 && col < room->cols-1) {
        int bottomBottomRightSeat = (row+2)*room->cols + (col+1);
        if (isValidSeat(room, bottomBottomRightSeat)) {
            printf("%s: %d\n", room->seats[bottomBottomRightSeat], bottomBottomRightSeat);
        }
    }
}
void printIndirectBottomSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2) {
        int bottomSeat = (row+2)*room->cols + col;
        if (isValidSeat(room, bottomSeat)) {
            printf("%s: %d\n", room->seats[bottomSeat], bottomSeat);
        }
    }
}
void printIndirectBottomBottomLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2 && col > 0) {
        int bottomBottomLeftSeat = (row+2)*room->cols + (col-1);
        if (isValidSeat(room, bottomBottomLeftSeat)) {
            printf("%s: %d\n", room->seats[bottomBottomLeftSeat], bottomBottomLeftSeat);
        }
    }
}
void printIndirectBottomLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2 && col > 1) {
        int bottomLeftSeat = (row+2)*room->cols + (col-2);
        if (isValidSeat(room, bottomLeftSeat)) {
            printf("%s: %d\n", room->seats[bottomLeftSeat], bottomLeftSeat);
        }
    }
}
void printIndirectLeftLeftBottomSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1 && col > 1) {
        int leftLeftBottomSeat = (row+1)*room->cols + (col-2);
        if (isValidSeat(room, leftLeftBottomSeat)) {
            printf("%s: %d\n", room->seats[leftLeftBottomSeat], leftLeftBottomSeat);
        }
    }
}
void printIndirectLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (col > 1) {
        int leftSeat = row*room->cols + (col-2);
        if (isValidSeat(room, leftSeat)) {
            printf("%s: %d\n", room->seats[leftSeat], leftSeat);
        }
    }
}
void printIndirectLeftLeftTopSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0 && col > 1) {
        int leftLeftTopSeat = (row-1)*room->cols + (col-2);
        if (isValidSeat(room, leftLeftTopSeat)) {
            printf("%s: %d\n", room->seats[leftLeftTopSeat], leftLeftTopSeat);
        }
    }
}



void queryStudents(Room *room) {
    printf("\nquery students\n");
    for (int i = 0; i < room->rows*room->cols; i++) {
        if (isValidSeat(room, i)) {
            if (strlen(room->seats[i]) > 0) {
                printf("%s: %d\n", room->seats[i], i);
            }
        }
    }
   
    while(1) {
        char studentId[MAGIC_NUMBER];
        do {
            printf("\nenter student id: ");
            scanf("%s", studentId);
            if (strcmp(studentId, "-abort") == 0) {
                freeRoom(room);
                exit(0);
            }
        } while(!isValidStudentId(studentId));
        int seat = -1;
        for (int i = 0; i < room->rows*room->cols; i++) {
            if (isValidSeat(room, i)) {
                if (strcmp(room->seats[i], studentId) == 0) {
                    seat = i;
                    break;
                }
            }
        }
        if (seat == -1) {
            printf("student not found\n");
        } else {
            printf("student found at seat %d\n", seat);
        }
        printf("\ndirect neighbors: \n");
        printTopLeftSeat(room, seat);
        printTopSeat(room, seat);
        printTopRightSeat(room, seat);
        printRightSeat(room, seat);
        printBottomRightSeat(room, seat);
        printBottomSeat(room, seat);
        printBottomLeftSeat(room, seat);
        printLeftSeat(room, seat);

        printf("\nindirect neighbors: \n");
        printIndirectTopLeftSeat(room, seat);
        printIndirectTopTopLeftSeat(room, seat);
        printIndirectTopSeat(room, seat);
        printIndirectTopTopRightSeat(room, seat);
        printIndirectTopRightSeat(room, seat);
        printIndirectRightRightTopSeat(room, seat);
        printIndirectRightSeat(room, seat);
        printIndirectRightRightBottomSeat(room, seat);
        printIndirectBottomRightSeat(room, seat);
        printIndirectBottomBottomRightSeat(room, seat);
        printIndirectBottomSeat(room, seat);
        printIndirectBottomBottomLeftSeat(room, seat);
        printIndirectBottomLeftSeat(room, seat);
        printIndirectLeftLeftBottomSeat(room, seat);
        printIndirectLeftSeat(room, seat);
        printIndirectLeftLeftTopSeat(room, seat);
    }
    freeRoom(room);
}