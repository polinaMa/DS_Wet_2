/*
 * list.h
 *
 *  Created on: Jun 8, 2015
 *      Author: Ron
 */

#ifndef LIST_H_
#define LIST_H_

#include "exception.h"
#include "iostream"
template<class T> class List;
template<class T> class Iterator;

// ----------------------------- NODE -------------------------------------

template<class T>
class Node {
	template<class U> friend class Iterator;
	template<class U> friend class List;
	T* data;
	Node* next;
	Node* prev;
	Node<T>();
	Node<T>(T& data);
	Node<T>(const T& data);
	Node<T>(const Node<T>& node);
	~Node<T>();
	void setNext(Node<T>& node);
	void setPrev(Node<T>& node);
	bool operator==(const Node<T>& node);
};

template<class T>
Node<T>::Node() :
		data(nullptr), next(nullptr), prev(nullptr) {
}

template<class T>
Node<T>::Node(T& data) :
		data(new T(data)), next(nullptr), prev(nullptr) {
}

template<class T>
Node<T>::Node(const T& data) :
		data(new T(data)), next(nullptr), prev(nullptr) {
}

template<class T>
Node<T>::Node(const Node<T>& node) :
		data(new T(node.data)), next(node.next), prev(node.prev) {
}

template<class T>
Node<T>::~Node() {
	delete (data);
}

template<class T>
void Node<T>::setNext(Node<T>& node) {
	this->next = &node;
	node.prev = this;
}

template<class T>
void Node<T>::setPrev(Node<T>& node) {
	this->prev = &node;
	node.next = this;
}

template<class T>
bool Node<T>::operator==(const Node<T>& node) {
	return this == &node;
}

// ----------------------------- ITERATOR ---------------------------------

template<class T>
class Iterator {
	template<class U> friend class List;
	const List<T>* list;
	Node<T>* node;
public:
	Iterator() = delete;
	Iterator(const List<T>* list, Node<T>* node);
	Iterator(const Iterator<T>& iterator) = default;
	~Iterator() = default;
	T& operator*();
	Iterator<T>& operator++();
	Iterator<T> operator++(int);
	Iterator<T>& operator--();
	Iterator<T> operator--(int);
	Iterator<T>& operator=(const Iterator<T>& iterator);
	bool operator==(const Iterator<T>& iterator);
	bool operator==(const Node<T>& node);
	bool operator!=(const Iterator<T>& iterator);
	bool operator!=(const Node<T>& node);
};

template<class T>
Iterator<T>::Iterator(const List<T>* list, Node<T>* node) :
		list(list), node(node) {
}

template<class T>
T& Iterator<T>::operator*() {
	if (node->data == nullptr) {
		throw ListExceptions::ElementNotFound();
	}
	return *(node->data);
}

template<class T>
Iterator<T>& Iterator<T>::operator++() {
	this->node = this->node->next;
	return *this;
}

template<class T>
Iterator<T> Iterator<T>::operator++(int) {
	Iterator copy(*this);
	++(*this);
	return copy;
}

template<class T>
Iterator<T>& Iterator<T>::operator--() {
	this->node = this->node->prev;
	return *this;
}

template<class T>
Iterator<T> Iterator<T>::operator--(int) {
	Iterator copy(*this);
	--(*this);
	return copy;
}

template<class T>
bool Iterator<T>::operator==(const Iterator<T>& iterator) {
	return (list == iterator.list) && (node == iterator.node);
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T>& iterator) {
	return !(*this == iterator);
}

template<class T>
bool Iterator<T>::operator==(const Node<T>& node) {
	return this->node == node;
}

template<class T>
bool Iterator<T>::operator!=(const Node<T>& node) {
	return this->node != node;
}

template<class T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& iterator) {
	if (this == &iterator) {
		return *this;
	}
	list = iterator.list;
	node = iterator.node;
	return *this;
}

// ------------------------------- LIST -----------------------------------

template<class T>
class List {
public:
	List<T>();
	explicit List<T>(List& list);
	~List();
	Iterator<T> begin();
	Iterator<T> end();

