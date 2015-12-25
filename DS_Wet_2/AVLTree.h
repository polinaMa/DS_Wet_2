/*
 * AVLTree.h
 *
 *  Created on: Nov 14, 2015
 *      Author: Ron
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "BinSearchTree.h"

template<class T, class U>
class AVLNode: public BinaryNode<T, U> {
	int height;
private:

public:
	/*
	 * AVLNode<T, U> - Constructor - create a new node for an AVL tree with the
	 * 								 received height
	 */
	AVLNode<T, U>(int height);

	/*
	 * AVLNode<T, U> - Constructor - create a new node for an AVL tree with the
	 * 								 received key&value
	 */
	AVLNode<T, U>(const T& key, const U& value);

	/*
	 * bfactor - returns the bfactor of the current node
	 *
	 * 			bfactor = left_barch_height - right_branch_height
	 */
	int bfactor() const;

	/*
	 * getHeight - returns the height of the whole avl tree
	 */
	int getHeight() const;

	/*
	 * setHeight - set the height of the node
	 */
	void setHeight(int height);

	/*
	 * fixHeight - updates the height of the current node according to the
	 * 			   height of its' right and left branches
	 */
	void fixHeight();

	/*
	 * isBalanced - if node is balanced returns true , otherwise returns false .
	 *
	 * 				a node is balanced when its' bfactor is either -1,0,or 1
	 */
	bool isBalanced() const;

	/*
	 * getLeftHeight -  returns the height of the left branch of the current
	 * 					node , if there isn't a left son returns -1
	 */
	int getLeftHeight() const;

	/*
	 * getRightHeight - returns the height of the right branch of the current
	 * 					node , if there isn't a right son returns -1
	 */
	int getRightHeight() const;

	/*
	 * getAVLLeft - returns a const pointer to the left child of the
	 * 				current node
	 *
	 */
	const AVLNode<T, U>* getAVLLeft() const;

	/*
	 * getAVLLeft - returns a pointer to the left child of the
	 * 				current node
	 *
	 */
	AVLNode<T, U>* getAVLLeft();

	/*
	 * getAVLRight - returns a const pointer to the right child of the
	 * 				current node
	 *
	 */
	const AVLNode<T, U>* getAVLRight() const;

	/*
	 * getAVLRight - returns a pointer to the right child of the
	 * 				current node
	 *
	 */
	AVLNode<T, U>* getAVLRight();

	/*
	 * getAVLFather - returns a const pointer to the parent of the
	 * 				  current node
	 *
	 */
	const AVLNode<T, U>* getAVLFather() const;

	/*
	 * getAVLFather - returns a pointer to the parent of the
	 * 				  current node
	 *
	 */
	AVLNode<T, U>* getAVLFather();

	/*
	 * make a complete tree of given height
	 */
	void completeTree(int height);
};

template<class T, class U>
AVLNode<T, U>::AVLNode(int height) {
	this->height = height;
}

template<class T, class U>
AVLNode<T, U>::AVLNode(const T& key, const U& value) :
		BinaryNode<T, U>(key, value), height(0) {

}

template<class T, class U>
void AVLNode<T, U>::completeTree(int height) {
	if (height < 0) {
		return;
	}
	this->setLeft(new AVLNode<T, U>(height));
	this->setRight(new AVLNode<T, U>(height));
	AVLNode<T, U>* leftNode = this->getAVLLeft();
	leftNode->completeTree(height - 1);
	AVLNode<T, U>* rightNode = this->getAVLRight();
	rightNode->completeTree(height - 1);
}

template<class T, class U>
const AVLNode<T, U>* AVLNode<T, U>::getAVLLeft() const {
	assert(
			(this->getLeft() == NULL ||
				dynamic_cast<const AVLNode<T, U>*>(this->getLeft()) != NULL));
	return dynamic_cast<const AVLNode<T, U>*>(this->getLeft());
}

template<class T, class U>
AVLNode<T, U>* AVLNode<T, U>::getAVLLeft() {
	assert(
			(this->getLeft() == NULL ||
					dynamic_cast<AVLNode<T, U>*>(this->getLeft()) != NULL));

	return dynamic_cast<AVLNode<T, U>*>(this->getLeft());
}

template<class T, class U>
const AVLNode<T, U>* AVLNode<T, U>::getAVLRight() const {
	assert(
			(this->getRight() == NULL ||
				dynamic_cast<const AVLNode<T, U>*>(this->getRight()) != NULL));
	return dynamic_cast<const AVLNode<T, U>*>(this->getRight());
}

