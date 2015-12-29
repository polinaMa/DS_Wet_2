/*
 * Student.cpp
 *
 *  Created on: Dec 25, 2015
 *      Author: Polina
 */

#include "Student.h"

Student::Student(const Student& s) :
		id(s.getID()), average(s.getAverage()), studyGroup(s.getStudyGroup()) {
}
;

Student::~Student() {

}

int Student::setAverage(int avg) {
	assert(avg >= 0 && avg <= 100);
	average = avg;
	return average;
}

int Student::setStudyGroup(int group) {
	studyGroup = group;
	return studyGroup;
}

const int& Student::getID() const {
	return id;
}

int Student::getAverage() const {
	return average;
}

int Student::getStudyGroup() const {
	return studyGroup;
}