	void insert(T& data, Iterator<T> iterator);
	void insert(const T& data, Iterator<T> iterator);
	void remove(Iterator<T> iterator);

	template<class Predicate>
	Iterator<T> find(const Predicate& predicate);

	template<class Predicate>
	bool contains(const Predicate& predicate);

	template<class Comapre>
	void sort(const Comapre& comparer);

	template<class Comapre>
	Iterator<T> findMin(List<T>& list, const Comapre& comparer);
	int getSize();

	void clear();

	List<T>& operator=(List<T>& list);
private:
	int size = 0;
	Node<T>* head;
	Node<T>* tail;
};

template<class T>
List<T>::List() :
		head(new Node<T>()), tail(new Node<T>()) {
	head->setNext(*tail);
}

template<class T>
List<T>::List(List<T>& list) :
		head(new Node<T>()), tail(new Node<T>()) {
	head->setNext(*tail);
	Iterator<T> i = list.begin();
	while (i != list.end()) {
		insert(*(i++), end());
	}
}

template<class T>
List<T>::~List() {
	Iterator<T> iterator = begin();
	while (iterator != end()) {
		remove(iterator);
		iterator = begin();
	}
	delete (head);
	delete (tail);
}

template<class T>
void List<T>::insert(T& data, Iterator<T> iterator) {
	if (iterator.list != this) {
		throw ListExceptions::ElementNotFound();
	}
	Node<T>* toAdd = new Node<T>(data);
	iterator.node->prev->setNext(*toAdd);
	toAdd->setNext(*iterator.node);
	size++;
}

template<class T>
void List<T>::insert(const T& data, Iterator<T> iterator) {
	if (iterator.list != this) {
		throw ListExceptions::ElementNotFound();
	}
	Node<T>* toAdd = new Node<T>(data);
	iterator.node->prev->setNext(*toAdd);
	toAdd->setNext(*iterator.node);
	size++;
}

template<class T>
void List<T>::remove(Iterator<T> iterator) {
	if (iterator.list != this || size == 0 || iterator.node == tail) {
		throw ListExceptions::ElementNotFound();
	}
	iterator.node->prev->setNext(*iterator.node->next);
	delete (iterator.node);
	--size;
}

template<class T>
void List<T>::clear() {
	for (Iterator<T> item = begin(); item != end(); ++item) {
		remove(item);
	}
}

template<class T>
Iterator<T> List<T>::begin() {
	return Iterator<T>(this, head->next);
}

template<class T>
Iterator<T> List<T>::end() {
	return Iterator<T>(this, tail);
}

template<class T>
int List<T>::getSize() {
	return size;
}

template<class T>
template<class Predicate>
Iterator<T> List<T>::find(const Predicate& predicate) {
	Iterator<T> i = this->begin();
	while (i != this->end()) {
		if (predicate(*i)) {
			return i;
		}
		i++;
	}
	return i;
}

template<class T>
template<class Predicate>
bool List<T>::contains(const Predicate& predicate) {
	Iterator<T> item = find(predicate);
	return (item != end());
}

template<class T>
template<class Comapre>
void List<T>::sort(const Comapre& comparer) {
	List<T> copy(*this);
	List<T> sorted;
	while (copy.getSize()) {
		Iterator<T> min = findMin(copy, comparer);
		sorted.insert(*min.node->data, sorted.end());
		copy.remove(min);
	}
	*this = sorted;
}

template<class T>
template<class Comapre>
Iterator<T> List<T>::findMin(List<T>& list, const Comapre& comparer) {
	Iterator<T> iterator = list.begin();
	Iterator<T> min = list.begin();
	while (iterator != list.end()) {
		if (comparer(*iterator.node->data, *min.node->data)) {
			min = iterator;
		}
		iterator++;
	}
	return min;
}

template<class T>
List<T>& List<T>::operator=(List<T>& list) {
	if (this == &list) {
		return *this;
	}
	Iterator<T> iterator = begin();
	while (iterator != end()) {
		remove(iterator);
		iterator = begin();
	}
	iterator = list.begin();
	while (iterator != list.end()) {
		insert(*iterator.node->data, end());
		++iterator;
	}
	return *this;
}

#endif /* LIST_H_ */
