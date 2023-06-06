#include <stdio.h>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


#include "newRoom.hpp"
#include "menu.hpp"
#include "enterStudents.hpp"
#include "queryStudents.hpp"
#include "directNeighbors.hpp"
#include "indirectNeighbors.hpp"

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

TEST_CASE("getTopLeftSeatNumber_5x5") {
    Room *room = GENERATE(generateNewRoom(5, 5, 1), generateNewRoom(5, 5, 2), generateNewRoom(5, 5, 3));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 0));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 1));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 2));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 3));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 4));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 5));
    REQUIRE(0 == getTopLeftSeatNumber(room, 6));
    REQUIRE(1 == getTopLeftSeatNumber(room, 7));
    REQUIRE(2 == getTopLeftSeatNumber(room, 8));
    REQUIRE(3 == getTopLeftSeatNumber(room, 9));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 10));
    REQUIRE(5 == getTopLeftSeatNumber(room, 11));
    REQUIRE(6 == getTopLeftSeatNumber(room, 12));
    REQUIRE(7 == getTopLeftSeatNumber(room, 13));
    REQUIRE(8 == getTopLeftSeatNumber(room, 14));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 15));
    REQUIRE(10 == getTopLeftSeatNumber(room, 16));
    REQUIRE(11 == getTopLeftSeatNumber(room, 17));
    REQUIRE(12 == getTopLeftSeatNumber(room, 18));
    REQUIRE(13 == getTopLeftSeatNumber(room, 19));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 20));
    REQUIRE(15 == getTopLeftSeatNumber(room, 21));
    REQUIRE(16 == getTopLeftSeatNumber(room, 22));
    REQUIRE(17 == getTopLeftSeatNumber(room, 23));
    REQUIRE(18 == getTopLeftSeatNumber(room, 24));
}

TEST_CASE("getTopSeatNumber_5x5") {
    Room *room = GENERATE(generateNewRoom(5, 5, 1), generateNewRoom(5, 5, 2), generateNewRoom(5, 5, 3));
    REQUIRE(-1 == getTopSeatNumber(room, 0));
    REQUIRE(-1 == getTopSeatNumber(room, 1));
    REQUIRE(-1 == getTopSeatNumber(room, 2));
    REQUIRE(-1 == getTopSeatNumber(room, 3));
    REQUIRE(-1 == getTopSeatNumber(room, 4));
    REQUIRE(0 == getTopSeatNumber(room, 5));
    REQUIRE(1 == getTopSeatNumber(room, 6));
    REQUIRE(2 == getTopSeatNumber(room, 7));
    REQUIRE(3 == getTopSeatNumber(room, 8));
    REQUIRE(4 == getTopSeatNumber(room, 9));
    REQUIRE(5 == getTopSeatNumber(room, 10));
    REQUIRE(6 == getTopSeatNumber(room, 11));
    REQUIRE(7 == getTopSeatNumber(room, 12));
    REQUIRE(8 == getTopSeatNumber(room, 13));
    REQUIRE(9 == getTopSeatNumber(room, 14));
    REQUIRE(10 == getTopSeatNumber(room, 15));
    REQUIRE(11 == getTopSeatNumber(room, 16));
    REQUIRE(12 == getTopSeatNumber(room, 17));
    REQUIRE(13 == getTopSeatNumber(room, 18));
    REQUIRE(14 == getTopSeatNumber(room, 19));
    REQUIRE(15 == getTopSeatNumber(room, 20));
    REQUIRE(16 == getTopSeatNumber(room, 21));
    REQUIRE(17 == getTopSeatNumber(room, 22));
    REQUIRE(18 == getTopSeatNumber(room, 23));
    REQUIRE(19 == getTopSeatNumber(room, 24));
}

