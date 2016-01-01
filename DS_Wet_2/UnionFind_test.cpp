/*
 * UnionFind_test.cpp
 *
 *  Created on: Dec 30, 2015
 *      Author: Polina
 */
#include "UnionFind.h"
#include "DS_test_utils.h"
#include "stdbool.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

/*
std::string location;
using namespace std;

bool testCreate(){
	cout<<"------ START ------ testCreate ------ START ------" <<endl;
	//create a new UnionFind Structure
	UnionFind uf(7);
	cout<<"------ END ------ testCreate ------ END ------" <<endl;
	return true;
}

bool testUniteAndFind1(){
	cout<<"------ START ------ testUniteAndFind1 ------ START ------" <<endl;
	//create a new UnionFind Structure
	UnionFind uf(7);
	//check all groups created with 1 member
	ASSERT_EQUALS(uf.find(0),0);
	ASSERT_EQUALS(uf.find(1),1);
	ASSERT_EQUALS(uf.find(2),2);
	ASSERT_EQUALS(uf.find(3),3);
	ASSERT_EQUALS(uf.find(4),4);
	ASSERT_EQUALS(uf.find(5),5);
	ASSERT_EQUALS(uf.find(6),6);

	//unite a group with itself
	ASSERT_NO_THROW(uf.unite(2,2));
	//nothing should be changed
	ASSERT_EQUALS(uf.find(0),0);
	ASSERT_EQUALS(uf.find(1),1);
	ASSERT_EQUALS(uf.find(2),2);
	ASSERT_EQUALS(uf.find(3),3);
	ASSERT_EQUALS(uf.find(4),4);
	ASSERT_EQUALS(uf.find(5),5);
	ASSERT_EQUALS(uf.find(6),6);

	//unite two valid groups
	ASSERT_NO_THROW(uf.unite(5,3));
	//check union - parent should be 5 for 5 and 3
	ASSERT_EQUALS(uf.find(0),0);
	ASSERT_EQUALS(uf.find(1),1);
	ASSERT_EQUALS(uf.find(2),2);
	ASSERT_EQUALS(uf.find(3),5);
	ASSERT_EQUALS(uf.find(4),4);
	ASSERT_EQUALS(uf.find(5),5);
	ASSERT_EQUALS(uf.find(6),6);

	//unite all to 5
	ASSERT_NO_THROW(uf.unite(3,4));
	ASSERT_EQUALS(uf.find(4),5);

	ASSERT_NO_THROW(uf.unite(4,2));
	ASSERT_EQUALS(uf.find(2),5);

	ASSERT_NO_THROW(uf.unite(2,6));
	ASSERT_EQUALS(uf.find(6),5);

	ASSERT_NO_THROW(uf.unite(6,1));
	ASSERT_EQUALS(uf.find(1),5);

	ASSERT_NO_THROW(uf.unite(5,0));
	ASSERT_EQUALS(uf.find(0),5);

	//check union - parent should be 5 for everyone
	ASSERT_EQUALS(uf.find(0),5);
	ASSERT_EQUALS(uf.find(1),5);
	ASSERT_EQUALS(uf.find(2),5);
	ASSERT_EQUALS(uf.find(3),5);
	ASSERT_EQUALS(uf.find(4),5);
	ASSERT_EQUALS(uf.find(5),5);
	ASSERT_EQUALS(uf.find(6),5);
	cout<<"------ END ------ testUniteAndFind1 ------ END ------" <<endl;
	return true;
}

bool testUniteAndFind2(){
	cout<<"------ START ------ testUniteAndFind2 ------ START ------" <<endl;
	//create a new UnionFind Structure
	UnionFind uf(15);
	ASSERT_EQUALS(uf.find(0),0);
	ASSERT_EQUALS(uf.find(1),1);
	ASSERT_EQUALS(uf.find(2),2);
	ASSERT_EQUALS(uf.find(3),3);
	ASSERT_EQUALS(uf.find(4),4);
	ASSERT_EQUALS(uf.find(5),5);
	ASSERT_EQUALS(uf.find(6),6);
	ASSERT_EQUALS(uf.find(7),7);
	ASSERT_EQUALS(uf.find(8),8);
	ASSERT_EQUALS(uf.find(9),9);
	ASSERT_EQUALS(uf.find(10),10);
	ASSERT_EQUALS(uf.find(11),11);
	ASSERT_EQUALS(uf.find(12),12);
	ASSERT_EQUALS(uf.find(13),13);
	ASSERT_EQUALS(uf.find(14),14);

	//make unions

	ASSERT_NO_THROW(uf.unite(11,14));
	ASSERT_EQUALS(uf.find(14),11);
	ASSERT_NO_THROW(uf.unite(11,13));
	ASSERT_EQUALS(uf.find(13),11);
	ASSERT_NO_THROW(uf.unite(0,11));

	ASSERT_NO_THROW(uf.unite(10,9));
	ASSERT_NO_THROW(uf.unite(9,7));

	ASSERT_NO_THROW(uf.unite(12,8));
	ASSERT_NO_THROW(uf.unite(12,6));
	ASSERT_NO_THROW(uf.unite(6,1));
	ASSERT_NO_THROW(uf.unite(6,4));

	ASSERT_NO_THROW(uf.unite(5,3));
	ASSERT_NO_THROW(uf.unite(5,2));

	//final state shold be :
	// 0 - 11,13,14
	// 10 - 7,9
	// 12 - 6,4,1,8
	// 5 - 3,2

	ASSERT_EQUALS(uf.find(0),0);
	ASSERT_EQUALS(uf.find(1),12);
	ASSERT_EQUALS(uf.find(2),5);
	ASSERT_EQUALS(uf.find(3),5);
	ASSERT_EQUALS(uf.find(4),12);
	ASSERT_EQUALS(uf.find(5),5);
	ASSERT_EQUALS(uf.find(6),12);
	ASSERT_EQUALS(uf.find(7),10);
	ASSERT_EQUALS(uf.find(8),12);
	ASSERT_EQUALS(uf.find(9),10);
	ASSERT_EQUALS(uf.find(10),10);
	ASSERT_EQUALS(uf.find(11),0);
	ASSERT_EQUALS(uf.find(12),12);
	ASSERT_EQUALS(uf.find(13),0);
	ASSERT_EQUALS(uf.find(14),0);

	cout<<"------ END ------ testUniteAndFind2 ------ END ------" <<endl;
	return true;
}

int main(){
	RUN_TEST(testCreate);
	RUN_TEST(testUniteAndFind1);
	RUN_TEST(testUniteAndFind2);

	return 0;
}
*/
