#include <stdio.h>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "enterStudents.hpp"

TEST_CASE("IsValidRoomFileName_noExtension") {
    char const *fileName = GENERATE("fileName", "Room1", "SitzPlan", "SitzPlan123");
    REQUIRE(1 == isValidRoomFileName(fileName));
}

TEST_CASE("IsValidRoomFileName_withExtension") {
    char const *fileName = GENERATE("fileName.txt", "Room2.txt", "SitzPlan.txt", "Sitz.Plan.txt");
    REQUIRE(1 == isValidRoomFileName(fileName));
}

TEST_CASE("IsValidRoomFileName_forbiddenName") {
    char const *fileName = GENERATE(".", "..", "./", ".\\", "/qwertz", "\\qwertz" );
    REQUIRE(0 == isValidRoomFileName(fileName));
}