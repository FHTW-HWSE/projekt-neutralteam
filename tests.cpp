#include <stdio.h>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "enterStudents.hpp"

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
    char const *studentId = GENERATE("student\n", "student\t", ",,student1, student2", "student:1");
    REQUIRE(0 == isValidStudentId(studentId));
}