/*
 * utils.h
 *
 *  Created on: Jan 1, 2016
 *      Author: Polina
 */

#ifndef UTILS_H_
#define UTILS_H_
#include <stdlib.h>
#include "AVLTree.h"
#include "Student.h"

#include <stdio.h>
#include <iostream>
using namespace std;

template<class T, class U>
class UpgradeStudentHashTable {
	int studyGroupID;
	int factor;

public:
	UpgradeStudentHashTable(int studyGroupID,int factor) :
							studyGroupID(studyGroupID),factor(factor){
	}

	void operator()(BinaryNode<T, U>* node) const {
		AVLNode<T, U>* AVLnode = dynamic_cast<AVLNode<T, U>*>(node);
		if (AVLnode == NULL) {
					return;
		}

		Student* student = AVLnode->value;

		if((*student).getStudyGroup()==studyGroupID){
				int newGrade=(student->getAverage())*factor;
				if(newGrade > 100){
						newGrade = 100;
						student->setAverage(newGrade);
				}
		}
	}
};

template<class T, class U>
class UpgradeStudentAVLTree {
	int studyGroupID;
	int factor;
	int *maxGrade;
	int *maxID;
	int* histogram;

public:
	UpgradeStudentAVLTree(int studyGroupID,int factor,int* maxGrade,int* maxID , int* histogram):
							studyGroupID(studyGroupID),factor(factor),
							maxGrade(maxGrade),maxID(maxID),histogram(histogram){
	}

	void operator()(BinaryNode<T, U>* node) const {
		AVLNode<T, U>* AVLnode = dynamic_cast<AVLNode<T, U>*>(node);
		if (AVLnode == NULL) {
					return;
		}
		Student* student = AVLnode->value;
		int newGrade=0;
		if(student->getStudyGroup() == studyGroupID){
				histogram[student->getAverage()]--;
				newGrade=(student->getAverage())*factor;
				if(newGrade > 100){
						newGrade = 100;
				}
				student->setAverage(newGrade);
				histogram[newGrade]++;
		}
		if(newGrade > *maxGrade ||
				(newGrade == *maxGrade && student->getID() < *maxID)){
			*maxGrade = newGrade;
			*maxID = student->getID();
		}
	}
};


#endif /* UTILS_H_ */
