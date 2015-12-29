/*
 * HashTable.cpp
 *
 *  Created on: Dec 28, 2015
 *      Author: Ron
 */

#include "HashTable.h"

HashTable::HashTable(int initSize) {
	if (initSize <= 0) {
		throw HashTableException::invalidInitSize();
	}
	size = initSize;
	numOfElements = 0;
	table = new AVLTree<int, Student*> [initSize];
}

HashTable::~HashTable() {
	delete[] table;
}

bool HashTable::contains(int id) {
	int index = id % size;
	return table[index].contains(id);
}

const Student* const HashTable::get(int id) {
	int index = id % size;
	if (contains(id) == false) {
		throw HashTableException::ElementNotFound();
	}
	return *(table[index].get(id));
}

void HashTable::insert(Student* s) {
	int index = s->getID() % size;
	if (contains(s->getID())) {
		throw HashTableException::ElementAlreadyExists();
	}
	table[index].insert(s->getID(), s);
	++numOfElements;
	if (numOfElements == size * tableFactor) {
		Student*** studentArr = new Student**[size];
		int* treeSize = new int[size];
		for (int i = 0; i < size; ++i) {
			studentArr[i] = new Student*[table[i].getSize()];
			table[i].TreeToArray(studentArr[i]);
			treeSize[i] = table[i].getSize();
		}
		delete[] table;
		table = new AVLTree<int, Student*> [size * tableFactor];
		int old_size = size;
		size *= tableFactor;
		for (int i = 0; i < old_size; ++i) {
			for (int j = 0; j < treeSize[i]; ++j) {
				index = studentArr[i][j]->getID() % size;
				table[index].insert(studentArr[i][j]->getID(), studentArr[i][j]);
			}
			delete[] studentArr[i];
		}
		delete[] treeSize;
	}
}

void HashTable::print() {
	for (int i = 0; i < size; ++i) {
		std::cout << "Index: " << i << ":\t";
		table[i].inOrder(printFunction<int, Student*>());
		std::cout << std::endl;
	}
}