template<class T, class U>
AVLNode<T, U>* AVLNode<T, U>::getAVLRight() {
	assert(
			(this->getRight() == NULL ||
					dynamic_cast<AVLNode<T, U>*>(this->getRight()) != NULL));
	return dynamic_cast<AVLNode<T, U>*>(this->getRight());
}

template<class T, class U>
const AVLNode<T, U>* AVLNode<T, U>::getAVLFather() const {
	assert(
			(this->getFather() == NULL ||
				dynamic_cast<const AVLNode<T, U>*>(this->getFather()) != NULL));
	return dynamic_cast<const AVLNode<T, U>*>(this->getFather());
}

template<class T, class U>
AVLNode<T, U>* AVLNode<T, U>::getAVLFather() {
	assert(
			(this->getFather() == NULL ||
					dynamic_cast<AVLNode<T, U>*>(this->getFather()) != NULL));
	return dynamic_cast<AVLNode<T, U>*>(this->getFather());
}

template<class T, class U>
int AVLNode<T, U>::getHeight() const {
	return height;
}

template<class T, class U>
void AVLNode<T, U>::setHeight(int height) {
	this->height = height;
}

template<class T, class U>
int AVLNode<T, U>::getRightHeight() const {
	return this->hasRight() ? this->getAVLRight()->getHeight() : -1;
}

template<class T, class U>
int AVLNode<T, U>::getLeftHeight() const {
	return this->hasLeft() ? this->getAVLLeft()->getHeight() : -1;
}

template<class T, class U>
int AVLNode<T, U>::bfactor() const {
	return getLeftHeight() - getRightHeight();
}

