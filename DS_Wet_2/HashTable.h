/*
 * HashTable.h
 *
 *  Created on: Dec 28, 2015
 *      Author: Ron
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "exception.h"
#include <iostream>
#include <string>
#include "AVLTree.h"
#include "Student.h"
#include "utils.h"

class HashTable {
	int size, numOfElements;
	AVLTree<int, Student>* table;
	static const int tableFactor = 2;

	template<class T, class U>
	class printFunction {
	public:
		void operator()(BinaryNode<T, U>* node) const {
			AVLNode<T, U>* AVLnode = dynamic_cast<AVLNode<T, U>*>(node);
			if (AVLnode == NULL) {
				return;
			}
			std::cout << "| " << *(AVLnode->key);
		}
	};

public:

	/*
     * HashTable - Constructor - creates a new Hash table with the received size
	 */
	HashTable(int initSize=2);

	/*
	 * ~HashTable - Destructor - frees all memmory allocated in the hash table
	 */
	~HashTable();

	/*
	 * contains - checks if an student with the received id exists in the
	 * 			  hash table
	 * 			  if element exists returns true, otherwise returns false
	 */
	bool contains(int);

	/*
	 * insert - adds a student with the receieved id to the hash table
	 */
	void insert(const Student& s);

	/*
	 * get - returns a const pointer to the student with the received id
	 * 		 if student with the received id doesn't exist , returns NULL
	 */
	const Student* const get(int);

	/*
	 * print - prints all the student ids  in the hash table
	 */
	void print();

	/*
	 * UpgradeStudentsAverage - updates the average of all students in
	 * 							the hash table that belong to the relevant
	 * 							stuy group , by multiplying it by the factor
	 * 							received if new grade is higher than 100 ,
	 * 							then the new grade will be 100
	 *
	 * 	@param studyGroupID - the id of the study group whose students will
	 * 						   get an higher avergae
	 *  @param factor - the factor by which the grade will be multiplied
	 */
	void UpgradeStudentsAverage(int studyGroupID, int factor);

}
;

#endif /* HASHTABLE_H_ */
