/*
 * BinSearchTree.h
 *
 *  Created on: Nov 12, 2015
 *      Author: Ron
 */

#ifndef BINSEARCHTREE_H_
#define BINSEARCHTREE_H_

#include "assert.h"
#include <iostream>
#include <stdlib.h>

template<class T, class U> class BinaryNode;
template<class T, class U> class BinSearchTree;

// ########################################################################
// -------------------------- EXCEPTIONS ----------------------------------
// ########################################################################

namespace BinaryTreeExceptions {
class ElementAlreadyExists {
};
}

// ########################################################################
// ----------------------------- NODE -------------------------------------
// ########################################################################

template<class T, class U>
class BinaryNode {
public:
	T* key;
	U* value;
	BinaryNode* left;
	BinaryNode* right;
	BinaryNode* father;
public:
	/*
	 * BinaryNode<T, U> - Constructor - Creates a new empty node with NULL data,
	 * 									key and pointers to children and parent
	 */
	BinaryNode<T, U>();

	/*
	 * BinaryNode<T, U> - Constructor - Creates a new node with the received
	 * 									data and key  and NULL pointers to
	 * 									children and parents
	 */
	BinaryNode<T, U>(const T& key, const U& value);

	/*
	 * BinaryNode<T, U> - Copy Constructor - copies the data ,key and
	 * 										  children & parents pointers from
	 * 										  the received node to the current
	 * 										  node
	 */
	BinaryNode<T, U>(const BinaryNode<T, U>& node);

	/*
	 * ~BinaryNode<T, U> - Destructor - deletes the data and key the node holds
	 */
	virtual ~BinaryNode<T, U>() {
		delete key;
		delete value;
	}

	/*
	 * hasLeft - if the current node has a pointer to a Left node returns true
	 * 			 otherwise returns false
	 */
	bool hasLeft() const;

	/*
	 * hasRight - if the current node has a pointer to a Right node returns
	 * 			  true , otherwise returns false
	 */
	bool hasRight() const;

	/*
	 * hasFather - if the current node has a pointer to a Parent node returns
	 * 			   true , otherwise returns false
	 */
	bool hasFather() const;

	/*
	 * isLeft -if the node has a parent and it is the left child of its parent
	 * 		   returns true , otherwise return false
	 */
	bool isLeft() const;

	/*
	 * isLeaf - if the current node has no children returns true , otherwise
	 * 			returns false
	 */
	bool isLeaf() const;

	/*
	 * hasOneSon - if the current node has one child (only a left one or only
	 * 			   a right one) rwturns true , otherwise return false
	 */
	bool hasOneSon() const;

	/*
	 * hasTwoSons - if the current node has two children (bothe left and right)
	 * 				returns true , otherwise returns false
	 */
	bool hasTwoSons() const;

	/*
	 * numOfSons - returns the number of children the current node has
	 */
	int numOfSons() const;

	/*
	 * getValue - returns a pointer to the value that is currently stored in
	 * 			  the node
	 */
	U* getValue();

	/*
	 * getValue - returns a pointer to the value currently stored in the node
	 */
	const U* getValue() const;

	/*
	 * getKey - returns a pointer to the key of the data that is currently
	 * 			stored in the node , the pointer to the key is a const ,
	 * 			can't be changed
	 */
	const T* getKey() const;

	/*
	 * getLeft - returns the pointer to the left son of the current node
	 */
	BinaryNode<T, U>* getLeft();

	/*
	 * getLeft -  returns the pointer to the left son of the current node
	 */
	const BinaryNode<T, U>* getLeft() const;

	/*
	 * getRight - returns a pointer to the right son of the current node
	 */
	BinaryNode<T, U>* getRight();

	/*
	 * getRight - returns a pointer to the right son of the current node
	 */
	const BinaryNode<T, U>* getRight() const;

	/*
	 * getFather - returns a pointer to the parent of the current node
	 */
	BinaryNode<T, U>* getFather();