template<class T, class U>
void AVLNode<T, U>::fixHeight() {
	int heightLeft = this->getLeftHeight();
	int heightRight = this->getRightHeight();
	height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

template<class T, class U>
bool AVLNode<T, U>::isBalanced() const {
	return (bfactor() <= 1 && bfactor() >= -1);
}

// ########################################################################
// ------------------------- AVLSEARCHTREE --------------------------------
// ########################################################################

template<class T, class U>
class AVLTree: public BinSearchTree<T, U> {
public:
	/*
	 * AVLTree<T, U> - Constructor - creates an empty avl tree
	 */
	AVLTree<T, U>() :
			BinSearchTree<T, U>() {
	}
	;

	/*
	 *~AVLTree - Destructor - deletes all nodes saved in the tree
	 */
	virtual ~AVLTree();

	/*
	 * insert - add a node with the received key and value to the current tree
	 */
	virtual void insert(const T& key, const U& value);

	/*
	 * remove - removes a node with the received key from the current tree
	 */
	virtual void remove(const T& data);

	/*
	 * makeEmptyTree - makes an empty tree with n nodes
	 */
	void makeEmptyTree(int n);

	/*
	 * getAVLRoot - returns a pointer to the root of the AVL tree
	 */
	AVLNode<T, U>* getAVLRoot();

private:
	/*
	 * performRoll - gets a pointer to an AVL node and performs a roll
	 * 				  the roll will be performed according to the balance factor
	 */
	void performRoll(AVLNode<T, U>* node);

	/*
	 * rollLL - perform an LL roll after adding or removing a node to the tree
	 * 			receives the pointer to the node that was added to the tree or
	 * 			the pointer to the parent of the removed node
	 * 			an LL Roll is performed when a node was added to/Removed from
	 * 			a left sub tree of the left child of the current node
	 */
	void rollLL(AVLNode<T, U>* node);

	/*
	 * rollLR - perform an LR roll after adding or removing a node to the tree
	 * 			receives the pointer to the node that was added to the tree or
	 * 			the pointer to the parent of the removed node
	 *
	 * 			an LR Roll is performed when a node was added to/removed from
	 * 			a right sub tree of the left child of the current node
	 */
	void rollLR(AVLNode<T, U>* node);

	/*
	 * rollRL - perform an RL roll after adding or removing a node to the tree
	 * 			receives the pointer to the node that was added to the tree or
	 * 			the pointer to the parent of the removed node
	 */
	void rollRL(AVLNode<T, U>* node);

	/*
	 * rollRE - perform an RR roll after adding or removing a node to the tree
	 * 			receives the pointer to the node that was added to the tree or
	 * 			the pointer to the parent of the removed node
	 */
	void rollRR(AVLNode<T, U>* node);

	/*
	 * makeCompleteTree - make a complete tree with given height
	 *
	 * @param height - the height of the tree to create
	 */
	void makeCompleteTree(int height);

	/*
	 * removeExcessNodes - auxiliary function of completeTree, removes given
	 * 					   amount of nodes
	 *
	 * 	@param excess - number of nodes to be removed
	 */
	void removeExcessNodes(int* excess);

	/*
	 * removeExcessNodes_aux - removes all excess nodes from the tree whose
	 * 							node is received
	 *
	 * @param excess - pointer to the number of nodes to remove
	 * @param node - the first node of the tree
	 */
	void removeExcessNodes_aux(int* excess, AVLNode<T, U>* node);
};

template<class T, class U>
AVLTree<T, U>::~AVLTree() {
}

template<class T, class U>
void AVLTree<T, U>::insert(const T& key, const U& value) {
	if (this->contains(key)) {
		return;
	}
	//create the new node
	AVLNode<T, U> *toAdd = new AVLNode<T, U>(key, value);
	//add the node to the relevant place - save the current place of the
	//                                     node in the tree
	AVLNode<T, U> *node = dynamic_cast<AVLNode<T, U>*>(this->insertNode(toAdd));
	int height;
	while (node->hasFather()) {
		node = node->getAVLFather();
		height = node->getHeight();
		node->fixHeight();
		//if the height hasn't changed, everything above it won't change either
		if (height == node->getHeight()) {
			break;
		}
		//node is balanced - nothing to change
		if (node->isBalanced()) {
			continue;
		} else { //the node isn't balanced
			performRoll(node);
			break;
		}
	}
}

template<class T, class U>
void AVLTree<T, U>::remove(const T& key) {
	if (this->contains(key) == false) {
		return;
	}
	//find the node to be removed
	AVLNode<T, U>* toRemove = dynamic_cast<AVLNode<T, U>*>(this->find(key));
	//remove the requested node
	AVLNode<T, U>* parent =
			dynamic_cast<AVLNode<T, U>*>(BinSearchTree<T, U>::removeNode(
					toRemove));
	//go all the way up the tree - and verify the nodes are balanced
	while (parent) {
		parent->fixHeight();
		//if the height hasn't changed, everything above it won't change either
		if (parent->isBalanced() == false) {
			performRoll(parent);
		}
		parent = parent->getAVLFather();
	}
}

template<class T, class U>
AVLNode<T, U>* AVLTree<T, U>::getAVLRoot() {
	return dynamic_cast<AVLNode<T, U>*>(this->getRoot());
}

template<class T, class U>
void AVLTree<T, U>::makeCompleteTree(int height) {
	assert(height >= 0);
	this->root = new AVLNode<T, U>(height);
	AVLNode<T, U>* AVLroot = getAVLRoot();
	assert(AVLroot);
	AVLroot->completeTree(height - 1);
}

template<class T, class U>
void AVLTree<T, U>::removeExcessNodes(int* excess) {
	if (*excess <= 0) {
		return;
	}
	removeExcessNodes_aux(excess, this->getAVLRoot());
}

template<class T, class U>
void AVLTree<T, U>::removeExcessNodes_aux(int* excess, AVLNode<T, U>* node) {
	if (node == NULL) {
		return;
	}
	int excessBefore = *excess;
	if (*excess > 0) {
		removeExcessNodes_aux(excess, node->getAVLRight());
	}
	if (*excess > 0) {
		removeExcessNodes_aux(excess, node->getAVLLeft());
	}
	if (excessBefore < *excess + 2) {
		if (*excess > 0) {
			if (node->isLeaf()) {
				if (node->hasFather()) {
					if (node->isLeft()) {
						node->father->left = NULL;
					} else {
						node->father->right = NULL;
					}
				}
				delete node;
				*excess = *excess - 1;
			}
		}
	} else {
		node->setHeight(node->getHeight() - 1);
	}
}

template<class T, class U>
void AVLTree<T, U>::makeEmptyTree(int n) {
	this->clear();
	assert(n >= 0);
	if (n == 0) {
		return;
	}
	//approximation that is the first power of 2 that's bigger than n
	//height of tree
	int approxN = 1, leavesInLevel = 1, height = 0;
	while (approxN < n) {
		leavesInLevel = leavesInLevel * 2;
		approxN += leavesInLevel;
		++height;
	}
	makeCompleteTree(height);
	this->size = n;
	int excess = approxN - n;
	removeExcessNodes(&excess);
}

template<class T, class U>
void AVLTree<T, U>::performRoll(AVLNode<T, U>* node) {
	//execute a roll according to the balance factor of the tree
	if (node->bfactor() == 2
			&& (node->hasLeft() && node->getAVLLeft()->bfactor() >= 0)) {
		rollLL(node);
		return;
	}
	if (node->bfactor() == 2
			&& (node->hasLeft() && node->getAVLLeft()->bfactor() == -1)) {
		rollLR(node);
		return;
	}
	if (node->bfactor() == -2
			&& (node->hasRight() && node->getAVLRight()->bfactor() <= 0)) {
		rollRR(node);
		return;
	}
	if (node->bfactor() == -2
			&& (node->hasRight() && node->getAVLRight()->bfactor() == 1)) {
		rollRL(node);
		return;
	}
}

template<class T, class U>
void AVLTree<T, U>::rollLL(AVLNode<T, U>* node) {
	bool isLeftSon = node->isLeft();
	AVLNode<T, U>* parent = node->getAVLFather();
	AVLNode<T, U>* nodeA = node->getAVLLeft();
	AVLNode<T, U>* nodeAR = nodeA->getAVLRight();
	node->setLeft(nodeAR);
	if (node->hasFather()) {
		if (isLeftSon) {
			parent->setLeft(nodeA);
		} else {
			parent->setRight(nodeA);
		}
	} else {
		nodeA->father = NULL;
		this->setRoot(nodeA);
	}
	nodeA->setRight(node);
	node->fixHeight();
	nodeA->fixHeight();
}

template<class T, class U>
void AVLTree<T, U>::rollLR(AVLNode<T, U>* node) {
	bool isLeftSon = node->isLeft();
	AVLNode<T, U>* nodeA = node->getAVLLeft();
	AVLNode<T, U>* nodeB = nodeA->getAVLRight();
	AVLNode<T, U>* nodeBL = nodeB->getAVLLeft();
	AVLNode<T, U>* nodeBR = nodeB->getAVLRight();
	AVLNode<T, U>* parent = node->getAVLFather();
	node->setLeft(nodeBR);
	nodeA->setRight(nodeBL);
	nodeB->setLeft(nodeA);
	nodeB->setRight(node);
	if (parent) {
		if (isLeftSon) {
			parent->setLeft(nodeB);
		} else {
			parent->setRight(nodeB);
		}
	} else {
		nodeB->father = NULL;
		this->setRoot(nodeB);
	}
	node->fixHeight();
	nodeA->fixHeight();
	nodeB->fixHeight();
}

template<class T, class U>
void AVLTree<T, U>::rollRL(AVLNode<T, U>* node) {
	bool isLeftSon = node->isLeft();
	AVLNode<T, U>* nodeA = node->getAVLRight();
	AVLNode<T, U>* nodeB = nodeA->getAVLLeft();
	AVLNode<T, U>* nodeBR = nodeB->getAVLRight();
	AVLNode<T, U>* nodeBL = nodeB->getAVLLeft();
	AVLNode<T, U>* parent = node->getAVLFather();
	node->setRight(nodeBL);
	nodeA->setLeft(nodeBR);
	nodeB->setLeft(node);
	nodeB->setRight(nodeA);
	if (parent) {
		if (isLeftSon) {
			parent->setLeft(nodeB);
		} else {
			parent->setRight(nodeB);
		}
	} else {
		nodeB->father = NULL;
		this->setRoot(nodeB);
	}
	node->fixHeight();
	nodeA->fixHeight();
	nodeB->fixHeight();
}

template<class T, class U>
void AVLTree<T, U>::rollRR(AVLNode<T, U>* node) {
	AVLNode<T, U>* parent = node->getAVLFather();
	AVLNode<T, U>* nodeA = node->getAVLRight();
	AVLNode<T, U>* nodeAL = nodeA->getAVLLeft();
	node->setRight(nodeAL);
	if (node->hasFather()) {
		if (node->isLeft()) {
			parent->setLeft(nodeA);
		} else {
			parent->setRight(nodeA);
		}
	} else {
		nodeA->father = NULL;
		this->setRoot(nodeA);
	}
	nodeA->setLeft(node);
	node->fixHeight();
	nodeA->fixHeight();
}

#endif /* AVLTREE_H_ */
