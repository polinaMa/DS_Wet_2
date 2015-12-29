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
	Academy* DS = new Academy(n);
	return (void*) DS;
}

StatusType AddStudent(void* DS, int studentID, int average) {
	if (DS == NULL || studentID < 0 || average < 0 || average > 0) {
		return INVALID_INPUT;
	}
	return ((Academy*) DS)->AddStudent(studentID, average);
}

StatusType AssignStudent(void* DS, int studentID, int studyGroup) {
	if (DS == NULL) {
		return INVALID_INPUT;
	}
	return ((Academy*) DS)->AssignStudent(studentID, studyGroup);
}

StatusType JoinFaculties(void* DS, int studyGroup1, int studyGroup2) {

	return SUCCESS;
}

StatusType UnifyFacultiesByStudents(void* DS, int studentID1, int studentID2) {

	return SUCCESS;
}

StatusType GetFaculty(void* DS, int studentID, int* faculty) {

	return SUCCESS;
}

StatusType UpgradeStudyGroup(void* DS, int studyGroup, int factor) {

	return SUCCESS;
}

StatusType GetSmartestStudent(void* DS, int facultyID, int* student) {

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
