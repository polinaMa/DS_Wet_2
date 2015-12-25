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

using namespace std;

void*       Init(int n){
	return NULL;
}

StatusType   AddStudent(void* DS, int studentID, int average){

	return SUCCESS;
}

StatusType   AssignStudent(void* DS, int studentID, int studyGroup){

	return SUCCESS;
}

StatusType   JoinFaculties(void* DS, int studyGroup1, int studyGroup2){

	return SUCCESS;
}

StatusType  UnifyFacultiesByStudents(void* DS, int studentID1, int studentID2){

	return SUCCESS;
}

StatusType   GetFaculty(void* DS, int studentID, int* faculty){

	return SUCCESS;
}

StatusType   UpgradeStudyGroup(void* DS, int studyGroup, int factor){

	return SUCCESS;
}

StatusType   GetSmartestStudent(void* DS, int facultyID, int* student){

	return SUCCESS;
}

StatusType   GetNumOfStudentsInRange(void* DS, int fromAvg, int toAvg, int* num){

	return SUCCESS;
}

void        Quit(void** DS){

	return;
}
