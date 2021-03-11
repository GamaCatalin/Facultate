#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){

	this->currentNode = m.head;
	this->firstNode = m.head;
}

void SMIterator::first(){
	this->currentNode = this->firstNode;
}

void SMIterator::next(){

	if(this->currentNode!=NULL)
		this->currentNode = this->currentNode->next;
	else {
		exception except;
		throw except;
	}
}

bool SMIterator::valid() const{
	if (this->currentNode!=NULL)
		return true;
	return false;
}

TElem SMIterator::getCurrent() const{
	if(this->currentNode!=NULL)
		return this->currentNode->data;
	else {
		exception except;
		throw except;
		return NULL_TPAIR;
	}
}


