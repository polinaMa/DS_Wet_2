/*
 * Academy.cpp
 *
 *  Created on: Dec 25, 2015
 *      Author: Polina
 */

#include "Academy.h"

Academy::Academy(int n) {
	numOfStudyGroups = n;
	studentsTree = AVLTree<int, Student>();
	gradesHistogram = new int[101];
	for (int i = 0; i < 101; i++) {
		gradesHistogram[i] = 0;
	}
	students = HashTable(10);
}

Academy::~Academy() {

}

StatusType Academy::AddStudent(int studentID, int average) {
	if (studentID < 0 || average < 0 || average > 100) {
		return INVALID_INPUT;
	}
	if (studentsTree.contains(studentID)) {
		return FAILURE;
	}
	Student s = Student(studentID, average);
	++gradesHistogram[average];
	studentsTree.insert(studentID, s);
	return SUCCESS;
}

StatusType Academy::AssignStudent(int studentID, int studyGroup) {
	if (studentID < 0 || studyGroup < 0 || studyGroup >= numOfStudyGroups) {
		return INVALID_INPUT;
	}
	if (studentsTree.contains(studentID) == false
			|| students.contains(studentID)) {
		return FAILURE;
	}
	Student* s = studentsTree.get(studentID);
	s->setStudyGroup(studyGroup);
	students.insert(s);
	return SUCCESS;
}
/*

StatusType Academy::JoinFaculties(int studyGroup1, int studyGroup2) {

}

StatusType Academy::GetFaculty(int studentID, int* faculty) {

}

StatusType Academy::UnifyFacultiesByStudents(int studentID1, int studentID2) {

}

StatusType Academy::UpgradeStudyGroup(int studyGroup, int factor) {

}

StatusType Academy::GetSmartestStudent(int facultyID, int* student) {

}
*/

StatusType Academy::GetNumOfStudentsInRange(int fromAvg, int toAvg, int* num) {
	if (num == NULL || fromAvg >= toAvg || fromAvg < 0 || toAvg > 100) {
		return INVALID_INPUT;
	}
	int numOfStudentsInRange = 0;
	for (int i = fromAvg + 1; i <= toAvg; ++i) {
		numOfStudentsInRange += gradesHistogram[i];
	}
	*num = numOfStudentsInRange;
	return SUCCESS;
}
