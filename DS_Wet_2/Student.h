/*
 * Student.h
 *
 *  Created on: Dec 25, 2015
 *      Author: Polina
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "assert.h"
#define EMPTY_STUDY_GROUP -1

class Student {
	int id;
	int average;
	int studyGroup;
public:

	/*
	 * Student - Constructor - creates a new students empty student
	 */
	Student() :
			id(0), average(0), studyGroup(EMPTY_STUDY_GROUP) {
	}
	;

	/*
	 * Student - Constructor - creates a new student with the received id
	 * 						   and average
	 * 						   the student will not be assigned to a study group
	 *
	 * 	@param id - the id of the student to be created
	 * 	@param average - the average of the newly created student
	 */
	Student(int id, int average) :
			id(id), average(average), studyGroup(EMPTY_STUDY_GROUP) {
	}
	;

	/*
	 * Student - Copy Constructor - copies the recieved student to the current
	 * 								student by copying the id, average,
	 * 								studyGroup
	 */
	Student(const Student&);

	/*
	 * ~Student - Destructor - frees all memmory allocated by the struct of
	 * 						   student
	 */
	~Student();

	/*
	 * setAverage -  sets the average of the student to be the receievd id
	 *
	 * @param avg - the new average to be set
	 */
	int setAverage(int avg);

	/*
	 * setStudyGroup - sets the study group id of the student to be the study
	 * 				   group with the received id
	 *
	 * 	@param group - the id of the study group to be set
	 */
	int setStudyGroup(int group);

	/*
	 * getID - returns the id of the current student
	 */
	const int& getID() const;

	/*
	 * getAverage - returns the average  of the current student
	 */
	int getAverage() const;

	/*
	 * getStudyGroup - returns the id of the study group to which the
	 * 				   current student belongs to
	 */
	int getStudyGroup() const;

};

#endif /* STUDENT_H_ */
