/*
 * StudyGroup.cpp
 *
 *  Created on: Dec 25, 2015
 *      Author: Polina
 */

#include "StudyGroup.h"

StudyGroup::StudyGroup(const StudyGroup& sg){
	id=sg.id;
	topStudentAVG=sg.topStudentAVG;
	topStudentID=sg.topStudentID;
	facultyID=sg.facultyID;
	hasStudents=sg.hasStudents;
	isFaculty=sg.isFaculty;
}

StudyGroup::~StudyGroup(){
}

int StudyGroup::getTopStudentAVG(){
	return topStudentAVG;
}

int StudyGroup::getTopStudentID(){
	return topStudentID;
}

void StudyGroup::setTopStudentID(int newStudentID){
	topStudentID = newStudentID;
}

void StudyGroup::setTopStudentAVG(int newStudentAVG , int newStudentID){
	assert(newStudentAVG >= 0 && newStudentAVG <= 100);

	if(newStudentID==NO_STUDENTS_WITH_AVG){
			return;
	}
	//if its the first student assigne to study group , must save it
	if(topStudentID == NO_STUDENTS_WITH_AVG){
		topStudentID = newStudentID;
		topStudentAVG = newStudentAVG;
		return;
	}else{//its not the first student in the study group -
		  //compare with current max grade

		//if both average are same compare ids
		if(topStudentAVG == newStudentAVG){
			//compare ids
			if(newStudentID < topStudentID){
				topStudentID = newStudentID;
				topStudentAVG = newStudentAVG;
			}
			return;
		}else{//avergaes aren't equal , compare them
			if(newStudentAVG > topStudentAVG){
				topStudentID = newStudentID;
				topStudentAVG = newStudentAVG;
			}
		}
	}
}

void StudyGroup::setStudyGroupID(int id){
	this->id=id;
}

void StudyGroup::updateFirstStudentAssigned(){
	if(hasStudents == false){
		hasStudents = true;
	}
}

void StudyGroup::updateIsFaculty(){
	isFaculty = false;
}

bool StudyGroup::checkIsFaculty(){
	return isFaculty;
}

bool StudyGroup::isEmpty(){
	return !hasStudents;
}

int StudyGroup::getFacultyID(){
	return facultyID;
}

void StudyGroup::setFacultyID(int newFacultyID){
	if(newFacultyID < 0){
		return;
	}
	facultyID = newFacultyID;
}
