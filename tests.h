#ifndef TESTS_H
#define TESTS_H
struct TestIsValidRoomFileNameArgs {
    char *fileName;
    int expected;
};
void callTests();
void testIsValidRoomFileName();
void *callIsValidRoomFileName(void *arg);
#endif