	/*
	 * getFather - returns a pointer to the parent of the current node
	 */
	const BinaryNode<T, U>* getFather() const;

	/*
	 * setLeft - sets the left son of the current node to be the received node
	 * 			 asserting the current node isn't the recieved node
	 */
	void setLeft(BinaryNode<T, U>* left);

	/*
	 * setRight - sets the right son of the current node to be the reeived node
	 * 			  asserting the current node isn't the received node
	 */
	void setRight(BinaryNode<T, U>* right);

	/*
	 * setKey - set the key of the node
	 */
	void setKey(T key);

	/*
	 * setValue - set the value of  the node
	 */
	void setValue(U value);

	/*
	 * operator< - compares between two nodes by key , returns true if the
	 * 				current nodes key is smaller then the key of the received
	 * 				node
	 */
	bool operator<(BinaryNode<T, U>& node);

	/*
	 *  operator== - compare between two nodes , returns true if both nodes are
	 *  			 equal or false otherwise
	 *
	 *  			 two nodes are considered equal when both the data and keys
	 *  			 are equal
	 */
	bool operator==(const BinaryNode<T, U>& node);

	/*
	 *  operator* - Dereferences the current node . returns the value of the
	 *  			current node , if its empty returns NULL
	 */
	U& operator*();

	/*
	 *  operator= - Assignment operator - copies the value & key of the
	 *  								  received node to the current node
	 */
	BinaryNode<T, U>& operator=(const BinaryNode<T, U>& node);
};

template<class T, class U>
BinaryNode<T, U>::BinaryNode() :
		key(NULL), value(NULL), left(NULL), right(NULL), father(
		NULL) {
}

template<class T, class U>
BinaryNode<T, U>::BinaryNode(const T& key, const U& value) :
		key(new T(key)), value(new U(value)), left(NULL), right(NULL), father(
		NULL) {
}

template<class T, class U>
BinaryNode<T, U>::BinaryNode(const BinaryNode<T, U>& node) {
	key = node.key;
	value = node.value;
	left = node.left;
	right = node.right;
	father = node.father;
}

template<class T, class U>
bool BinaryNode<T, U>::hasFather() const {
	return father != NULL;
}

template<class T, class U>
bool BinaryNode<T, U>::hasLeft() const {
	return left != NULL;
}

template<class T, class U>
bool BinaryNode<T, U>::hasRight() const {
	return right != NULL;
}

template<class T, class U>
bool BinaryNode<T, U>::isLeft() const {
	return (hasFather() && father->getLeft() == this);
}

template<class T, class U>
bool BinaryNode<T, U>::isLeaf() const {
	return (numOfSons() == 0);
}

template<class T, class U>
bool BinaryNode<T, U>::hasOneSon() const {
	return (numOfSons() == 1);
}

template<class T, class U>
bool BinaryNode<T, U>::hasTwoSons() const {
	return (numOfSons() == 2);
}

template<class T, class U>
const T* BinaryNode<T, U>::getKey() const {
	return key;
}

template<class T, class U>
const U* BinaryNode<T, U>::getValue() const {
	return value;
}

template<class T, class U>
U* BinaryNode<T, U>::getValue() {
	return value;
}

template<class T, class U>
BinaryNode<T, U>* BinaryNode<T, U>::getLeft() {
	return left;
}

template<class T, class U>
const BinaryNode<T, U>* BinaryNode<T, U>::getLeft() const {
	return left;
}

template<class T, class U>
BinaryNode<T, U>* BinaryNode<T, U>::getRight() {
	return right;
}

template<class T, class U>
const BinaryNode<T, U>* BinaryNode<T, U>::getRight() const {
	return right;
}

template<class T, class U>
BinaryNode<T, U>* BinaryNode<T, U>::getFather() {
	return father;
}

template<class T, class U>
const BinaryNode<T, U>* BinaryNode<T, U>::getFather() const {
	return father;
}

