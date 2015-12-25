/*
 * Student.h
 *
 *  Created on: Dec 25, 2015
 *      Author: Polina
 */

#ifndef STUDENT_H_
#define STUDENT_H_


class Student{
	int id;
	int average;
	int facultyID;
public:

	/*
	 *
	 */
	Student(int id, int average):id(id),average(average),facultyID(-1){
	};

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
	int setID(int id);

	/*
	 *
	 */
	int setAverage(int id);

	/*
	 *
	 */
	int setFacultyID();

	/*
	 *
	 */
	int getID();

	/*
	 *
	 */
	int getAverage();

	/*
	 *
	 */
	int getFacultyID();

};


#endif /* STUDENT_H_ */