TEST_CASE("getTopRightSeatNumber_5x5") {
    Room *room = GENERATE(generateNewRoom(5, 5, 1), generateNewRoom(5, 5, 2), generateNewRoom(5, 5, 3));
    REQUIRE(-1 == getTopRightSeatNumber(room, 0));
    REQUIRE(-1 == getTopRightSeatNumber(room, 1));
    REQUIRE(-1 == getTopRightSeatNumber(room, 2));
    REQUIRE(-1 == getTopRightSeatNumber(room, 3));
    REQUIRE(-1 == getTopRightSeatNumber(room, 4));
    REQUIRE(1 == getTopRightSeatNumber(room, 5));
    REQUIRE(2 == getTopRightSeatNumber(room, 6));
    REQUIRE(3 == getTopRightSeatNumber(room, 7));
    REQUIRE(4 == getTopRightSeatNumber(room, 8));
    REQUIRE(-1 == getTopRightSeatNumber(room, 9));
    REQUIRE(6 == getTopRightSeatNumber(room, 10));
    REQUIRE(7 == getTopRightSeatNumber(room, 11));
    REQUIRE(8 == getTopRightSeatNumber(room, 12));  
    REQUIRE(9 == getTopRightSeatNumber(room, 13));
    REQUIRE(-1 == getTopRightSeatNumber(room, 14));
    REQUIRE(11 == getTopRightSeatNumber(room, 15));
    REQUIRE(12 == getTopRightSeatNumber(room, 16));
    REQUIRE(13 == getTopRightSeatNumber(room, 17));
    REQUIRE(14 == getTopRightSeatNumber(room, 18));
    REQUIRE(-1 == getTopRightSeatNumber(room, 19));
    REQUIRE(16 == getTopRightSeatNumber(room, 20));
    REQUIRE(17 == getTopRightSeatNumber(room, 21));
    REQUIRE(18 == getTopRightSeatNumber(room, 22));
    REQUIRE(19 == getTopRightSeatNumber(room, 23));
    REQUIRE(-1 == getTopRightSeatNumber(room, 24));
}

TEST_CASE("getRightSeatNumber_5x5") {
    Room *room = GENERATE(generateNewRoom(5, 5, 1), generateNewRoom(5, 5, 2), generateNewRoom(5, 5, 3));
    REQUIRE(1 == getRightSeatNumber(room, 0));
    REQUIRE(2 == getRightSeatNumber(room, 1));
    REQUIRE(3 == getRightSeatNumber(room, 2));
    REQUIRE(4 == getRightSeatNumber(room, 3));
    REQUIRE(-1 == getRightSeatNumber(room, 4));
    REQUIRE(6 == getRightSeatNumber(room, 5));
    REQUIRE(7 == getRightSeatNumber(room, 6));
    REQUIRE(8 == getRightSeatNumber(room, 7));
    REQUIRE(9 == getRightSeatNumber(room, 8));
    REQUIRE(-1 == getRightSeatNumber(room, 9));
    REQUIRE(11 == getRightSeatNumber(room, 10));
    REQUIRE(12 == getRightSeatNumber(room, 11));
    REQUIRE(13 == getRightSeatNumber(room, 12));
    REQUIRE(14 == getRightSeatNumber(room, 13));
    REQUIRE(-1 == getRightSeatNumber(room, 14));
    REQUIRE(16 == getRightSeatNumber(room, 15));
    REQUIRE(17 == getRightSeatNumber(room, 16));
    REQUIRE(18 == getRightSeatNumber(room, 17));
    REQUIRE(19 == getRightSeatNumber(room, 18));
    REQUIRE(-1 == getRightSeatNumber(room, 19));
    REQUIRE(21 == getRightSeatNumber(room, 20));
    REQUIRE(22 == getRightSeatNumber(room, 21));
    REQUIRE(23 == getRightSeatNumber(room, 22));
    REQUIRE(24 == getRightSeatNumber(room, 23));
    REQUIRE(-1 == getRightSeatNumber(room, 24));
}

TEST_CASE("getBottomRightSeatNumber_4x5") {
    Room *room = GENERATE(generateNewRoom(4, 5, 1), generateNewRoom(4, 5, 2), generateNewRoom(4, 5, 3));
    REQUIRE(6 == getBottomRightSeatNumber(room, 0));
    REQUIRE(7 == getBottomRightSeatNumber(room, 1));
    REQUIRE(8 == getBottomRightSeatNumber(room, 2));
    REQUIRE(9 == getBottomRightSeatNumber(room, 3));
    REQUIRE(-1 == getBottomRightSeatNumber(room, 4));
    REQUIRE(11 == getBottomRightSeatNumber(room, 5));
    REQUIRE(12 == getBottomRightSeatNumber(room, 6));
    REQUIRE(13 == getBottomRightSeatNumber(room, 7));
    REQUIRE(14 == getBottomRightSeatNumber(room, 8));
    REQUIRE(-1 == getBottomRightSeatNumber(room, 9));
    REQUIRE(16 == getBottomRightSeatNumber(room, 10));
    REQUIRE(17 == getBottomRightSeatNumber(room, 11));
    REQUIRE(18 == getBottomRightSeatNumber(room, 12));
    REQUIRE(19 == getBottomRightSeatNumber(room, 13));
    REQUIRE(-1 == getBottomRightSeatNumber(room, 14));
    REQUIRE(-1 == getBottomRightSeatNumber(room, 15));
    REQUIRE(-1 == getBottomRightSeatNumber(room, 16));
    REQUIRE(-1 == getBottomRightSeatNumber(room, 17));
    REQUIRE(-1 == getBottomRightSeatNumber(room, 18));
    REQUIRE(-1 == getBottomRightSeatNumber(room, 19));
}

