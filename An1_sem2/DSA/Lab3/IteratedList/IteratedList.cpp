
#include <exception>
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList() {
	//TODO - Implementation
	
	for (int i = 0; i <= this->capacity; i++) {
		this->elements[i].data = NULL_TELEM;
		this->elements[i].next = i+1;
	}

	this->elements[this->capacity].next = -1;

	this->head = 0;

	this->tail = 0;

	this->firstEmpty = 0;

	this->lenght = 0;
}

int IteratedList::size() const {
	//TODO - Implementation	
	return this->lenght;
}

bool IteratedList::isEmpty() const {
	//TODO -  Implementation
	if (this->lenght == 0) {
		return true;
	}
	return false;
}

ListIterator IteratedList::first() const {
	ListIterator iterator(*this);
	iterator.first();
	return iterator;
}

TElem IteratedList::getElement(ListIterator pos) const {
	
	if (pos.getCurrentPosition() < 0 || pos.getCurrentPosition() > this->capacity) {
		throw _exception();
	}

	ListIterator iterator(*this);
	iterator.first();

	while (iterator.getCurrentPosition() != -1) {
		if (iterator.getCurrentPosition() == pos.getCurrentPosition()) {
			return this->elements[iterator.getCurrentPosition()].data;
		}
		iterator.next();
	}

	return NULL_TELEM;
}

TElem IteratedList::remove(ListIterator& pos) {
	ListIterator iterator(*this);
	iterator.first();

	if (pos.getCurrentPosition() == 1) {
		this->head = this->elements[1].next;
		if (this->firstEmpty > pos.getCurrentPosition()) {
			this->elements[pos.getCurrentPosition()].data = NULL_TELEM;
			this->elements[pos.getCurrentPosition()].next = pos.getCurrentPosition() + 1;
			this->firstEmpty = pos.getCurrentPosition();
		}
		return this->elements[1].data;
	}

	Node* prevElement;

	prevElement = &this->elements[iterator.getCurrentPosition()];

	while (iterator.getCurrentPosition() != -1) {
		iterator.next();
		if (iterator.getCurrentPosition() == pos.getCurrentPosition()) {
			prevElement->next = this->elements[iterator.getCurrentPosition()].next;
			if (this->firstEmpty > iterator.getCurrentPosition()) {
				this->firstEmpty = iterator.getCurrentPosition();
			}
			this->lenght--;
			TElem value = this->elements[iterator.getCurrentPosition()].data;
			this->elements[iterator.getCurrentPosition()].data = NULL_TELEM;
			return value;
		}
		prevElement = &this->elements[iterator.getCurrentPosition()];
	}

	return NULL_TELEM;
}

ListIterator IteratedList::search(TElem e) const{
	//TODO - Implementation
	ListIterator iterator(*this);
	iterator.first();
	while (iterator.getCurrentPosition() !=-1) {
		if (this->elements[iterator.getCurrentPosition()].data == e) {
			return iterator;
		}
		iterator.next();
	}
	return ListIterator(*this);	
}

void IteratedList::setFirstEmpty()
{
	int nullElem = NULL_TELEM;

	for (int i = 0; i <= this->capacity; i++) {
		if (this->elements[i].data == nullElem) {
			this->firstEmpty = i;
			return;
		}
	}
	this->firstEmpty = -1;
}

void IteratedList::print()
{
	ListIterator iterator(*this);
	std::cout << "New" << std::endl;
	this->setFirstEmpty();
	std::cout << "First empty: " << this->firstEmpty << std::endl;
	while (iterator.valid()) {
		std::cout << "Position: " << iterator.getCurrentPosition() << " - Value: " << iterator.getCurrent() << std::endl;
		iterator.next();
	}
}


TElem IteratedList::setElement(ListIterator pos, TElem e) {
    //TODO - Implementation
	if (pos.getCurrentPosition() < 0 || pos.getCurrentPosition() > this->capacity) {
		throw _exception();
	}

	ListIterator iterator(*this);
	iterator.first();

	while (iterator.getCurrentPosition() != -1) {
		if (iterator.getCurrentPosition() ==pos.getCurrentPosition()) {
			TElem value = this->elements[iterator.getCurrentPosition()].data;
			this->elements[iterator.getCurrentPosition()].data = e;
			return value;
		}
		iterator.next();
	}

	return NULL_TELEM;
}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
    //TODO - Implementation
	if (pos.getCurrentPosition() < 0 || pos.getCurrentPosition() > this->capacity) {
		throw _exception();
	}
	int nullElem = NULL_TELEM;
	ListIterator iterator(*this);
	iterator.first();
	this->setFirstEmpty();
	
	while (iterator.valid()) {
		if (iterator.getCurrentPosition() == pos.getCurrentPosition()) {
			while (true) {
				if (this->elements[iterator.getCurrentPosition()].next == this->firstEmpty) {
					this->elements[iterator.getCurrentPosition()].next = this->elements[this->firstEmpty].next;
					break;
				}
				iterator.next();
			}
			this->elements[this->firstEmpty].next = this->elements[pos.getCurrentPosition()].next;
			this->elements[pos.getCurrentPosition()].next = this->firstEmpty;
			this->elements[this->firstEmpty].data = e;
			pos.setPosition(this->firstEmpty);
			this->lenght++;
		}
		iterator.next();
	}



}

void IteratedList::addToEnd(TElem e) {
	//TODO - Implementation
	int nullElem=NULL_TELEM;
	ListIterator iterator(*this);
	iterator.first();
	this->setFirstEmpty();
	while (iterator.valid()) {
		iterator.next();
	}
	this->elements[iterator.getCurrentPosition()].data = e;
	this->lenght++;
}

void IteratedList::addToBeginning(TElem e)
{
	ListIterator iterator(*this);
	this->setFirstEmpty();
	while (iterator.valid()) {
		if (this->elements[iterator.getCurrentPosition()].next == this->firstEmpty) {
			this->elements[iterator.getCurrentPosition()].next = this->elements[this->firstEmpty].next;
			break;
		}
		iterator.next();
	}

	if (this->lenght == 0) {
		this->elements[0].data = e;
		this->head = 0;
		this->lenght++;
		return;
	}

	this->elements[this->firstEmpty].data = e;
	this->elements[this->firstEmpty].next = this->head;
	this->head = this->firstEmpty;
	this->lenght++;
}

IteratedList::~IteratedList() {
	//TODO - Implementation
}