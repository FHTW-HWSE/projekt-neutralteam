#include <stdio.h>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "enterStudents.hpp"
#include "newRoom.hpp"

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

TEST_CASE("genRoom_validParameters") {
    int rows = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int cols = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int layout = GENERATE(1, 2, 3);
    Room *room = genRoom(rows, cols, layout);
    REQUIRE(rows == room->rows);
    REQUIRE(cols == room->cols);
    REQUIRE(layout == room->layout);
    REQUIRE(sizeof(room->seats) == rows * cols * sizeof(char*));
}

TEST_CASE("genRoom_invalidRows") {
    int rows = GENERATE(0, 101);
    int cols = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int layout = GENERATE(1, 2, 3);
    Room *room = genRoom(rows, cols, layout);
    REQUIRE(NULL == room);
}

TEST_CASE("genRoom_invalidCols") {
    int rows = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int cols = GENERATE(0, 101);
    int layout = GENERATE(1, 2, 3);
    Room *room = genRoom(rows, cols, layout);
    REQUIRE(NULL == room);
}

TEST_CASE("genRoom_invalidLayout") {
    int rows = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int cols = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int layout = GENERATE(0, 4);
    Room *room = genRoom(rows, cols, layout);
    REQUIRE(NULL == room);
}