TEST_CASE("getBottomSeatNumber_5x4") {
    Room *room = GENERATE(generateNewRoom(5, 4, 1), generateNewRoom(5, 4, 2), generateNewRoom(5, 4, 3));
    REQUIRE(4 == getBottomSeatNumber(room, 0));
    REQUIRE(5 == getBottomSeatNumber(room, 1));
    REQUIRE(6 == getBottomSeatNumber(room, 2));
    REQUIRE(7 == getBottomSeatNumber(room, 3));
    REQUIRE(8 == getBottomSeatNumber(room, 4));
    REQUIRE(9 == getBottomSeatNumber(room, 5));
    REQUIRE(10 == getBottomSeatNumber(room, 6));
    REQUIRE(11 == getBottomSeatNumber(room, 7));
    REQUIRE(12 == getBottomSeatNumber(room, 8));
    REQUIRE(13 == getBottomSeatNumber(room, 9));
    REQUIRE(14 == getBottomSeatNumber(room, 10));
    REQUIRE(15 == getBottomSeatNumber(room, 11));
    REQUIRE(16 == getBottomSeatNumber(room, 12));
    REQUIRE(17 == getBottomSeatNumber(room, 13));
    REQUIRE(18 == getBottomSeatNumber(room, 14));
    REQUIRE(19 == getBottomSeatNumber(room, 15));
    REQUIRE(-1 == getBottomSeatNumber(room, 16));
    REQUIRE(-1 == getBottomSeatNumber(room, 17));
    REQUIRE(-1 == getBottomSeatNumber(room, 18));
    REQUIRE(-1 == getBottomSeatNumber(room, 19));
}

TEST_CASE("getBottomLeftSeatNumber_2x4") {
    Room *room = GENERATE(generateNewRoom(2, 4, 1), generateNewRoom(2, 4, 2), generateNewRoom(2, 4, 3));
    REQUIRE(-1 == getBottomLeftSeatNumber(room, 0));
    REQUIRE(4 == getBottomLeftSeatNumber(room, 1));
    REQUIRE(5 == getBottomLeftSeatNumber(room, 2));
    REQUIRE(6 == getBottomLeftSeatNumber(room, 3));
    REQUIRE(-1 == getBottomLeftSeatNumber(room, 4));
    REQUIRE(-1 == getBottomLeftSeatNumber(room, 5));
    REQUIRE(-1 == getBottomLeftSeatNumber(room, 6));
    REQUIRE(-1 == getBottomLeftSeatNumber(room, 7));
}

TEST_CASE("getLeftSeatNumber_4x2") {
    Room *room = GENERATE(generateNewRoom(4, 2, 1), generateNewRoom(4, 2, 2), generateNewRoom(4, 2, 3));
    REQUIRE(-1 == getLeftSeatNumber(room, 0));
    REQUIRE(0 == getLeftSeatNumber(room, 1));
    REQUIRE(-1 == getLeftSeatNumber(room, 2));
    REQUIRE(2 == getLeftSeatNumber(room, 3));
    REQUIRE(-1 == getLeftSeatNumber(room, 4));
    REQUIRE(4 == getLeftSeatNumber(room, 5));
    REQUIRE(-1 == getLeftSeatNumber(room, 6));
    REQUIRE(6 == getLeftSeatNumber(room, 7));
}

TEST_CASE("getTopLeftSeatNumber_1x7") {
    Room *room = GENERATE(generateNewRoom(1, 7, 1), generateNewRoom(1, 7, 2), generateNewRoom(1, 7, 3));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 0));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 1));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 2));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 3));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 4));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 5));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 6));
}