template<class T, class U>
void BinaryNode<T, U>::setLeft(BinaryNode<T, U>* left) {
	assert(this != left);
	this->left = left;
	if (left != NULL) {
		left->father = this;
	}
}

template<class T, class U>
void BinaryNode<T, U>::setRight(BinaryNode<T, U>* right) {
	assert(this != right);
	this->right = right;
	if (right != NULL) {
		right->father = this;
	}
}

template<class T, class U>
void BinaryNode<T, U>::setKey(T key) {
	delete this->key;
	this->key = new T(key);
}

template<class T, class U>
void BinaryNode<T, U>::setValue(U value) {
	delete this->value;
	this->value = new U(value);
}

template<class T, class U>
bool BinaryNode<T, U>::operator==(const BinaryNode<T, U>& node) {
	return *(key) == *(node.key) && *(value) == *(node.value);
}

template<class T, class U>
bool BinaryNode<T, U>::operator<(BinaryNode<T, U>& node) {
	return *(key) < *(node.key);
}

template<class T, class U>
U& BinaryNode<T, U>::operator*() {
	if (value == NULL) {
		return NULL;
	}
	return *(value);
}

template<class T, class U>
BinaryNode<T, U>& BinaryNode<T, U>::operator=(const BinaryNode<T, U>& node) {
	if (this == &node) {
		return *this;
	}
	this->key = new T(node.key);
	this->value = new U(node.value);
	return *this;
}

template<class T, class U>
int BinaryNode<T, U>::numOfSons() const {
	int sons = 0;
	if (left != NULL) {
		++sons;
	}
	if (right != NULL) {
		++sons;
	}
	return sons;
}

// ########################################################################
// ------------------------- BINSEARCHTREE --------------------------------
// ########################################################################

template<class T, class U>
class BinSearchTree {
public:
	/*
	 * BinSearchTree - Constructor - creates an empty Binary tree , with an
	 * 								 empty root Node
	 */
	BinSearchTree();

	/*
	 * ~BinSearchTree - Destructor - deletes the tree with all its'
	 * 								 nodes an data stored in them
	 */
	virtual ~BinSearchTree();

	/*
	 * insert - adds a node with the received key and value to the current tree
	 * 			this function willl be overriden in each tree according to the
	 * 			type of the tree
	 */
	virtual void insert(const T& key, const U& value);

	/*
	 * remove - removes a node with the received key from the current tree
	 * 			this function willl be overriden in each tree according to the
	 * 			type of the tree
	 */
	virtual void remove(const T& key);

	/*
	 *	contains - returns true if the current tree contains a node with the
	 *			   received key , otherwise returns false
	 */
	bool contains(const T& key);

	/*
	 * getSize - returns the number of nodes in the tree
	 */
	int getSize();

	/*
	 * clear - deletes the tree with all its' nodes an data stored in them
	 */
	void clear();

	/*
	 * isEmpty - checks if the tree is empty (has no nodes) , if so returns
	 * 			  true , otherwise returns false
	 */
	bool isEmpty();

	/*
	 * get - returns a pointer to the value of the node in the tree with the
	 * 		 received key
	 * 		 if a node with the received key doesn't exist returns NULL
	 */

	U* get(const T& key);

	/*
	 * getFather - returns a pointer to the Parent node of the node with the
	 * 			   received data ,if the node with the received key  doesn't
	 * 			   exist return a pointer to the last node who could be its'
	 * 			   parent
	 */
	U* getFather(const T& key);

	/*
	 * getMax - return the value of the maximal node
	 */
	U* getMax();

	/*
	 * getMin - return the value of the minimal node
	 */
	U* getMin();

	/*
	 * preOrder - receives a function to be performed on all nodes in the tree
	 *
	 * 			  performs the function on all nodes in the tree in the
	 * 			  following order :
	 * 			       1.root
	 * 			       2.left subtree
	 * 			       3.right subtree
	 */
	template<class Function>
	void preOrder(const Function& f);

