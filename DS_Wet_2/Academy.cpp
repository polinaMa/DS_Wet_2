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

	studyGroupsArr = new StudyGroup*[numOfStudyGroups];
	for(int i=0 ; i < numOfStudyGroups ; i++){
		studyGroupsArr[i] = new StudyGroup(i);
	}

	studyGroupsUF = new UnionFind(numOfStudyGroups);
}

Academy::~Academy() {
	delete studyGroupsArr;
	delete gradesHistogram;
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


StatusType Academy::JoinFaculties(int studyGroup1, int studyGroup2) {
	int faculty1=0,faculty2=0;
	faculty1 = studyGroupsUF->find(studyGroup1);
	faculty2 = studyGroupsUF->find(studyGroup2);

	//both study groups belong to the same faculty
	if(faculty1 == faculty2){
		return FAILURE;
	}

	studyGroupsUF->unite(faculty1,faculty2);

	return SUCCESS;
}


StatusType Academy::GetFaculty(int studentID, int* faculty) {
	//check if astudent is assigned to a faculty or exists in the academy
	if (students.contains(studentID) == false) {
			return FAILURE;
	}
	const Student* student = students.get(studentID);
	*faculty = studyGroupsUF->find(student->getStudyGroup());
	return SUCCESS;
}
/*
StatusType Academy::UnifyFacultiesByStudents(int studentID1, int studentID2) {

}

StatusType Academy::UpgradeStudyGroup(int studyGroup, int factor) {

}
*/
StatusType Academy::GetSmartestStudent(int facultyID, int* student) {
	int newFacultyID =studyGroupsUF->find(facultyID);
	int topStudentID = studyGroupsArr[newFacultyID]->getTopStudentID();

	//there are no students in the faculty
	if(topStudentID ==-1){
		return FAILURE;
	}

	*student=topStudentID;
	return SUCCESS;
}


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

int Academy::AcademyGetSize(){
	return numOfStudyGroups;
}
