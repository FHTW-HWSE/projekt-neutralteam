#include <stdio.h>
#include <string.h>

#include "menu.h"
#include "tests.h"

int main(int argc, char **argv) {
    printf("welcome to *project*!\n");
    if (argc > 2) {
        printf("too many arguments\n");
        return 1;
    }
    if (argc == 2) {
        if (strcmp(argv[1], "-tests") == 0) {
            callTests();
            return 0;
        } else {
            printf("undefined argument\n");
            return 1;
        }
    }
    if(argc == 1) {
        menu();
        return 0;
    }
}