	/*
	 * inOrder - receives a function to be performed on all nodes in the tree
	 *
	 * 			  performs the function on all nodes in the tree in the
	 * 			  following order :
	 * 			       1.left subtree
	 * 			       2.root
	 * 			       3.right subtree
	 */
	template<class Function>
	void inOrder(const Function& f);

	/*
	 * postOrder - receives a function to be performed on all nodes in the tree
	 *
	 * 			  performs the function on all nodes in the tree in the
	 * 			  following order :
	 * 			       1.left subtree
	 * 			       2.right subtree
	 * 			       3.root
	 */
	template<class Function>
	void postOrder(const Function& f);

	/*
	 * TreeToArray - fills the array whose pointer is received with values of
	 * 				 nodes in the tree
	 *
	 *	@param array - pointer to the array to be filled
	 */
	void TreeToArray(U* array) const;

	/*
	 * TreeToArray_aux - convert the current tree to an array containing the
	 * 					 values of the nodes
	 *
	 * @param array - pointer to the array to fill
	 * @param node - the root node of the tree to convert into array
	 * @param index - pointer to a variable holding the index of the current
	 * 				  place to fill in the array
	 */
	void TreeToArray_aux(U* array, BinaryNode<T, U>* node, int* index) const;

	/*
	 * arrayToTree - converts an array to tree , both arrays should be aligned
	 * 				 in both arrays the first element should be of the same
	 * 				 first node to be added in the tree
	 *
	 * @param keyArray - array of keys of nodes to add to the tree
	 * @param valueArray - array of values of nodes to add to the tree
	 */
	void arrayToTree(T* keyArray, U* valueArray);

	/*
	 *	arrayToTree_aux - converts an array to tree
	 *
	 *	@param keyArray - array containing node keys to fill into the tree
	 *	@param array - array containing node values to fill into the tree
	 *	@param node - the root node of the tree to fill from array
	 *	@param index - pointer to a variable holding the index of the current
	 * 				   place to read in the array
	 */
	void arrayToTree_aux(T* keyArray, U* array, BinaryNode<T, U>* node,
			int* index);

protected:
	int size;
	BinaryNode<T, U>* root;
	/*
	 * setRoot - sets the root of the current tree to be the received node
	 */
	void setRoot(BinaryNode<T, U>* node);

	/*
	 * deleteTree - deletes all the nodes in the tree
	 */
	void deleteTree(BinaryNode<T, U>* node);

	/*
	 * removeNode - removes from the tree the node of the received pointr
	 */
	BinaryNode<T, U>* removeNode(BinaryNode<T, U>* node);

	/*
	 * pre_aux - receives a pointer to the first node in the tree and a
	 * 			 function that can be performed on the node
	 *
	 * 			 performs the function on all nodes in the tree in "pre-order" :
	 * 			 1.root
	 * 			 2.left subtree
	 * 			 3.right subtree
	 */
	template<class Function>
	void pre_aux(BinaryNode<T, U>* node, Function& f);

	/*
	 * in_aux - receives a pointer to the first node in the tree and a
	 * 			function that can be performed on the node
	 *
	 * 			 performs the function on all nodes in the tree in "in-order" :
	 * 			 1.left subtree
	 * 			 2.root
	 * 			 3.right subtree
	 */
	template<class Function>
	void in_aux(BinaryNode<T, U>* node, Function& f);

	/*
	 * post_aux - receives a pointer to the first node in the tree and a
	 * 			  function that can be performed on the node
	 *
	 * 			 performs the function on all nodes in the tree in "post-order" :
	 * 			 1.left subtree
	 * 			 2.right subtree
	 * 			 3.root
	 */
	template<class Function>
	void post_aux(BinaryNode<T, U>* node, Function& f);

