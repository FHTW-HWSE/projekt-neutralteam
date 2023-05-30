#include <stdio.h>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


#include "newRoom.hpp"
#include "menu.hpp"
#include "enterStudents.hpp"
#include "queryStudents.hpp"

#include "seat.hpp"


TEST_CASE("IsValidRoomFileName_allowedName") {
    char const *fileName = GENERATE("room", "roomName", "test123", "1room", "...", ".../", "...\\", "room/room", "room\\room", "room.txt", "sitz.plan", "sitz.plan.wtf, sitz.plan.1");
    REQUIRE(1 == isValidRoomFileName(fileName));
}

TEST_CASE("IsValidRoomFileName_forbiddenName") {
    char const *fileName = GENERATE(".", "..", "../", "..\\", "./", ".\\", "/qwertz", "\\qwertz" );
    REQUIRE(0 == isValidRoomFileName(fileName));
}

TEST_CASE("IsValidStudentId_allowedId") {
    char const *studentId = GENERATE("student1", "Student1", "student-id", "ic22b113", "ic-22-b-113");
    REQUIRE(1 == isValidStudentId(studentId));
}

TEST_CASE("isValidStudentId_forbiddenId") {
    char const *studentId = GENERATE("student\n", "student\t", "student1, student2", "student:1");
    REQUIRE(0 == isValidStudentId(studentId));
}

TEST_CASE("isValidOption_allowedOption") {
    int option = GENERATE(1, 2);
    REQUIRE(1 == isValidOption(option));
}

TEST_CASE("isValidOption_forbiddenOption") {
    int option = GENERATE(0, 3);
    REQUIRE(0 == isValidOption(option));
}

TEST_CASE("isValidLayout_allowedLayout") {
    int layout = GENERATE(1, 2, 3);
    REQUIRE(1 == isValidLayout(layout));
}

TEST_CASE("isValidLayout_forbiddenLayout") {
    int layout = GENERATE(0, 4);
    REQUIRE(0 == isValidLayout(layout));
}

TEST_CASE("isValidRowNumber_allowedRowNumber") {
    int rows = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    REQUIRE(1 == isValidRowNumber(rows));
}

TEST_CASE("isValidRowNumber_forbiddenRowNumber") {
    int rows = GENERATE(0, 101);
    REQUIRE(0 == isValidRowNumber(rows));
}

TEST_CASE("isValidColNumber_allowedColNumber") {
    int cols = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    REQUIRE(1 == isValidColNumber(cols));
}

TEST_CASE("isValidColNumber_forbiddenColNumber") {
    int cols = GENERATE(0, 101);
    REQUIRE(0 == isValidColNumber(cols));
}

TEST_CASE("generateNewRoom_validParameters") {
    int rows = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int cols = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int layout = GENERATE(1, 2, 3);
    Room *room = generateNewRoom(rows, cols, layout);
    REQUIRE(rows == room->rows);
    REQUIRE(cols == room->cols);
    REQUIRE(layout == room->layout);
}

TEST_CASE("generateNewRoom_invalidRows") {
    int rows = GENERATE(0, 101);
    int cols = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int layout = GENERATE(1, 2, 3);
    Room *room = generateNewRoom(rows, cols, layout);
    REQUIRE(NULL == room);
}

TEST_CASE("generateNewRoom_invalidCols") {
    int rows = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int cols = GENERATE(0, 101);
    int layout = GENERATE(1, 2, 3);
    Room *room = generateNewRoom(rows, cols, layout);
    REQUIRE(NULL == room);
}

TEST_CASE("generateNewRoom_invalidLayout") {
    int rows = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int cols = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int layout = GENERATE(0, 4);
    Room *room = generateNewRoom(rows, cols, layout);
    REQUIRE(NULL == room);
}

TEST_CASE("isValidSeatNumber_layout1") {
    Room *room = generateNewRoom(5, 5, 1);
    int seatNumber = GENERATE(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24);
    REQUIRE(1 == isValidSeatNumber(room, seatNumber));
}

TEST_CASE("isValidSeatNumber_layout2") {
    Room *room = generateNewRoom(5, 5, 2);
    int seatNumber = GENERATE(0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24);
    REQUIRE(1 == isValidSeatNumber(room, seatNumber));
}

TEST_CASE("isValidSeatNumber_layout3") {
    Room *room = generateNewRoom(5, 5, 3);
    int seatNumber = GENERATE(0, 2, 4, 10, 12, 14, 20, 22, 24);
    REQUIRE(1 == isValidSeatNumber(room, seatNumber));
}

TEST_CASE("writeStudentIdToSeatNumber_layout1") {
    Room *room = generateNewRoom(5, 5, 1);
     int seatNumber = GENERATE(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24);
    writeStudentIdToSeatNumber((char*)"studentId", room, seatNumber);
    REQUIRE(strcmp(room->seats[seatNumber], "studentId") == 0);
}

TEST_CASE("writeStudentIdToSeatNumber_layout2") {
    Room *room = generateNewRoom(5, 5, 2);
    int seatNumber = GENERATE(0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24);
    writeStudentIdToSeatNumber((char*)"studentId", room, seatNumber);
    REQUIRE(strcmp(room->seats[seatNumber], "studentId") == 0);
}

TEST_CASE("writeStudentIdToSeatNumber_layout3") {
    Room *room = generateNewRoom(5, 5, 3);
    int seatNumber = GENERATE(0, 2, 4, 10, 12, 14, 20, 22, 24);
    writeStudentIdToSeatNumber((char*)"studentId", room, seatNumber);
    REQUIRE(strcmp(room->seats[seatNumber], "studentId") == 0);
}

TEST_CASE("getSeatNumberByStudentId") {
    Room *room = generateNewRoom(5, 5, 1);
    writeStudentIdToSeatNumber((char*)"studentId", room, 0);
    writeStudentIdToSeatNumber((char*)"studentId2", room, 7);
    writeStudentIdToSeatNumber((char*)"studentId3", room, 9);
    writeStudentIdToSeatNumber((char*)"studentId4", room, 16);
    writeStudentIdToSeatNumber((char*)"studentId5", room, 18);
    writeStudentIdToSeatNumber((char*)"studentId6", room, 24);
    REQUIRE(0 == getSeatNumberByStudentId(room, (char*)"studentId"));
    REQUIRE(7 == getSeatNumberByStudentId(room, (char*)"studentId2"));
    REQUIRE(9 == getSeatNumberByStudentId(room, (char*)"studentId3"));
    REQUIRE(16 == getSeatNumberByStudentId(room, (char*)"studentId4"));
    REQUIRE(18 == getSeatNumberByStudentId(room, (char*)"studentId5"));
    REQUIRE(24 == getSeatNumberByStudentId(room, (char*)"studentId6"));
    REQUIRE(-1 == getSeatNumberByStudentId(room, (char*)"studentId7"));
}


