#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

ListIterator::ListIterator(const IteratedList& list) : list(list) {
	this->currentElement = this->list.head;
}

void ListIterator::first() {
	this->currentElement = this->list.head;
}

void ListIterator::next() {
	
	/*if (!this->valid()) {
		throw _exception();
	}
	else {*/
		this->currentElement = this->list.elements[this->currentElement].next;
	//}
	
}

bool ListIterator::valid() const {
	int nullElem = NULL_TELEM;
	if (this->getCurrent()!=nullElem)
		return true;
	return  false;
}

void ListIterator::setPosition(int position)
{
	this->currentElement = position;
}

TElem ListIterator::getCurrent() const {
	return this->list.elements[this->currentElement].data;
}

int ListIterator::getCurrentPosition()
{
	return this->currentElement;
}



