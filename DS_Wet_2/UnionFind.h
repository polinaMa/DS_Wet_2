/*
 * UnionFind.h
 *
 *  Created on: Dec 29, 2015
 *      Author: Polina
 */

#ifndef UNIONFIND_H_
#define UNIONFIND_H_

#include "assert.h"

#define IS_PARENT -1

class UnionFind{
	int numOfElements;
	int* sizes;
	int* parents;
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
	 * find - returns the parent of the recieved group
	 */
	int find(int n);

	/*
	 * unite - unites the the groups whose parents are recieved as input
	 * 		   unites the second group ti the first group
	 *
	 * @param parent1 - the parent of the first group
	 * @param parent2 - the parent of the second group
	 */
	void unite(int parent1, int parent2);
};

#endif /* UNIONFIND_H_ */