TEST_CASE("getTopLeftSeatNumber_2x7") {
    Room *room = GENERATE(generateNewRoom(2, 7, 1), generateNewRoom(2, 7, 2), generateNewRoom(2, 7, 3));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 0));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 1));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 2));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 3));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 4));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 5));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 6));
    REQUIRE(-1 == getTopLeftSeatNumber(room, 7));
    REQUIRE(0 == getTopLeftSeatNumber(room, 8));
    REQUIRE(1 == getTopLeftSeatNumber(room, 9));
    REQUIRE(2 == getTopLeftSeatNumber(room, 10));
    REQUIRE(3 == getTopLeftSeatNumber(room, 11));
    REQUIRE(4 == getTopLeftSeatNumber(room, 12));
    REQUIRE(5 == getTopLeftSeatNumber(room, 13));
}

TEST_CASE("getTopTopLeftLeftSeatNumber_7x3") {
    Room *room = GENERATE(generateNewRoom(7, 3, 1), generateNewRoom(7, 3, 2), generateNewRoom(7, 3, 3));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 0));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 1));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 2));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 3));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 4));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 5));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 6));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 7));
    REQUIRE(0 == getTopTopLeftLeftSeatNumber(room, 8));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 9));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 10));
    REQUIRE(3 == getTopTopLeftLeftSeatNumber(room, 11));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 12));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 13));
    REQUIRE(6 == getTopTopLeftLeftSeatNumber(room, 14));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 15));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 16));
    REQUIRE(9 == getTopTopLeftLeftSeatNumber(room, 17));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 18));
    REQUIRE(-1 == getTopTopLeftLeftSeatNumber(room, 19));
    REQUIRE(12 == getTopTopLeftLeftSeatNumber(room, 20));
}

TEST_CASE("getTopTopLeftSeatNumber_4x7") {
    Room *room = GENERATE(generateNewRoom(4, 7, 1), generateNewRoom(4, 7, 2), generateNewRoom(4, 7, 3));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 0));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 1));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 2));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 3));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 4));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 5));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 6));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 7));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 8));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 9));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 10));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 11));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 12));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 13));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 14));
    REQUIRE(0 == getTopTopLeftSeatNumber(room, 15));
    REQUIRE(1 == getTopTopLeftSeatNumber(room, 16));
    REQUIRE(2 == getTopTopLeftSeatNumber(room, 17));
    REQUIRE(3 == getTopTopLeftSeatNumber(room, 18));
    REQUIRE(4 == getTopTopLeftSeatNumber(room, 19));
    REQUIRE(5 == getTopTopLeftSeatNumber(room, 20));
    REQUIRE(-1 == getTopTopLeftSeatNumber(room, 21));
    REQUIRE(7 == getTopTopLeftSeatNumber(room, 22));
    REQUIRE(8 == getTopTopLeftSeatNumber(room, 23));
    REQUIRE(9 == getTopTopLeftSeatNumber(room, 24));
    REQUIRE(10 == getTopTopLeftSeatNumber(room, 25));
    REQUIRE(11 == getTopTopLeftSeatNumber(room, 26));
    REQUIRE(12 == getTopTopLeftSeatNumber(room, 27));
}

TEST_CASE("getTopTopSeatNumber") {
    Room *room = GENERATE(generateNewRoom(5, 2, 1), generateNewRoom(5, 2, 2), generateNewRoom(5, 2, 3));
    REQUIRE(-1 == getTopTopSeatNumber(room, 0));
    REQUIRE(-1 == getTopTopSeatNumber(room, 1));
    REQUIRE(-1 == getTopTopSeatNumber(room, 2));
    REQUIRE(-1 == getTopTopSeatNumber(room, 3));
    REQUIRE(0 == getTopTopSeatNumber(room, 4));
    REQUIRE(1 == getTopTopSeatNumber(room, 5));
    REQUIRE(2 == getTopTopSeatNumber(room, 6));
    REQUIRE(3 == getTopTopSeatNumber(room, 7));
    REQUIRE(4 == getTopTopSeatNumber(room, 8));
    REQUIRE(5 == getTopTopSeatNumber(room, 9));
}

