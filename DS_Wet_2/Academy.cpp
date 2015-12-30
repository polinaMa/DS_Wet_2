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

	//check if student exists or student is already assigned to a study group
	if (studentsTree.contains(studentID) == false
			|| students.contains(studentID)) {
		return FAILURE;
	}

	//find student in students tree
	Student* student = studentsTree.get(studentID);

	//assign the student to the relevant study Group
	student->setStudyGroup(studyGroup);

	// add the assigned student to the hash table
	students.insert(student);

	//update highest average in faculty
	int facultyID = studyGroupsUF->find(student->getStudyGroup());
	studyGroupsArr[facultyID]->setTopStudentAVG(student->getAverage(),studentID);
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
	//check if a student is assigned to a faculty or exists in the academy
	if (students.contains(studentID) == false) {
			return FAILURE;
	}
	const Student* student = students.get(studentID);
	*faculty = studyGroupsUF->find(student->getStudyGroup());
	return SUCCESS;
}


StatusType Academy::UnifyFacultiesByStudents(int studentID1, int studentID2) {
	const Student* student1 = students.get(studentID1);
	const Student* student2 = students.get(studentID2);

	//check if students are assigned to a study group - if they are not
	// assigned we can't join ther faculties
	if (students.contains(studentID1) == false ||
								students.contains(studentID2) == false) {
				return FAILURE;
		}
	int faculty1 = studyGroupsUF->find(student1->getStudyGroup());
	int faculty2 = studyGroupsUF->find(student2->getStudyGroup());

	if(faculty1 == faculty2){
		return FAILURE;
	}

	studyGroupsUF->unite(faculty1,faculty2);

	return SUCCESS;
}


StatusType Academy::UpgradeStudyGroup(int studyGroup, int factor) {
	//go over all students - check if the belong to study group
	// if yes update grade
	// otherwise , continue


	return SUCCESS;
}


StatusType Academy::GetSmartestStudent(int facultyID, int* student) {
	int newFacultyID =studyGroupsUF->find(facultyID);
	int topStudentID = studyGroupsArr[newFacultyID]->getTopStudentID();

	//there are no students in the faculty
	if(topStudentID ==  NO_STUDENTS_WITH_AVG){
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
