/*
 * hashTable_test.cpp
 *
 *  Created on: Dec 29, 2015
 *      Author: Ron
 */

#include "HashTable.h"
#include <stdlib.h>
#include "DS_test_utils.h"
#include <string>
#include <iostream>

std::string location;

using namespace std;

bool test() {
	HashTable table = HashTable(1);
	Student** arr = new Student*[1000];
	for (int i = 0; i < 1000; ++i) {
		arr[i] = new Student(i, 50);
		table.insert(arr[i]);
	}
	table.print();
	return true;
}

int main() {
	test();
	return 0;
}

