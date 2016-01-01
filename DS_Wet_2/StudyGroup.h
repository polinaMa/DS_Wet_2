/*
 * StudyGroup.h
 *
 *  Created on: Dec 25, 2015
 *      Author: Polina
 */

#ifndef STUDYGROUP_H_
#define STUDYGROUP_H_

#include "Student.h"
#include "assert.h"

class StudyGroup{
	int id;
	int topStudentAVG;
	int topStudentID;
	static const int NO_STUDENTS_WITH_AVG = -1;

	/*
	 * setTopStudentID - updates the id of the student to be the received id
	 */
	void setTopStudentID(int newStudentID);

public:
	/*
	 * StudyGroup - Constructor - creates a new study group with the recieved
	 * 							   id
	 * 							   sets the topStudentAVG to be 0 and the
	 * 							   topStudentID to be -1 because there are no
	 * 							   students in the study Group yet
	 */
	StudyGroup(int id):id(id),topStudentAVG(0),topStudentID(NO_STUDENTS_WITH_AVG){
	};
	StudyGroup():id(0),topStudentAVG(0),topStudentID(NO_STUDENTS_WITH_AVG){
	};

	/*
	 * StudyGroup - Copy Constructor - copies the received study group to the
	 * 								   current study group.
	 * 								   copies the data saved as id,
	 * 								   topStudentAVG, topStudentID.
	 */
	StudyGroup(const StudyGroup& sg);

	/*
	 * StudyGroup - Destructor - destruct the current studyGroup
	 */
	~StudyGroup();

	/*
	 * getTopStudentAVG - returns the highest average of a student in
	 * 					   a Study Group
	 */
	int getTopStudentAVG();

	/*
	 * setTopStudentAVG - updates the highest average grade in the study group
	 * 					  if the new average is the same as the current the
	 * 					  the id of the students will be compared and the
	 * 					  student with the lowest id will be saved as the
	 * 					  student with the highest average in the study group
	 */
	void setTopStudentAVG(int newStudentAVG ,int newStudentID);

	/*
	 * getTopStudentID - returns the id of the student who has the higest
	 * 					 average in the current study group
	 */
	int getTopStudentID();

	/*
	 * setStudyGroupID - sets the current study group id to be the received id
	 */
	void setStudyGroupID(int id);
};


#endif /* STUDYGROUP_H_ */
