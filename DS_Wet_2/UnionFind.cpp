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
}

UnionFind::UnionFind(const UnionFind& newUnionFind){
	if(this == &newUnionFind){
		return;
	}
	delete[] sizes;
	delete[] parents;

	this->numOfElements=newUnionFind.numOfElements;

	sizes = new int[numOfElements];
	parents = new int[numOfElements];

	//copy arrays of sizes and parents of each group in the UnionFind structure
	for(int i=0 ; i<numOfElements ; i++){
		sizes[i]=newUnionFind.sizes[i];
		parents[i]=newUnionFind.parents[i];
	}
}

UnionFind::~UnionFind(){
	delete[] sizes;
	delete[] parents;
}

int UnionFind::find(int n){
	assert(n >= 0 && n <= numOfElements-1);
	//find parent of the current node
	int currentParent = parents[n];

	//the current group is its own parent
	if(currentParent == IS_PARENT){
		return n;
	}

	//go on until the parent of the group is found
	//the current parent of a group will be updated
	while(parents[currentParent]!= IS_PARENT){
		currentParent=parents[currentParent];
	}
	return currentParent;
}

void UnionFind::unite(int parent1, int parent2){
	assert(parent1 >= 0 && parent2 >= 0);
	//if we try to unite the same group with itself - finish
	if(parent1 == parent2){
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
