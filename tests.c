#include <stdio.h>
#include <pthread.h>

#include "tests.h"
#include "room.h"

void callTests() {
    printf("running tests...\n");
    testIsValidRoomFileName();
    printf("tests complete\n");
}   

void *callIsValidRoomFileName(void *arg) {
    struct TestIsValidRoomFileNameArgs *args = arg;
    int actual = isValidRoomFileName(args->fileName);
    if (actual != args->expected) {
        printf("isValidRoomFileName test failed: expected %d, got %d\n", args->expected, actual);
    } else {
        printf("isValidRoomFileName test passed for \"%s\"\n", args->fileName);
    } 
    return NULL;
}

void testIsValidRoomFileName() {
    printf("testing isValidRoomFileName...\n");
    //test case 1
    pthread_t thread0;
    struct TestIsValidRoomFileNameArgs args0 = {"testName", 1};
    pthread_create(&thread0, NULL, callIsValidRoomFileName, &args0);
    //test case 2
    pthread_t thread1;
    struct TestIsValidRoomFileNameArgs args1 = {"testName.txt", 1};
    pthread_create(&thread1, NULL, callIsValidRoomFileName, &args1);
    //test case 3
    pthread_t thread2;
    struct TestIsValidRoomFileNameArgs args2 = {".", 0};
    pthread_create(&thread2, NULL, callIsValidRoomFileName, &args2);
    //test case 4
    pthread_t thread3;
    struct TestIsValidRoomFileNameArgs args3 = {"..", 0};
    pthread_create(&thread3, NULL, callIsValidRoomFileName, &args3);
    //test case 5
    pthread_t thread4;
    struct TestIsValidRoomFileNameArgs args4 = {"/testName", 0};
    pthread_create(&thread4, NULL, callIsValidRoomFileName, &args4);

    pthread_join(thread0, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    printf("isValidRoomFileName test complete\n");
}

