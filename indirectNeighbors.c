#include <stdio.h>
#include <string.h>

#include "indirectNeighbors.h"

void printTopTopLeftLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1 && col > 1) {
        int topTopLeftLeftSeat = (row-2)*room->cols + (col-2);
        if (isValidSeat(room, topTopLeftLeftSeat)) {
            if (strlen(room->seats[topTopLeftLeftSeat]) > 0) {
                printf("%s: %d\n", room->seats[topTopLeftLeftSeat], topTopLeftLeftSeat);
            }
        }
    }
}
void printTopTopLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1 && col > 0) {
        int topTopLeftSeat = (row-2)*room->cols + (col-1);
        if (isValidSeat(room, topTopLeftSeat)) {
            if (strlen(room->seats[topTopLeftSeat]) > 0) {
                printf("%s: %d\n", room->seats[topTopLeftSeat], topTopLeftSeat);
            }
        }
    }
}
void printTopTopSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1) {
        int topTopSeat = (row-2)*room->cols + col;
        if (isValidSeat(room, topTopSeat)) {
            if (strlen(room->seats[topTopSeat]) > 0) {
                printf("%s: %d\n", room->seats[topTopSeat], topTopSeat);
            }
        }
    }
}
void printTopTopRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1 && col < room->cols-1) {
        int topTopRightSeat = (row-2)*room->cols + (col+1);
        if (isValidSeat(room, topTopRightSeat)) {
            if (strlen(room->seats[topTopRightSeat]) > 0) {
                printf("%s: %d\n", room->seats[topTopRightSeat], topTopRightSeat);
            }
        }
    }
}
void printTopTopRightRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 1 && col < room->cols-2) {
        int topTopRightRightSeat = (row-2)*room->cols + (col+2);
        if (isValidSeat(room, topTopRightRightSeat)) {
            if (strlen(room->seats[topTopRightRightSeat]) > 0) {
                printf("%s: %d\n", room->seats[topTopRightRightSeat], topTopRightRightSeat);
            }
        }
    }
}
void printTopRightRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0 && col < room->cols-2) {
        int topRightRightSeat = (row-1)*room->cols + (col+2);
        if (isValidSeat(room, topRightRightSeat)) {
            if (strlen(room->seats[topRightRightSeat]) > 0) {
                printf("%s: %d\n", room->seats[topRightRightSeat], topRightRightSeat);
            }
        }
    }
}
void printRightRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (col < room->cols-2) {
        int rightRightSeat = row*room->cols + (col+2);
        if (isValidSeat(room, rightRightSeat)) {
            if (strlen(room->seats[rightRightSeat]) > 0) {
                printf("%s: %d\n", room->seats[rightRightSeat], rightRightSeat);
            }
        }
    }
}
void printBottomRightRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1 && col < room->cols-2) {
        int bottomRightRightSeat = (row+1)*room->cols + (col+2);
        if (isValidSeat(room, bottomRightRightSeat)) {
            if (strlen(room->seats[bottomRightRightSeat]) > 0) {
                printf("%s: %d\n", room->seats[bottomRightRightSeat], bottomRightRightSeat);
            }
        }
    }
}
void printBottomBottomRightRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2 && col < room->cols-2) {
        int bottomBottomRightRightSeat = (row+2)*room->cols + (col+2);
        if (isValidSeat(room, bottomBottomRightRightSeat)) {
            if (strlen(room->seats[bottomBottomRightRightSeat]) > 0) {
                printf("%s: %d\n", room->seats[bottomBottomRightRightSeat], bottomBottomRightRightSeat);
            }
        }
    }
}
void printBottomBottomRightSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2 && col < room->cols-1) {
        int bottomBottomRightSeat = (row+2)*room->cols + (col+1);
        if (isValidSeat(room, bottomBottomRightSeat)) {
            if (strlen(room->seats[bottomBottomRightSeat]) > 0) {
                printf("%s: %d\n", room->seats[bottomBottomRightSeat], bottomBottomRightSeat);
            }
        }
    }
}
void printBottomBottomSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2) {
        int bottomBottomSeat = (row+2)*room->cols + col;
        if (isValidSeat(room, bottomBottomSeat)) {
            if (strlen(room->seats[bottomBottomSeat]) > 0) {
                printf("%s: %d\n", room->seats[bottomBottomSeat], bottomBottomSeat);
            }
        }
    }
}
void printBottomBottomLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2 && col > 0) {
        int bottomBottomLeftSeat = (row+2)*room->cols + (col-1);
        if (isValidSeat(room, bottomBottomLeftSeat)) {
            if (strlen(room->seats[bottomBottomLeftSeat]) > 0) {
                printf("%s: %d\n", room->seats[bottomBottomLeftSeat], bottomBottomLeftSeat);
            }
        }
    }
}
void printBottomBottomLeftLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-2 && col > 1) {
        int bottomBottomLeftLeftSeat = (row+2)*room->cols + (col-2);
        if (isValidSeat(room, bottomBottomLeftLeftSeat)) {
            if (strlen(room->seats[bottomBottomLeftLeftSeat]) > 0) {
                printf("%s: %d\n", room->seats[bottomBottomLeftLeftSeat], bottomBottomLeftLeftSeat);
            }
        }
    }
}
void printBottomLeftLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row < room->rows-1 && col > 1) {
        int bottomLeftLeftSeat = (row+1)*room->cols + (col-2);
        if (isValidSeat(room, bottomLeftLeftSeat)) {
            if (strlen(room->seats[bottomLeftLeftSeat]) > 0) {
                printf("%s: %d\n", room->seats[bottomLeftLeftSeat], bottomLeftLeftSeat);
            }
        }
    }
}
void printLeftLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (col > 1) {
        int leftLeftSeat = row*room->cols + (col-2);
        if (isValidSeat(room, leftLeftSeat)) {
            if (strlen(room->seats[leftLeftSeat]) > 0) {
                printf("%s: %d\n", room->seats[leftLeftSeat], leftLeftSeat);
            }
        }
    }
}
void printTopLeftLeftSeat(Room *room, int seat) {
    int row = seat / room->cols;
    int col = seat % room->cols;
    if (row > 0 && col > 1) {
        int topLeftLeftSeat = (row-1)*room->cols + (col-2);
        if (isValidSeat(room, topLeftLeftSeat)) {
            if (strlen(room->seats[topLeftLeftSeat]) > 0) {
                printf("%s: %d\n", room->seats[topLeftLeftSeat], topLeftLeftSeat);
            }
        }
    }
}