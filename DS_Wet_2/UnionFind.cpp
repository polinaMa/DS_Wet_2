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
		studyGroupsArr[i].setFacultyID(i);
	}
}

UnionFind::UnionFind(const UnionFind& newUnionFind){
	//if the current UF is the recieved UF , Do nothing - compare by pointers
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

	return currentParent;
}

int UnionFind::findFacultyID(int n) {
	assert(n >= 0 && n <= numOfElements - 1);
	int currentParent = find(n);
	return studyGroupsArr[currentParent].getFacultyID();
}

void UnionFind::unite(int parent1, int parent2){
	//function must unite parent 2 to parent1
	//union must be done by sizes - smaller group united to bigger group
	assert(parent1 >= 0 && parent2 >= 0 &&
			parent1 <numOfElements && parent2<numOfElements);

	//find the parent in the unionFind
	int newParent1 = this->find(parent1);
	int newParent2 = this->find(parent2);

	int bestID1,bestID2,bestAvg1,bestAvg2;
	bestID1 = getTopStudentIDInFaculty(parent1);
	bestAvg1 = getTopStudentAvgInFaculty(parent1);
	bestID2 = getTopStudentIDInFaculty(parent2);
	bestAvg2 = getTopStudentAvgInFaculty(parent2);

	//if we try to unite the same group with itself - finish
	//check if current parent1 isn't already the parent of parent 2
	if(newParent1 == newParent2){
		return;
	}

	//merge smaller to bigger
	if(sizes[newParent1] < sizes[newParent2]){

		//update sizes and parents
		this->sizes[newParent2] = this->sizes[newParent2] + this->sizes[newParent1];
		this->sizes[newParent1]=-1;
		this->parents[newParent1] = newParent2;

		studyGroupsArr[studyGroupsArr[newParent2].getFacultyID()].updateIsFaculty();
		//update relevant faculty id - only in the faculty that we merged into
		studyGroupsArr[newParent2].setFacultyID(studyGroupsArr[newParent1].getFacultyID());

	} else {

		//update sizes and parents
		this->sizes[newParent1] = this->sizes[newParent1] + this->sizes[newParent2];
		this->sizes[newParent2]=-1;
		this->parents[newParent2] = newParent1;

		//update relevant faculty id - only in the faculty that we merged into
		//newParent2 itsn't a faculty anymore
		studyGroupsArr[studyGroupsArr[newParent2].getFacultyID()].updateIsFaculty();
	}

	int facultyID = findFacultyID(parent1);
	//update the average in parent 1 by checking the average in parent2
	studyGroupsArr[facultyID].setTopStudentAVG(bestAvg1 , bestID1);
	studyGroupsArr[facultyID].setTopStudentAVG(bestAvg2 , bestID2);


}

void UnionFind::setBestStudentInFaculty(int studyGroupID , int studentID ,
																int average){
	assert(studyGroupID >= 0 && studyGroupID < numOfElements && studentID >0
											&& average >= 0 && average <= 100);

	int newFacultyID = findFacultyID(studyGroupID);
	studyGroupsArr[newFacultyID].setTopStudentAVG(average,studentID);
}

int  UnionFind::getTopStudentIDInFaculty(int studyGroupID){

	assert(studyGroupID >= 0 && studyGroupID < numOfElements);

	int newFacultyID = findFacultyID(studyGroupID);
	return  studyGroupsArr[newFacultyID].getTopStudentID();
}

int UnionFind::getTopStudentAvgInFaculty(int studyGroupID){

	assert(studyGroupID >= 0 && studyGroupID < numOfElements);

	int newFacultyID = findFacultyID(studyGroupID);
	return  studyGroupsArr[newFacultyID].getTopStudentAVG();
}

void UnionFind::updateStudentExist(int studyGroupID){
	assert(studyGroupID >= 0 && studyGroupID < numOfElements);
	studyGroupsArr[studyGroupID].updateFirstStudentAssigned();
}

bool UnionFind::isFaculty(int studyGroupID){
	assert(studyGroupID >= 0 && studyGroupID < numOfElements);
	return studyGroupsArr[studyGroupID].checkIsFaculty();
}
/*
bool UnionFind::isFacultyEmpty(int studyGroupID){
	assert(studyGroupID >= 0 && studyGroupID < numOfElements);
	return studyGroupsArr[studyGroupID].isEmpty();
}
*/

int UnionFind::getGroupSize(int groupID){
	assert(groupID >= 0 && groupID <= numOfElements - 1);
	return sizes[groupID];
}
