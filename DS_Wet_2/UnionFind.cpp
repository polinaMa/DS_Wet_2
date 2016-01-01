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

	studyGroupsArr = new StudyGroup[numOfElements];
	for(int i=0 ; i < numOfElements ; i++){
		studyGroupsArr[i].setStudyGroupID(i);
	}
}

UnionFind::UnionFind(const UnionFind& newUnionFind){
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

int UnionFind::find(int n){
	int visited[numOfElements];
	for(int i = 0; i < numOfElements ; i++){
		visited[i]=0;
	}
	assert(n >= 0 && n <= numOfElements-1);
	//find parent of the current node
	int currentParent = parents[n];

	//the current group is its own parent
	if(currentParent == IS_PARENT){
		return n;
	}

	//go on until the parent of the group is found
	//the current parent of a group will be updated
	while(parents[currentParent] != IS_PARENT){
		visited[currentParent]=1;
		currentParent = parents[currentParent];
	}

	for(int i = 0 ; i < numOfElements ; i++){
		if(visited[i] == 1){
			parents[i] = currentParent;
		}
	}
	return currentParent;
}

void UnionFind::unite(int parent1, int parent2){
	assert(parent1 >= 0 && parent2 >= 0);

	//if we try to unite the same group with itself - finish
	if(parent1 == parent2){
		return;
	}

	//if parent 2 already belong to another parent and is not itself
	//parent then do nothing
	if(parent2 != this->find(parent2)){
		return;
	}

	int newParent = this->find(parent1);

	//check if current parent1 isn't already the parent of parent 2
	if(this->find(parent2)==parent1){
		return;
	}

	this->sizes[newParent]++;
	this->parents[parent2] = parent1;
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
