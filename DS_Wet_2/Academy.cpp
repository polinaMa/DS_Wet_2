/*
 * Academy.cpp
 *
 *  Created on: Dec 25, 2015
 *      Author: Polina
 */

#include "Academy.h"

Academy::Academy(int n) {
	studentTree = AVLTree<int, Student>();
	gradeHistogram = new int[101];
	students(10);
}
Academy::~Academy() {

}

StatusType AddStudent(int studentID, int average);
StatusType AssignStudent(int studentID, int studyGroup);
StatusType JoinFaculties(int studyGroup1, int studyGroup2);
StatusType GetFaculty(int studentID, int* faculty);
StatusType UnifyFacultiesByStudents(int studentID1, int studentID2);
StatusType UpgradeStudyGroup(int studyGroup, int factor);
StatusType GetSmartestStudent(int facultyID, int* student);
StatusType GetNumOfStudentsInRange(int fromAvg, int toAvg, int* num);
