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

	StatusType status;
	try{
		status= ((Academy*) DS)->AddStudent(studentID, average);
	} catch(std::bad_alloc& error){
		return ALLOCATION_ERROR;
	}
	return status;
}

StatusType AssignStudent(void* DS, int studentID, int studyGroup) {
	int academySize=((Academy*) DS)->AcademyGetSize();
	if (DS == NULL || studyGroup < 0 || studyGroup >= academySize ||
					  studentID < 0) {
		return INVALID_INPUT;
	}

	StatusType status;
	try{
		status = ((Academy*) DS)->AssignStudent(studentID, studyGroup);
	} catch(std::bad_alloc& error){
		return ALLOCATION_ERROR;
	}
	return status;
}

StatusType JoinFaculties(void* DS, int studyGroup1, int studyGroup2) {
	int academySize=((Academy*) DS)->AcademyGetSize();
	if(DS == NULL || studyGroup1 < 0 || studyGroup2 < 0 ||
					 studyGroup1 >= academySize || studyGroup2 >= academySize){
		return INVALID_INPUT;
	}

	StatusType status;
	try{
		status = ((Academy*) DS)-> JoinFaculties(studyGroup1,studyGroup2);
	} catch(std::bad_alloc& error){
		return ALLOCATION_ERROR;
	}
	return status;
}

StatusType GetFaculty(void* DS, int studentID, int* faculty) {
	if(DS == NULL || studentID < 0 || faculty == NULL){
		return INVALID_INPUT;
	}

	StatusType status;
	try{
		status = ((Academy*) DS)-> GetFaculty(studentID,faculty);
	} catch(std::bad_alloc& error){
		return ALLOCATION_ERROR;
	}
	return status;
}

StatusType UnifyFacultiesByStudents(void* DS, int studentID1, int studentID2) {
	if(DS == NULL || studentID1 < 0 || studentID2 < 0){
		return INVALID_INPUT;
	}

	StatusType status;
	try{
		status = ((Academy*) DS)-> UnifyFacultiesByStudents(studentID1,
															studentID2);
	} catch(std::bad_alloc& error){
		return ALLOCATION_ERROR;
	}
	return status;
}

StatusType UpgradeStudyGroup(void* DS, int studyGroup, int factor) {
	int academySize=((Academy*) DS)->AcademyGetSize();
	if(DS == NULL || studyGroup < 0 || studyGroup >= academySize || factor < 1){
		return INVALID_INPUT;
	}

	StatusType status;
	try{
		status = ((Academy*) DS)-> UpgradeStudyGroup(studyGroup,factor);
	} catch(std::bad_alloc& error){
		return ALLOCATION_ERROR;
	}
	return status;
}

StatusType GetSmartestStudent(void* DS, int facultyID, int* student) {
	int academySize=((Academy*) DS)->AcademyGetSize();
	if(DS == NULL || facultyID < 0 || facultyID >= academySize ||
					 student == NULL) {
		return INVALID_INPUT;
	}

	StatusType status;
	try{
		status = ((Academy*) DS)->GetSmartestStudent(facultyID,student);
	} catch(std::bad_alloc& error){
		return ALLOCATION_ERROR;
	}
	return status;
}

StatusType GetNumOfStudentsInRange(void* DS, int fromAvg, int toAvg, int* num) {
	if (DS == NULL || num == NULL || fromAvg >= toAvg || fromAvg < 0
			|| toAvg > 100) {
		return INVALID_INPUT;
	}

	StatusType status;
	try{
		status = ((Academy*) DS)->GetNumOfStudentsInRange(fromAvg, toAvg, num);
	} catch(std::bad_alloc& error){
		return ALLOCATION_ERROR;
	}
	return status;
}

void Quit(void** DS) {
	if (*DS != NULL) {
		Academy* academy = (Academy*) *DS;
		delete academy;
		*DS = NULL;
	}
}