TEST_CASE("getTopTopRightSeatNumber") {
    Room *room = GENERATE(generateNewRoom(5, 3, 1), generateNewRoom(5, 3, 2), generateNewRoom(5, 3, 3));
    REQUIRE(-1 == getTopTopRightSeatNumber(room, 0));
    REQUIRE(-1 == getTopTopRightSeatNumber(room, 1));
    REQUIRE(-1 == getTopTopRightSeatNumber(room, 2));
    REQUIRE(-1 == getTopTopRightSeatNumber(room, 3));
    REQUIRE(-1 == getTopTopRightSeatNumber(room, 4));
    REQUIRE(-1 == getTopTopRightSeatNumber(room, 5));
    REQUIRE(1 == getTopTopRightSeatNumber(room, 6));
    REQUIRE(2 == getTopTopRightSeatNumber(room, 7));
    REQUIRE(-1 == getTopTopRightSeatNumber(room, 8));
    REQUIRE(4 == getTopTopRightSeatNumber(room, 9));
    REQUIRE(5 == getTopTopRightSeatNumber(room, 10));
    REQUIRE(-1 == getTopTopRightSeatNumber(room, 11));
    REQUIRE(7 == getTopTopRightSeatNumber(room, 12));
    REQUIRE(8 == getTopTopRightSeatNumber(room, 13));
    REQUIRE(-1 == getTopTopRightSeatNumber(room, 14));
}

TEST_CASE("getTopTopRightRightSeatNumber") {
    Room *room = GENERATE(generateNewRoom(6, 4, 1), generateNewRoom(6, 4, 2), generateNewRoom(6, 4, 3));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 0));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 1));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 2));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 3));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 4));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 5));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 6));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 7));
    REQUIRE(2 == getTopTopRightRightSeatNumber(room, 8));
    REQUIRE(3 == getTopTopRightRightSeatNumber(room, 9));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 10));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 11));
    REQUIRE(6 == getTopTopRightRightSeatNumber(room, 12));
    REQUIRE(7 == getTopTopRightRightSeatNumber(room, 13));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 14));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 15));
    REQUIRE(10 == getTopTopRightRightSeatNumber(room, 16));
    REQUIRE(11 == getTopTopRightRightSeatNumber(room, 17));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 18));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 19));
    REQUIRE(14 == getTopTopRightRightSeatNumber(room, 20));
    REQUIRE(15 == getTopTopRightRightSeatNumber(room, 21));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 22));
    REQUIRE(-1 == getTopTopRightRightSeatNumber(room, 23));
}

TEST_CASE("getTopRightRightSeatNumber") {
    Room *room = GENERATE(generateNewRoom(5, 3, 1), generateNewRoom(5, 3, 2), generateNewRoom(5, 3, 3));
    REQUIRE(-1 == getTopRightRightSeatNumber(room, 0));
    REQUIRE(-1 == getTopRightRightSeatNumber(room, 1));
    REQUIRE(-1 == getTopRightRightSeatNumber(room, 2));
    REQUIRE(2 == getTopRightRightSeatNumber(room, 3));
    REQUIRE(-1 == getTopRightRightSeatNumber(room, 4));
    REQUIRE(-1 == getTopRightRightSeatNumber(room, 5));
    REQUIRE(5 == getTopRightRightSeatNumber(room, 6));
    REQUIRE(-1 == getTopRightRightSeatNumber(room, 7));
    REQUIRE(-1 == getTopRightRightSeatNumber(room, 8));
    REQUIRE(8 == getTopRightRightSeatNumber(room, 9));
    REQUIRE(-1 == getTopRightRightSeatNumber(room, 10));
    REQUIRE(-1 == getTopRightRightSeatNumber(room, 11));
    REQUIRE(11 == getTopRightRightSeatNumber(room, 12));
    REQUIRE(-1 == getTopRightRightSeatNumber(room, 13));
    REQUIRE(-1 == getTopRightRightSeatNumber(room, 14));
}

