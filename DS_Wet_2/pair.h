/*
 * pair.h
 *
 *  Created on: Nov 18, 2015
 *      Author: Ron
 */

#ifndef PAIR_H_
#define PAIR_H_

#include <stdlib.h>

template<class T, class U>
class Pair {
private:
	T* firstPtr;
	U* secondPtr;
	T& first() {
		return *firstPtr;
	}

	const T& first() const {
		return *firstPtr;
	}

	const U& second() const {
		return *secondPtr;
	}
public:
	/*
	 * Pair - Constructor - creates a new pair with NULL pointers
	 */
	Pair() :
			firstPtr(NULL), secondPtr(NULL) {
	}
	;

	/*
	 * Pair - Copy Constructor - copies the received pair to the current pair
	 */
	Pair(const Pair& pair) {
		firstPtr = new T(*pair.firstPtr);
		secondPtr = new U(*pair.secondPtr);
	}

	/*
	 * Pair - Constructor - creates a new pair with the received data
	 */
	explicit Pair(const T& t, const U& u) :
			firstPtr(new T(t)), secondPtr(new U(u)) {
	}
	;

	/*
	 * Pair - Copy Constructor - copies the received pair to the current pair
	 */
	Pair(Pair& pair) {
		firstPtr = new T(*pair.firstPtr);
		secondPtr = new U(*pair.secondPtr);
	}

	/*
	 * Pair - Destructor
	 */
	~Pair() {
		delete firstPtr;
		delete secondPtr;
	}

	/*
	 * setFirst - sets the first part of data of the current pair to the
	 * 			  received data
	 */
	void setFirst(const T& first) {
		if (firstPtr != NULL) {
			delete firstPtr;
		}
		firstPtr = new T(first);
	}

	/*
	 * setSecond - sets the second part of data of the current pair to the
	 * 		      received data
	 */
	void setSecond(const U& second) {
		if (secondPtr != NULL) {
			delete secondPtr;
		}
		secondPtr = new U(second);
	}

	/*
	 * operator< - compares between two pairs according to the first part
	 * 			   of the data
	 * 			   returns true if the current node is smaller than the received
	 * 			   pair
	 */
	bool operator<(const Pair<T, U>& p) const {
		if (first() < p.first()) {
			return true;
		}
		if (first() == p.first()) {
			return second() > p.second();
		}
		return false;
	}

	/*
	 * operator== - compares between two pairs , two pairs will be equal if
	 * 				the pointers to the pairs are the same one
	 */
	bool operator==(const Pair<T, U>& p) const {
		return !(*this < p) && !(p < *this);
	}

	bool operator!=(const Pair<T, U>& p) const {
		return *this < p || p < *this;
	}

	/*
	 * operator= - assignment operator - copies the received pair to the
	 * 									 current pair
	 *
	 *  @param p - the pair to be copied
	 */
	Pair<T, U>& operator=(const Pair<T, U>& p) {
		if (this == &p) {
			return *this;
		}
		this->firstPtr = new T(*p.firstPtr);
		this->secondPtr = new U(*p.secondPtr);
		return *this;
	}
};

#endif /* PAIR_H_ */
