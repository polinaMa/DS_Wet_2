/*
 * UnionFind.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: Polina
 */

#include "UnionFind.h"

UnionFind::UnionFind(int numOfElements){
	assert(numOfElements>0);

	this->numOfElements=numOfElements;
	sizes = new int[numOfElements];
	parents = new int[numOfElements];

	//set each element to be a group
	//set the size of each group to be 1
	for(int i=0 ; i<numOfElements ; i++){
		parents[i]=IS_PARENT;
		sizes[i]=1;
	}

	// update study groups ids
	studyGroupsArr = new StudyGroup[numOfElements];
	for(int i=0 ; i < numOfElements ; i++){
		studyGroupsArr[i].setStudyGroupID(i);
	}
}

UnionFind::UnionFind(const UnionFind& newUnionFind){
	//if the current UF is the recieved UF , Do nothing
	if(this == &newUnionFind){
		return;
	}

	delete[] sizes;
	delete[] parents;
	delete[] studyGroupsArr;

	this->numOfElements=newUnionFind.numOfElements;

	sizes = new int[numOfElements];
	parents = new int[numOfElements];
	studyGroupsArr = new StudyGroup[numOfElements];

	//copy arrays of sizes and parents of each group in the UnionFind structure
	for(int i=0 ; i<numOfElements ; i++){
		sizes[i]=newUnionFind.sizes[i];
		parents[i]=newUnionFind.parents[i];
		studyGroupsArr[i]=newUnionFind.studyGroupsArr[i];
	}
}

UnionFind::~UnionFind(){
	delete[] sizes;
	delete[] parents;
	delete[] studyGroupsArr;
}

int UnionFind::find(int n) {
	assert(n >= 0 && n <= numOfElements - 1);

	//save the nodes visited in the path to update their parent
	int visited[numOfElements];
	int visitCounter = 0;
	//find parent of the current node
	int currentParent = parents[n];

	//the current group is its own parent
	if (currentParent == IS_PARENT) {
		return n;
	}

	//go on until the parent of the group is found
	//the current parent of a group will be updated
	while (parents[currentParent] != IS_PARENT) {
		visited[visitCounter] = currentParent;
		++visitCounter;
		currentParent = parents[currentParent];
	}

	for (int i = 0; i < visitCounter; i++) {
		parents[visited[i]] = currentParent;
	}

	//delete[] visited;
	return currentParent;
}

void UnionFind::unite(int parent1, int parent2){
	assert(parent1 >= 0 && parent2 >= 0 &&
			parent1 <numOfElements && parent2<numOfElements);

	//if we try to unite the same group with itself - finish
	//check if current parent1 isn't already the parent of parent 2
	if(parent1 == parent2 || this->find(parent2) == parent1){
		return;
	}
	//int newParent = this->find(parent1);

	this->sizes[parent1] = this->sizes[parent1] +this->sizes[parent2];
	this->parents[parent2] = parent1;

	//update the average in parent 1 by checking the average in parent2
	studyGroupsArr[parent1].setTopStudentAVG(
									studyGroupsArr[parent2].getTopStudentAVG(),
									studyGroupsArr[parent2].getTopStudentID());

	//change the status of parent 2 - it isn't a faculty anymore
	studyGroupsArr[parent2].updateIsFaculty();
}

void UnionFind::setBestStudentInFaculty(int facultyID , int studentID ,
																int average){
	assert(facultyID >= 0 && facultyID < numOfElements && studentID >0
											&& average >= 0 && average <= 100);
	studyGroupsArr[facultyID].setTopStudentAVG(average,studentID);
}

int  UnionFind::getTopStudentIDInFaculty(int facultyID){
	assert(facultyID >= 0 && facultyID < numOfElements);
	return  studyGroupsArr[facultyID].getTopStudentID();
}

int UnionFind::getTopStudentAvgInFaculty(int facultyID){
	assert(facultyID >= 0 && facultyID < numOfElements);
	return  studyGroupsArr[facultyID].getTopStudentAVG();
}

void UnionFind::updateStudentExist(int studyGroupID){
	assert(studyGroupID >= 0 && studyGroupID < numOfElements);
	studyGroupsArr[studyGroupID].updateFirstStudentAssigned();
}

bool UnionFind::isFaculty(int studyGroupID){
	assert(studyGroupID >= 0 && studyGroupID < numOfElements);
	return studyGroupsArr[studyGroupID].checkIsFaculty();
}

bool UnionFind::isFacultyEmpty(int studyGroupID){
	assert(studyGroupID >= 0 && studyGroupID < numOfElements);
	return studyGroupsArr[studyGroupID].isEmpty();
}
