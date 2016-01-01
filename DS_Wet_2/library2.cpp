/*
 * library2.cpp
 *
 *  Created on: Dec 25, 2015
 *      Author: Polina
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "library2.h"
#include <cstring>
#include "Academy.h"

using namespace std;


void* Init(int n) {
	if(n < 2){
		return NULL;
	}
	Academy* DS = new Academy(n);
	return (void*) DS;
}

StatusType AddStudent(void* DS, int studentID, int average) {
	if (DS == NULL || studentID < 0 || average < 0 || average > 100) {
		return INVALID_INPUT;
	}
	return ((Academy*) DS)->AddStudent(studentID, average);
}

StatusType AssignStudent(void* DS, int studentID, int studyGroup) {
	int academySize=((Academy*) DS)->AcademyGetSize();
	if (DS == NULL || studyGroup < 0 || studyGroup >= academySize ||
					  studentID < 0) {
		return INVALID_INPUT;
	}
	return ((Academy*) DS)->AssignStudent(studentID, studyGroup);
}

StatusType JoinFaculties(void* DS, int studyGroup1, int studyGroup2) {
	int academySize=((Academy*) DS)->AcademyGetSize();
	if(DS == NULL || studyGroup1 < 0 || studyGroup2 < 0 ||
					 studyGroup1 >= academySize || studyGroup2 >= academySize){
		return INVALID_INPUT;
	}
	return SUCCESS;
}

StatusType GetFaculty(void* DS, int studentID, int* faculty) {
	if(DS == NULL || studentID < 0 || faculty == NULL){
		return INVALID_INPUT;
	}
	return SUCCESS;
}

StatusType UnifyFacultiesByStudents(void* DS, int studentID1, int studentID2) {
	if(DS == NULL || studentID1 < 0 || studentID2 < 0){
		return INVALID_INPUT;
	}
	return SUCCESS;
}

StatusType UpgradeStudyGroup(void* DS, int studyGroup, int factor) {
	int academySize=((Academy*) DS)->AcademyGetSize();
	if(DS == NULL || studyGroup < 0 || studyGroup >= academySize || factor < 1){
		return INVALID_INPUT;
	}
	return SUCCESS;
}

StatusType GetSmartestStudent(void* DS, int facultyID, int* student) {
	int academySize=((Academy*) DS)->AcademyGetSize();
	if(DS == NULL || facultyID < 0 || facultyID >= academySize ||
					 student == NULL) {
		return INVALID_INPUT;
	}
	return SUCCESS;
}

StatusType GetNumOfStudentsInRange(void* DS, int fromAvg, int toAvg, int* num) {
	if (DS == NULL || num == NULL || fromAvg >= toAvg || fromAvg < 0
			|| toAvg > 100) {
		return INVALID_INPUT;
	}
	return ((Academy*) DS)->GetNumOfStudentsInRange(fromAvg, toAvg, num);
}

void Quit(void** DS) {
	if (*DS != NULL) {
		Academy* academy = (Academy*) *DS;
		delete academy;
		*DS = NULL;
	}
}