TEST_CASE("getRightRightSeatNumber") {
    Room *room = GENERATE(generateNewRoom(3, 5, 1), generateNewRoom(3, 5, 2), generateNewRoom(3, 5, 3));
    REQUIRE(2 == getRightRightSeatNumber(room, 0));
    REQUIRE(3 == getRightRightSeatNumber(room, 1));
    REQUIRE(4 == getRightRightSeatNumber(room, 2));
    REQUIRE(-1 == getRightRightSeatNumber(room, 3));
    REQUIRE(-1 == getRightRightSeatNumber(room, 4));
    REQUIRE(7 == getRightRightSeatNumber(room, 5));
    REQUIRE(8 == getRightRightSeatNumber(room, 6));
    REQUIRE(9 == getRightRightSeatNumber(room, 7));
    REQUIRE(-1 == getRightRightSeatNumber(room, 8));
    REQUIRE(-1 == getRightRightSeatNumber(room, 9));
    REQUIRE(12 == getRightRightSeatNumber(room, 10));
    REQUIRE(13 == getRightRightSeatNumber(room, 11));
    REQUIRE(14 == getRightRightSeatNumber(room, 12));
    REQUIRE(-1 == getRightRightSeatNumber(room, 13));
    REQUIRE(-1 == getRightRightSeatNumber(room, 14));
}

TEST_CASE("getBottomRightRightSeatNumber") {
    Room *room = GENERATE(generateNewRoom(4, 3, 1), generateNewRoom(4, 3, 2), generateNewRoom(4, 3, 3));
    REQUIRE(5 == getBottomRightRightSeatNumber(room, 0));
    REQUIRE(-1 == getBottomRightRightSeatNumber(room, 1));
    REQUIRE(-1 == getBottomRightRightSeatNumber(room, 2));
    REQUIRE(8 == getBottomRightRightSeatNumber(room, 3));
    REQUIRE(-1 == getBottomRightRightSeatNumber(room, 4));
    REQUIRE(-1 == getBottomRightRightSeatNumber(room, 5));
    REQUIRE(11 == getBottomRightRightSeatNumber(room, 6));
    REQUIRE(-1 == getBottomRightRightSeatNumber(room, 7));
    REQUIRE(-1 == getBottomRightRightSeatNumber(room, 8));
    REQUIRE(-1 == getBottomRightRightSeatNumber(room, 9));
    REQUIRE(-1 == getBottomRightRightSeatNumber(room, 10));
    REQUIRE(-1 == getBottomRightRightSeatNumber(room, 11));
}   

TEST_CASE("getBottomBottomRightRightSeatNumber") {
    Room *room = GENERATE(generateNewRoom(6, 4, 1), generateNewRoom(6, 4, 2), generateNewRoom(6, 4, 3));
    REQUIRE(10 == getBottomBottomRightRightSeatNumber(room, 0));
    REQUIRE(11 == getBottomBottomRightRightSeatNumber(room, 1));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 2));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 3));
    REQUIRE(14 == getBottomBottomRightRightSeatNumber(room, 4));
    REQUIRE(15 == getBottomBottomRightRightSeatNumber(room, 5));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 6));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 7));
    REQUIRE(18 == getBottomBottomRightRightSeatNumber(room, 8));
    REQUIRE(19 == getBottomBottomRightRightSeatNumber(room, 9));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 10));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 11));
    REQUIRE(22 == getBottomBottomRightRightSeatNumber(room, 12));
    REQUIRE(23 == getBottomBottomRightRightSeatNumber(room, 13));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 14));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 15));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 16));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 17));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 18));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 19));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 20));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 21));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 22));
    REQUIRE(-1 == getBottomBottomRightRightSeatNumber(room, 23));
}

TEST_CASE("getBottomBottomRightSeatNumber") {
    Room *room = GENERATE(generateNewRoom(5, 3, 1), generateNewRoom(5, 3, 2), generateNewRoom(5, 3, 3));
    REQUIRE(7 == getBottomBottomRightSeatNumber(room, 0));
    REQUIRE(8 == getBottomBottomRightSeatNumber(room, 1));
    REQUIRE(-1 == getBottomBottomRightSeatNumber(room, 2));
    REQUIRE(10 == getBottomBottomRightSeatNumber(room, 3));
    REQUIRE(11 == getBottomBottomRightSeatNumber(room, 4));
    REQUIRE(-1 == getBottomBottomRightSeatNumber(room, 5));
    REQUIRE(13 == getBottomBottomRightSeatNumber(room, 6));
    REQUIRE(14 == getBottomBottomRightSeatNumber(room, 7));
    REQUIRE(-1 == getBottomBottomRightSeatNumber(room, 8));
    REQUIRE(-1 == getBottomBottomRightSeatNumber(room, 9));
    REQUIRE(-1 == getBottomBottomRightSeatNumber(room, 10));
    REQUIRE(-1 == getBottomBottomRightSeatNumber(room, 11));
    REQUIRE(-1 == getBottomBottomRightSeatNumber(room, 12));
    REQUIRE(-1 == getBottomBottomRightSeatNumber(room, 13));
    REQUIRE(-1 == getBottomBottomRightSeatNumber(room, 14));
}

