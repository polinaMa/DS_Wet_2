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
}

int StudyGroup::getTopStudentAVG(){
	return topStudentAVG;
}

int StudyGroup::getTopStudentID(){
	return topStudentID;
}

void StudyGroup::setTopStudentID(int newStudentID){
	if(newStudentID<0){
		return ;
	}

	topStudentID=newStudentID;
}

void StudyGroup::setTopStudentAVG(int newStudentAVG , int newStudentID){
	assert(newStudentAVG >= 0 && newStudentAVG <= 100);

	//if both average are same compare ids
	if(topStudentAVG == newStudentAVG){
		//compare ids
		if(newStudentAVG < topStudentAVG){
			topStudentID = newStudentID;
			topStudentAVG = newStudentAVG;
		}
		return;
	}

	//avergaes aren't equal , compare them
	if(newStudentAVG > topStudentAVG){
		topStudentID = newStudentID;
		topStudentAVG = newStudentAVG;
	}
}
