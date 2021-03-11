#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c) : bag(c)
{
	this->currentElement = 0;
	this->currentPosition = 0;
}

void BagIterator::first() {

	this->currentPosition = 0;
	this->currentElement = bag.elements[this->currentPosition];
}


void BagIterator::next() {

	if (!this->valid())
		return;
	this->currentPosition++;
	this->currentElement = bag.elements[this->currentPosition];
}


bool BagIterator::valid() const {
	if (this->currentPosition < this->bag.size() && this->bag.size()!=0) return true;
	return false;
}



TElem BagIterator::getCurrent() const
{
	return this->currentElement;
}
