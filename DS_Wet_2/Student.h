/*
 * Student.h
 *
 *  Created on: Dec 25, 2015
 *      Author: Polina
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "assert.h"

class Student {
	int id;
	int average;
	int studyGroup;
public:

	/*
	 *
	 */
	Student() :
			id(0), average(0), studyGroup(-1) {
	}
	;

	/*
	 *
	 */
	Student(int id, int average) :
			id(id), average(average), studyGroup(-1) {
	}
	;

	/*
	 *
	 */
	Student(const Student&);

	/*
	 *
	 */
	~Student();

	/*
	 *
	 */
	int setAverage(int id);

	/*
	 *
	 */
	int setStudyGroup(int);

	/*
	 *
	 */
	const int& getID() const;

	/*
	 *
	 */
	int getAverage() const;

	/*
	 *
	 */
	int getStudyGroup() const;

};

#endif /* STUDENT_H_ */