	/*
	 * removeLeaf - removes from the tree the node of the received pointer
	 * 				the node that is sent must be a leaf
	 * 				(has no children)
	 */
	void removeLeaf(BinaryNode<T, U>* nodeToRemove);

	/*
	 * removeOneSon - removes from the tree the node of the received pointer
	 * 				  the node that is sent must have only one child
	 * 				  (either a left one or a right one - not both)
	 */
	void removeOneSon(BinaryNode<T, U>* nodeToRemove);

	/*
	 * removeTwoSons - removes from the tree the node of the received pointer
	 * 				   the node that is sent must have two children
	 * 				   (both the left and the right)
	 *
	 * 				   returns a pointer to the parent of the node that
	 * 				   replaced the node to be removed
	 */
	BinaryNode<T, U>* removeTwoSons(BinaryNode<T, U>* nodeToRemove);

	/*
	 * getRoot - returns a pointer to the croot of the current tree
	 */
	BinaryNode<T, U>* getRoot() const ;

	/*
	 * findParent - returns a pointer to the parent of the node with the
	 * 				received key
	 * 				if a node with such key doesn't exist returns a pointer to
	 * 				the node who could be its' parent
	 */
	BinaryNode<T, U>* findParent(const T& data);

	/*
	 * find - returns a pointer to the node with the received key , if such
	 * 		  node doesn't exist return NULL
	 */
	BinaryNode<T, U>* find(const T& data);

	/*
	 * insertNode -  adds to the current tree the received node .  returns a
	 * 				 pointer to the  new node added to the tree
	 */
	BinaryNode<T, U>* insertNode(BinaryNode<T, U>* node);
};

template<class T, class U>
BinSearchTree<T, U>::BinSearchTree() :
		size(0), root(NULL) {
}

template<class T, class U>
BinSearchTree<T, U>::~BinSearchTree() {
	deleteTree(root);
}

template<class T, class U>
bool BinSearchTree<T, U>::isEmpty() {
	return size == 0;
}

template<class T, class U>
U* BinSearchTree<T, U>::get(const T& key) {
	if (isEmpty()) {
		return NULL;
	}
	BinaryNode<T, U>* node = find(key);
	if (node != NULL) {
		return node->getValue();
	}
	return NULL;
}

template<class T, class U>
U* BinSearchTree<T, U>::getFather(const T& key) {
	if (isEmpty()) {
		return NULL;
	}
	BinaryNode<T, U>* node = findParent(key);
	if (node != NULL) {
		return node->getValue();
	}
	return NULL;
}

template<class T, class U>
U* BinSearchTree<T, U>::getMax() {
	if (isEmpty()) {
		return NULL;
	}
	BinaryNode<T, U>* max = getRoot();
	while (max->getRight()) {
		max = max->getRight();
	}
	return max->getValue();
}

template<class T, class U>
U* BinSearchTree<T, U>::getMin() {
	if (isEmpty()) {
		return NULL;
	}
	BinaryNode<T, U>* min = getRoot();
	while (min->getLeft()) {
		min = min->getLeft();
	}
	return min->getValue();
}

template<class T, class U>
int BinSearchTree<T, U>::getSize() {
	return size;
}

template<class T, class U>
void BinSearchTree<T, U>::setRoot(BinaryNode<T, U>* node) {
	root = node;
}

template<class T, class U>
void BinSearchTree<T, U>::insert(const T& key, const U& value) {
	BinaryNode<T, U> *toAdd = new BinaryNode<T, U>(key, value);
	insertNode(toAdd);
}

template<class T, class U>
BinaryNode<T, U>* BinSearchTree<T, U>::insertNode(BinaryNode<T, U>* toAdd) {
	if (isEmpty()) {
		root = toAdd;
		++size;
		return root;
	}
	BinaryNode<T, U> *node = findParent(*(toAdd->key));
	if (*node < *toAdd) {
		node->setRight(toAdd);
		++size;
		return node->getRight();
	} else {
		node->setLeft(toAdd);
		++size;
		return node->getLeft();
	}
	return NULL;
}

