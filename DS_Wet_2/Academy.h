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
#include "StudyGroup.h"
#include "UnionFind.h"

class Academy {
	int numOfStudyGroups;
	AVLTree<int, Student> studentsTree;
	int* gradesHistogram;
	HashTable students;
	StudyGroup** studyGroupsArr;
	UnionFind* studyGroupsUF;
public:
	/*
	 * Academy - Constructor - creates a new struct of academy with no
	 * 						   students in it and n study groups .
	 * 						   in the current situation each study group is a
	 * 						   faculty by itself.
	 */
	Academy(int n);

	/*
	 * Academy - Distructor - frees all the memory allocated to the structure
	 */
	~Academy();

	/*
	 * AddStudent - adds a new student to the academy
	 *
	 * @param studentID - the id of the student to add to the academy
	 * 					  (should be a positive number)
	 * @param average - the average of the student to add to the Academy
	 * 					(shoul be a number between 0 to 100)
	 */
	StatusType AddStudent(int studentID, int average);

	/*
	 * AssignStudent - assigns the student with the received student id to the
	 * 				   study group with the received id
	 *
	 * 	@param studentID - the id of the student to be assigned
	 * 	@param studyGroup - the id of the study group to which the student will
	 * 						be assigned
	 */
	StatusType AssignStudent(int studentID, int studyGroup);

	/*
	 * JoinFaculties - join the faculties with the receieved ids
	 * 				   join the second faculty ti the first faculty
	 *
	 * 	@studyGroup1 - the id of the first study group whose faculty should
	 * 				   be joined
	 * 	@studyGroup2 - the id of the second study group whose faculty should
	 * 				   be joined
	 */
	StatusType JoinFaculties(int studyGroup1, int studyGroup2);

	/*
	 * GetFaculty - returns the faculty of the student whose id Is received as
	 * 				input
	 *
	 * 	@param studentID - id of the student whose faculty we want to find
	 * 	@param faculty - pointer to the result of the function , the faculty
	 * 					 id will be saved there
	 */
	StatusType GetFaculty(int studentID, int* faculty);

	/*
	 *
	 */
	StatusType UnifyFacultiesByStudents(int studentID1, int studentID2);

	/*
	 *
	 */
	StatusType UpgradeStudyGroup(int studyGroup, int factor);

	/*
	 * GetSmartestStudent - returns the id of the smartest student in the
	 * 						faculty with the received id .
	 * 						if the received id isn't an id of a faculty but is
	 * 						an id of a study group - the best studnt of the
	 * 						faculty to which the study group beloings will
	 * 						be returned
	 *
	 * 	@param facultyID - the id of the faculty whose best student id we want
	 * 						get
	 * 	@param student - pointer to the result of the function , the student
	 * 					 id  of the student with the highest average in the
	 * 					 faculty will be saved there
	 */
	StatusType GetSmartestStudent(int facultyID, int* student);

	/*
	 *
	 */
	StatusType GetNumOfStudentsInRange(int fromAvg, int toAvg, int* num);

	/*
	 * AcademyGetSize - returns the number of study Groups in the academy
	 */
	int AcademyGetSize();
};

#endif /* ACADEMY_H_ */
