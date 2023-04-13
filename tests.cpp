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