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

class HashTable {
	int size, numOfElements;
	AVLTree<int, Student*>* table;
	static const int tableFactor = 10;

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
	HashTable(int);
	~HashTable();
	bool contains(int);
	void insert(Student*);
	const Student* const get(int);

	void print();

};

#endif /* HASHTABLE_H_ */
