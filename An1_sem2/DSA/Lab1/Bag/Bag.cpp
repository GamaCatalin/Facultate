#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag(int capacity) {

	this->capacity = capacity;
	this->sizeElements = 0;
	this->sizePositions = 0;
	this->elements = new TElem[this->capacity];
	this->positions = new TElem[this->capacity];
}


void Bag::add(TElem elem) {

	if (this->search(elem) == false) {
		this->elements[this->sizeElements++] = elem;
		this->positions[this->sizePositions++] = (this->sizeElements) - 1;
	}
	else {
		if (this->elementPosition(elem) != -1) {
			this->positions[this->sizePositions++] = this->elementPosition(elem);
		}
	}
}


bool Bag::remove(TElem elem) {
	
	int elementPosition = this->elementPosition(elem),foundElementsNr=0;
	bool foundElementSwitch=false;

	std::cout << "Test remove element: " << elem;

	foundElementsNr = this->nrOccurrences(elem);

	std::cout << " - " << foundElementsNr << "-" << elementPosition << endl;

	if(elementPosition!=-1 && this->sizePositions!=0)
		for (int i = 0; i < this->sizePositions; i++) {
			if (this->positions[i] == elementPosition) {
				if (foundElementSwitch==false) {
					for (int j = i; j < this->sizePositions - 1; j++) {
						this->positions[j] = this->positions[j + 1];
					}
					this->sizePositions--;
					foundElementSwitch = true;
					break;
				}
			}
		}

	if (foundElementsNr == 1) {
		for (int i = 0; i < this->sizeElements; i++) {
			if (this->elements[i] == elem) {
				for (int j = i; j < this->sizeElements - 1; j++) {
					this->elements[j] = this->elements[j + 1];
				}
				this->sizeElements--;
				break;
			}
		}
	}

	if (foundElementSwitch) return true;
	return false;
}


bool Bag::search(TElem elem) const {
	
	for (int i = 0; i < this->sizeElements; i++) {
		if (this->elements[i] == elem) return true;
	}

	return false;
}

int Bag::nrOccurrences(TElem elem) const {
	int counterOccurrences = 0;
	for (int i = 0; i < this->sizeElements; i++) {
		if (this->elements[i] == elem) {
			for (int j = 0; j < this->sizePositions; j++) {
				if (this->positions[j] == i) counterOccurrences++;
			}
			break;
		}
	}
	return counterOccurrences;
}


int Bag::size() const {
	
	return this->sizePositions;
}

int Bag::elementPosition(TElem e) const
{
	for (int i = 0; i < this->sizeElements; i++) {
		if (this->elements[i] == e) return i;
	}
	return -1;
}


bool Bag::isEmpty() const {
	if (this->sizePositions == 0) 
		return true;
	return false;
}

TElem Bag::leastFrequent() const
{
	int minFrequency=99999999;
	TElem minElement;
	bool foundSwitch = false;

	for (int i = 0; i < this->sizeElements; i++) {
		if (this->nrOccurrences(this->elements[i]) < minFrequency) {
			minElement = this->elements[i];
			minFrequency = this->nrOccurrences(this->elements[i]);
			foundSwitch = true;
		}
	}

	if (foundSwitch)
		return minElement;
	else
		return NULL_TELEM
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	delete[] this->elements;
	delete[] this->positions;
}