TEST_CASE("getBottomBottomSeatNumber") {
    Room *room = GENERATE(generateNewRoom(4, 3, 1), generateNewRoom(4, 3, 2), generateNewRoom(4, 3, 3));
    REQUIRE(6 == getBottomBottomSeatNumber(room, 0));
    REQUIRE(7 == getBottomBottomSeatNumber(room, 1));
    REQUIRE(8 == getBottomBottomSeatNumber(room, 2));
    REQUIRE(9 == getBottomBottomSeatNumber(room, 3));
    REQUIRE(10 == getBottomBottomSeatNumber(room, 4));
    REQUIRE(11 == getBottomBottomSeatNumber(room, 5));
    REQUIRE(-1 == getBottomBottomSeatNumber(room, 6));
    REQUIRE(-1 == getBottomBottomSeatNumber(room, 7));
    REQUIRE(-1 == getBottomBottomSeatNumber(room, 8));
    REQUIRE(-1 == getBottomBottomSeatNumber(room, 9));
    REQUIRE(-1 == getBottomBottomSeatNumber(room, 10));
    REQUIRE(-1 == getBottomBottomSeatNumber(room, 11));
}

TEST_CASE("getBottomBottomLeftSeatNumber") {
    Room *room = GENERATE(generateNewRoom(3, 4, 1), generateNewRoom(3, 4, 2), generateNewRoom(3, 4, 3));
    REQUIRE(-1 == getBottomBottomLeftSeatNumber(room, 0));
    REQUIRE(8 == getBottomBottomLeftSeatNumber(room, 1));
    REQUIRE(9 == getBottomBottomLeftSeatNumber(room, 2));
    REQUIRE(10 == getBottomBottomLeftSeatNumber(room, 3));
    REQUIRE(-1 == getBottomBottomLeftSeatNumber(room, 4));
    REQUIRE(-1 == getBottomBottomLeftSeatNumber(room, 5));
    REQUIRE(-1 == getBottomBottomLeftSeatNumber(room, 6));
    REQUIRE(-1 == getBottomBottomLeftSeatNumber(room, 7));
    REQUIRE(-1 == getBottomBottomLeftSeatNumber(room, 8));
    REQUIRE(-1 == getBottomBottomLeftSeatNumber(room, 9));
    REQUIRE(-1 == getBottomBottomLeftSeatNumber(room, 10));
    REQUIRE(-1 == getBottomBottomLeftSeatNumber(room, 11));
}

TEST_CASE("getBottomBottomLeftLeftSeatNumber") {
    Room *room = GENERATE(generateNewRoom(5, 5, 1), generateNewRoom(5, 5, 2), generateNewRoom(5, 5, 3));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 0));  
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 1));
    REQUIRE(10 == getBottomBottomLeftLeftSeatNumber(room, 2));
    REQUIRE(11 == getBottomBottomLeftLeftSeatNumber(room, 3));
    REQUIRE(12 == getBottomBottomLeftLeftSeatNumber(room, 4));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 5));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 6));
    REQUIRE(15 == getBottomBottomLeftLeftSeatNumber(room, 7));
    REQUIRE(16 == getBottomBottomLeftLeftSeatNumber(room, 8));
    REQUIRE(17 == getBottomBottomLeftLeftSeatNumber(room, 9));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 10));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 11));
    REQUIRE(20 == getBottomBottomLeftLeftSeatNumber(room, 12));
    REQUIRE(21 == getBottomBottomLeftLeftSeatNumber(room, 13));
    REQUIRE(22 == getBottomBottomLeftLeftSeatNumber(room, 14));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 15));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 16));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 17));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 18));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 19));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 20));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 21));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 22));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 23));
    REQUIRE(-1 == getBottomBottomLeftLeftSeatNumber(room, 24));
}

