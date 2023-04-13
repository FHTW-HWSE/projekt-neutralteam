#ifndef QUERYSTUDENTS_H
#define QUERYSTUDENTS_H
#include "room.hpp"
void queryStudents(Room *room);
int getSeatByStudentId(Room *room, char *studentId);
void printNeighbors(Room *room, int seat);
void printSeat(Room *room, int seat);
#endif