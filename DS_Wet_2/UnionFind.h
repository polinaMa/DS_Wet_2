/*
 * UnionFind.h
 *
 *  Created on: Dec 29, 2015
 *      Author: Polina
 */

#ifndef UNIONFIND_H_
#define UNIONFIND_H_

#include "assert.h"
#include "StudyGroup.h"
#include <stdlib.h>

class UnionFind{
	int numOfElements;
	int* sizes;
	int* parents;
	static const int IS_PARENT = -1;
	StudyGroup* studyGroupsArr;

public:

	/*
	 * UnionFind - Constructor - reates a new UnionFind whose size is
	 * 							 numOfElements .
	 * 							 the elemnts are consequent from 1 to the number
	 * 							 rececived in numOfElements
	 * 	@param numOfElements - number of Elements in the Union-Find Struct
	 * 							asserting the size is non-negative
	 */
	UnionFind(int numOfElements);

	/*
	 * UnionFind - Copy Constructor - copies the received union find struct to
	 * 								  the current union find
	 */
	UnionFind(const UnionFind& newUnionFind);

	/*
	 * ~UnionFind - Destructor - destructs the current UnionFind struct by
	 * 							 freeing all of its memory
	 */
	~UnionFind();

	/*
	 * find - returns the parent of the recieved group in the array of union find
	 */
	int find(int n);
	int findFacultyID(int n);

	/*
	 * unite - unites the the groups whose parents are recieved as input
	 * 		   unites the second group ti the first group
	 *
	 * @param parent1 - the parent of the first group
	 * @param parent2 - the parent of the second group
	 */
	void unite(int parent1, int parent2);

	/*
	 * setBestStudentInFaculty - updates best average for the received faculty
	 */
	void setBestStudentInFaculty(int studyGroupID , int studentID , int average);

	/*
	 * getTopStudentIDInFaculty - returns the id of the best student in the
	 * 							  received faculty
	 */
	int getTopStudentIDInFaculty(int studyGroupID);

	/*
	 * getTopStudentIDInFaculty - returns the id of the best student in the
	 * 							  received faculty
	 */
	int getTopStudentAvgInFaculty(int studyGroupID);

	/*
	 * updateStudentExist - update the faculty with the faculty ID received has
	 * 						students assigned to it
	 */
	void updateStudentExist(int studyGroupID);

	/*
	 * isFaculty - returns true if the study group with the receieved id is a
	 *			   faculty , otherwise returns false
	 */
	bool isFaculty(int studyGroupID);

	/*
	 * isFacultyEmpty - returns true if the current study group has no students
	 * 			   assigned to it , or false otherwise
	 */
	//bool isFacultyEmpty(int studyGroupID);

	int getGroupSize(int groupID);
};

#endif /* UNIONFIND_H_ */