TEST_CASE("getBottomLeftLeftSeatNumber") {
    Room *room = GENERATE(generateNewRoom(5, 3, 1), generateNewRoom(5, 3, 2), generateNewRoom(5, 3, 3));
    REQUIRE(-1 == getBottomLeftLeftSeatNumber(room, 0));
    REQUIRE(-1 == getBottomLeftLeftSeatNumber(room, 1));
    REQUIRE(3 == getBottomLeftLeftSeatNumber(room, 2));
    REQUIRE(-1 == getBottomLeftLeftSeatNumber(room, 3));
    REQUIRE(-1 == getBottomLeftLeftSeatNumber(room, 4));
    REQUIRE(6 == getBottomLeftLeftSeatNumber(room, 5));
    REQUIRE(-1 == getBottomLeftLeftSeatNumber(room, 6));
    REQUIRE(-1 == getBottomLeftLeftSeatNumber(room, 7));
    REQUIRE(9 == getBottomLeftLeftSeatNumber(room, 8));
    REQUIRE(-1 == getBottomLeftLeftSeatNumber(room, 9));
    REQUIRE(-1 == getBottomLeftLeftSeatNumber(room, 10));
    REQUIRE(12 == getBottomLeftLeftSeatNumber(room, 11));
    REQUIRE(-1 == getBottomLeftLeftSeatNumber(room, 12));
    REQUIRE(-1 == getBottomLeftLeftSeatNumber(room, 13));
    REQUIRE(-1 == getBottomLeftLeftSeatNumber(room, 14));
}

TEST_CASE("getLeftLeftSeatNumber") {
    Room *room = GENERATE(generateNewRoom(3, 5, 1), generateNewRoom(3, 5, 2), generateNewRoom(3, 5, 3));
    REQUIRE(-1 == getLeftLeftSeatNumber(room, 0));
    REQUIRE(-1 == getLeftLeftSeatNumber(room, 1));
    REQUIRE(0 == getLeftLeftSeatNumber(room, 2));
    REQUIRE(1 == getLeftLeftSeatNumber(room, 3));
    REQUIRE(2 == getLeftLeftSeatNumber(room, 4));
    REQUIRE(-1 == getLeftLeftSeatNumber(room, 5));
    REQUIRE(-1 == getLeftLeftSeatNumber(room, 6));
    REQUIRE(5 == getLeftLeftSeatNumber(room, 7));
    REQUIRE(6 == getLeftLeftSeatNumber(room, 8));
    REQUIRE(7 == getLeftLeftSeatNumber(room, 9));
    REQUIRE(-1 == getLeftLeftSeatNumber(room, 10));
    REQUIRE(-1 == getLeftLeftSeatNumber(room, 11));
    REQUIRE(10 == getLeftLeftSeatNumber(room, 12));
    REQUIRE(11 == getLeftLeftSeatNumber(room, 13));
    REQUIRE(12 == getLeftLeftSeatNumber(room, 14));
}

TEST_CASE("getTopLeftLeftSeatNumber") {
    Room *room = GENERATE(generateNewRoom(4, 4, 1), generateNewRoom(4, 4, 2), generateNewRoom(4, 4, 3));
    REQUIRE(-1 == getTopLeftLeftSeatNumber(room, 0));
    REQUIRE(-1 == getTopLeftLeftSeatNumber(room, 1));
    REQUIRE(-1 == getTopLeftLeftSeatNumber(room, 2));
    REQUIRE(-1 == getTopLeftLeftSeatNumber(room, 3));
    REQUIRE(-1 == getTopLeftLeftSeatNumber(room, 4));
    REQUIRE(-1 == getTopLeftLeftSeatNumber(room, 5));
    REQUIRE(0 == getTopLeftLeftSeatNumber(room, 6));
    REQUIRE(1 == getTopLeftLeftSeatNumber(room, 7));
    REQUIRE(-1 == getTopLeftLeftSeatNumber(room, 8));
    REQUIRE(-1 == getTopLeftLeftSeatNumber(room, 9));
    REQUIRE(4 == getTopLeftLeftSeatNumber(room, 10));
    REQUIRE(5 == getTopLeftLeftSeatNumber(room, 11));
    REQUIRE(-1 == getTopLeftLeftSeatNumber(room, 12));
    REQUIRE(-1 == getTopLeftLeftSeatNumber(room, 13));
    REQUIRE(8 == getTopLeftLeftSeatNumber(room, 14));
    REQUIRE(9 == getTopLeftLeftSeatNumber(room, 15));
}