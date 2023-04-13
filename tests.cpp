#include <stdio.h>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "enterStudents.hpp"

TEST_CASE("filename_onlyLetters_noExtension") {
    char fileName[] = "filename";
    REQUIRE(1 == isValidRoomFileName(fileName));
}
