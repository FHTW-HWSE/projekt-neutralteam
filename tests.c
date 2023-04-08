#include <stdio.h>
#include <pthread.h>

#include "tests.h"
#include "room.h"

void callTests() {
    printf("running tests...\n");
    pthread_t thread0;
    pthread_create(&thread0, NULL, isValidRoomFileNameTests, NULL);
    pthread_join(thread0, NULL);
    printf("tests complete\n");
}   

void *isValidRoomFileNameTests() {
    printf("testing isValidRoomFileName...\n");
    //test case 1
    callIsValidRoomFileName("testName", 1);
    //test case 2
    callIsValidRoomFileName("testName.txt", 1);
    //test case 3
    callIsValidRoomFileName(".", 0);
    //test case 4
    callIsValidRoomFileName("..", 0);
    //test case 5
    callIsValidRoomFileName("/testName", 0);
    printf("isValidRoomFileName test complete\n");
    return NULL;
}
void callIsValidRoomFileName(char *fileName, int expected) {
    int actual = isValidRoomFileName(fileName);
    if (actual != expected) {
        printf("isValidRoomFileName test failed: expected %d, got %d\n", expected, actual);
    } else {
        printf("isValidRoomFileName test passed for \"%s\"\n", fileName);
    } 
}