template<class T, class U>
BinaryNode<T, U>* BinSearchTree<T, U>::removeNode(
		BinaryNode<T, U>* nodeToRemove) {
	if (isEmpty()) {
		return NULL;
	}
	BinaryNode<T, U>* parent = nodeToRemove->getFather();
	if (nodeToRemove->isLeaf()) {
		removeLeaf(nodeToRemove);
		return parent;
	}
	if (nodeToRemove->hasOneSon()) {
		removeOneSon(nodeToRemove);
		return parent;
	}
	return removeTwoSons(nodeToRemove);
}

template<class T, class U>
void BinSearchTree<T, U>::remove(const T& key) {
	if (isEmpty() || contains(key) == false) {
		return;
	}

	BinaryNode<T, U> *nodeToRemove = find(key);
	removeNode(nodeToRemove);
}

template<class T, class U>
void BinSearchTree<T, U>::removeLeaf(BinaryNode<T, U>* nodeToRemove) {
	if (nodeToRemove->hasFather()) {
		if (nodeToRemove->isLeft()) {
			nodeToRemove->father->left = NULL;
		} else {
			nodeToRemove->father->right = NULL;
		}
		delete (nodeToRemove);
		--size;
	} else {
		delete (nodeToRemove);
		--size;
		root = NULL;
	}
}

template<class T, class U>
void BinSearchTree<T, U>::removeOneSon(BinaryNode<T, U>* nodeToRemove) {
	if (nodeToRemove->hasFather()) {
		if (nodeToRemove->isLeft()) {
			if (nodeToRemove->hasLeft()) {
				nodeToRemove->father->left = nodeToRemove->left;
				nodeToRemove->left->father = nodeToRemove->father;
			} else {
				nodeToRemove->father->left = nodeToRemove->right;
				nodeToRemove->right->father = nodeToRemove->father;
			}
		} else {
			if (nodeToRemove->left != NULL) {
				nodeToRemove->father->right = nodeToRemove->left;
				nodeToRemove->left->father = nodeToRemove->father;
			} else {
				nodeToRemove->father->right = nodeToRemove->right;
				nodeToRemove->right->father = nodeToRemove->father;
			}
		}
	} else {
		if (nodeToRemove->left != NULL) {
			root = nodeToRemove->left;
			nodeToRemove->left->father = NULL;
		} else {
			root = nodeToRemove->right;
			nodeToRemove->right->father = NULL;
		}
	}
	delete (nodeToRemove);
	--size;
}

template<class T, class U>
BinaryNode<T, U>* BinSearchTree<T, U>::removeTwoSons(
		BinaryNode<T, U>* nodeToRemove) {
	BinaryNode<T, U> *replacement = nodeToRemove;
	replacement = replacement->right;
	while (replacement->left != NULL) {
		replacement = replacement->left;
	}
	BinaryNode<T, U>* toReturn = replacement->getFather();
	delete nodeToRemove->key;
	nodeToRemove->key = new T(*replacement->key);
	delete nodeToRemove->value;
	nodeToRemove->value = new U(*replacement->value);
	if (replacement->isLeaf()) {
		removeLeaf(replacement);
		return toReturn;
	}
	if (replacement->hasOneSon()) {
		removeOneSon(replacement);
		return toReturn;
	}
	return toReturn;
}

template<class T, class U>
BinaryNode<T, U>* BinSearchTree<T, U>::findParent(const T& key) {
	if (isEmpty()) {
		return NULL;
	}
	BinaryNode<T, U> *node = getRoot();
	BinaryNode<T, U> *parent = node;
	while (node != NULL && node->getKey() && *(node->key) != key) {
		parent = node;
		if (*(node->key) < key) {
			node = node->right;
		} else {
			node = node->left;
		}
	}
	return parent;
}

