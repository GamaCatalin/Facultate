#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	this->currentNode = m.root;
	this->currentPosition = 0;
	this->nodes = multime.getSuccessors(multime.root);
	this->currentNode = this->nodes.get_element(this->currentPosition);
}


void SortedSetIterator::first() {
	this->currentNode = this->nodes.get_element(0);
	this->currentPosition = 0;
}

void SortedSetIterator::next() {
	this->currentNode = this->nodes.get_element(++this->currentPosition);
}


TElem SortedSetIterator::getCurrent()
{
	if (this->valid()) {
		/*std::cout << "Current position: " << this->currentPosition << " - ";
		std::cout << "Current elem: " << this->nodes.get_element(this->currentPosition)->data << std::endl;*/
		return this->nodes.get_element(this->currentPosition)->data;
	}
	return NULL;
}

bool SortedSetIterator::valid() const {
	if (this->currentNode == NULL || this->currentPosition>=this->nodes.lenght())
		return false;
	return true;
}

