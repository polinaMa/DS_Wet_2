/*
 * Academy.h
 *
 *  Created on: Dec 25, 2015
 *      Author: Polina
 */

#ifndef ACADEMY_H_
#define ACADEMY_H_

#include "library2.h"
#include "AVLTree.h"
#include "HashTable.h"

class Academy {
	AVLTree<int, Student> studentTree;
	int* gradeHistogram;
	HashTable students;
public:
	Academy(int n);
	~Academy();
	StatusType AddStudent(int studentID, int average);
	StatusType AssignStudent(int studentID, int studyGroup);
	StatusType JoinFaculties(int studyGroup1, int studyGroup2);
	StatusType GetFaculty(int studentID, int* faculty);
	StatusType UnifyFacultiesByStudents(int studentID1, int studentID2);
	StatusType UpgradeStudyGroup(int studyGroup, int factor);
	StatusType GetSmartestStudent(int facultyID, int* student);
	StatusType GetNumOfStudentsInRange(int fromAvg, int toAvg, int* num);
};

#endif /* ACADEMY_H_ */
