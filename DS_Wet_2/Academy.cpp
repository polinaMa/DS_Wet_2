/*
 * Academy.cpp
 *
 *  Created on: Dec 25, 2015
 *      Author: Polina
 */

#include "Academy.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Academy::Academy(int n) {
	numOfStudyGroups = n;

	gradesHistogram = new int[101];
	for (int i = 0; i < 101; i++) {
		gradesHistogram[i] = 0;
	}

	studyGroupsUF = new UnionFind(numOfStudyGroups);
}

Academy::~Academy() {
	delete[] gradesHistogram;
	delete studyGroupsUF;
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

	Student* student;
	//check if student exists or student is already assigned to a study group
	if (studentsTree.contains(studentID) == false || students.contains(studentID)) {
		student= studentsTree.get(studentID);
		//if student is already assigned to the same requested study group
		if(students.contains(studentID) && student->getStudyGroup() == studyGroup){
			return SUCCESS;
		}
		return FAILURE;
	}

	//find student in students tree
	student = studentsTree.get(studentID);

	//assign the student to the relevant study Group
	student->setStudyGroup(studyGroup);

	// add the assigned student to the hash table
	students.insert(*student);

	//update highest average in study group
	studyGroupsUF->updateStudentExist(studyGroup);
	studyGroupsUF->setBestStudentInFaculty(studyGroup,studentID,
														student->getAverage());
	//update highest average in faculty
	//int facultyID = studyGroupsUF->find(studyGroup);
	//studyGroupsUF->updateStudentExist(facultyID);
	//studyGroupsUF->setBestStudentInFaculty(facultyID,studentID,
	//												student->getAverage());
	return SUCCESS;
}

StatusType Academy::JoinFaculties(int studyGroup1, int studyGroup2) {
	int faculty1=0,faculty2=0;
	faculty1 = studyGroupsUF->findFacultyID(studyGroup1);
	faculty2 = studyGroupsUF->findFacultyID(studyGroup2);

	//both study groups belong to the same faculty
	if(faculty1 == faculty2 || studyGroup1 == studyGroup2 ){
		return FAILURE;
	}

	studyGroupsUF->unite(studyGroup1,studyGroup2);
	return SUCCESS;
}

StatusType Academy::GetFaculty(int studentID, int* faculty) {
	//check if a student is assigned to a faculty or exists in the academy
	if (students.contains(studentID) == false) {
			return FAILURE;
	}
	const Student* student = students.get(studentID);
	int sgID = student->getStudyGroup();
	*faculty = studyGroupsUF->findFacultyID(sgID);
	return SUCCESS;
}

StatusType Academy::UnifyFacultiesByStudents(int studentID1, int studentID2) {
	const Student* student1;
	const Student* student2;
	try{
		 student1 = students.get(studentID1);
		 student2 = students.get(studentID2);
	}catch (HashTableException::ElementNotFound&){
		return FAILURE;
	}

	//check if students are assigned to a study group - if they are not
	// assigned we can't join ther faculties
	if (students.contains(studentID1) == false ||
								students.contains(studentID2) == false) {
				return FAILURE;
	}
	int sgID1 = student1->getStudyGroup();
	int sgID2 = student2->getStudyGroup();
	int faculty1 = studyGroupsUF->findFacultyID(sgID1);
	int faculty2 = studyGroupsUF->findFacultyID(sgID2);

	if(faculty1 == faculty2){
		return FAILURE;
	}
	studyGroupsUF->unite(sgID1,sgID2);

	return SUCCESS;
}

StatusType Academy::UpgradeStudyGroup(int studyGroup, int factor) {
	//go over all students - check if the belong to study group
	// if yes update grade
	// otherwise , continue
	int maxGradeInFaculty = 0;
	int idOfMaxGrade = 0;

	idOfMaxGrade = studyGroupsUF->getTopStudentIDInFaculty(studyGroup);
	maxGradeInFaculty = studyGroupsUF->getTopStudentAvgInFaculty(studyGroup);

	students.UpgradeStudentsAverage(studyGroup,factor);
	studentsTree.inOrder(UpgradeStudentAVLTree<int,Student>(studyGroup , factor
							, &maxGradeInFaculty , &idOfMaxGrade , gradesHistogram));

	studyGroupsUF->setBestStudentInFaculty(studyGroup,idOfMaxGrade,maxGradeInFaculty);
	return SUCCESS;
}

StatusType Academy::GetSmartestStudent(int facultyID, int* student) {
	if(studyGroupsUF->isFaculty(facultyID) == false){
		return FAILURE;
	}

	int topStudentID = studyGroupsUF->getTopStudentIDInFaculty(facultyID);
	if(topStudentID == -1){
		return FAILURE;
	}

	*student = topStudentID;
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
