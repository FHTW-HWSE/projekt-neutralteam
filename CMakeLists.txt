project(MyProject)
cmake_minimum_required(VERSION 3.5)
add_executable(PROGRAMM
    main.cpp
    directNeighbors.cpp
    enterStudents.cpp
    indirectNeighbors.cpp
    loadRoom.cpp
    menu.cpp
    newRoom.cpp
    queryStudents.cpp
    room.cpp
    seat.cpp
)
add_executable(TEST
    tests.cpp   
    directNeighbors.cpp
    enterStudents.cpp
    indirectNeighbors.cpp
    loadRoom.cpp
    menu.cpp
    newRoom.cpp
    queryStudents.cpp
    room.cpp
    seat.cpp
)
add_library(Catch2 INTERFACE)

