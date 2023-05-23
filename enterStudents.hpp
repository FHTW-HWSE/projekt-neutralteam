#ifndef ENTERSTUDENTS_H
#define ENTERSTUDENTS_H
#include "room.hpp"
#include "main.hpp"
void enterStudents(Room *room);
int isValidStudentId(const char *studentId);
int isValidRoomFileName(const char *fileName);
void writeStudentIdToSeatNumber(char studentId[MAX_STUDENTID_LENGTH+1], Room *room, int seatNumber);
#endif