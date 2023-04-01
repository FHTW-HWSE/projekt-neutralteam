#include "enterStudents.h"
void enterStudents(Room *room) {
   
}

int isValidPlace(Room *room, int row, int col) {
    if (row < 0 || row >= room->rows) {
        return 0;
    }
    if (col < 0 || col >= room->cols) {
        return 0;
    }
    switch(room->layout) {
    case 1:
        return 1;
        break;
    case 2:
        if ( (row % 2 == 0 && col % 2 == 0) || (row % 2 == 1 && col % 2 == 1) ) {
            return 1;
        } else {
            return 0;
        }
        break;
    case 3:
        if (row % 2 == 0 && col % 2 == 0) {
            return 1;
        } else {
            return 0;
        }
        break;
    }
    return 0;
}