template<class T, class U>
BinaryNode<T, U>* BinSearchTree<T, U>::find(const T& key) {
	if (isEmpty()) {
		return NULL;
	}
	BinaryNode<T, U> *node = getRoot();
	while (node != NULL && node->getKey() && *node->getKey() != key) {
		if (*(node->key) < key) {
			node = node->right;
		} else {
			node = node->left;
		}
	}
	if (node != NULL && *(node->key) == key) {
		return node;
	}
	return NULL;
}

template<class T, class U>
bool BinSearchTree<T, U>::contains(const T& key) {
	if (isEmpty()) {
		return false;
	}
	BinaryNode<T, U> *node = find(key);
	if (node != NULL && *(node->key) == key) {
		return true;
	}
	return false;
}

template<class T, class U>
void BinSearchTree<T, U>::clear() {
	deleteTree(root);
	root = NULL;
	size = 0;
}

template<class T, class U>
void BinSearchTree<T, U>::deleteTree(BinaryNode<T, U>* node) {
	if (node == NULL) {
		return;
	}
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}

template<class T, class U>
BinaryNode<T, U>* BinSearchTree<T, U>::getRoot() const {
	return root;
}

template<class T, class U>
template<class Function>
void BinSearchTree<T, U>::preOrder(const Function& f) {
	if (isEmpty()) {
		return;
	}
	pre_aux(root, f);
}

template<class T, class U>
template<class Function>
void BinSearchTree<T, U>::pre_aux(BinaryNode<T, U>* node, Function& f) {
	if (node == NULL) {
		return;
	}
	f(node);
	pre_aux(node->getLeft(), f);
	pre_aux(node->getRight(), f);
}

template<class T, class U>
template<class Function>
void BinSearchTree<T, U>::inOrder(const Function& f) {
	if (isEmpty()) {
		return;
	}
	in_aux(root, f);
}

template<class T, class U>
template<class Function>
void BinSearchTree<T, U>::in_aux(BinaryNode<T, U>* node, Function& f) {
	if (node == NULL) {
		return;
	}
	in_aux(node->getLeft(), f);
	f(node);
	in_aux(node->getRight(), f);
}

template<class T, class U>
template<class Function>
void BinSearchTree<T, U>::postOrder(const Function& f) {
	if (isEmpty()) {
		return;
	}
	post_aux(root, f);
}

template<class T, class U>
template<class Function>
void BinSearchTree<T, U>::post_aux(BinaryNode<T, U>* node, Function& f) {
	if (node == NULL) {
		return;
	}
	post_aux(node->getLeft(), f);
	post_aux(node->getRight(), f);
	f(node);
}

template<class T, class U>
void BinSearchTree<T, U>::TreeToArray(U* arr) const{
	assert(arr);
	int index = 0;
	TreeToArray_aux(arr, getRoot(), &index);
}

template<class T, class U>
void BinSearchTree<T, U>::TreeToArray_aux(U* array, BinaryNode<T, U>* node,
		int* index) const {
	if (node == NULL) {
		return;
	}
	TreeToArray_aux(array, node->getLeft(), index);
	array[*index] = U(*node->getValue());
	*index = *index + 1;
	TreeToArray_aux(array, node->getRight(), index);
}

template<class T, class U>
void BinSearchTree<T, U>::arrayToTree(T* keyArray, U* valueArray) {
	assert(keyArray && valueArray);
	int index = 0;
	arrayToTree_aux(keyArray, valueArray, getRoot(), &index);
}

template<class T, class U>
void BinSearchTree<T, U>::arrayToTree_aux(T* keyArray, U* array,
		BinaryNode<T, U>* node, int* index) {
	if (node == NULL) {
		return;
	}
	arrayToTree_aux(keyArray, array, node->getLeft(), index);
	node->setValue(array[*index]);
	node->setKey(keyArray[*index]);
	*index = *index + 1;
	arrayToTree_aux(keyArray, array, node->getRight(), index);
}

#endif /* BINSEARCHTREE_H_ */
