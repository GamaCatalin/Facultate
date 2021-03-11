#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <iostream>
using namespace std;

SortedMap::SortedMap(Relation r) {

	this->lenght = 0;

	this->head = NULL;
	this->tail=NULL;

	this->relation = r;
}

TValue SortedMap::add(TKey k, TValue v) {
	
	Node* tempNode;

	tempNode = this->head;

	while (tempNode != NULL) {
		if (tempNode->data.first == k) {
			TValue value = tempNode->data.second;
			tempNode->data.second = v;
			return value;
		}
		if (this->relation(k, tempNode->data.first)) {
			Node* newNode = new Node();

			newNode->data.first = k;
			newNode->data.second = v;

			newNode->prev = tempNode->prev;
			tempNode->prev = newNode;
			newNode->next = tempNode;
			if (newNode->prev != NULL) {
				newNode->prev->next = newNode;
			}
			else {
				this->head = newNode;
			}
			this->lenght++;
			return NULL_TVALUE;
		}
		tempNode = tempNode->next;
	}

	this->tail = tempNode;

	Node* newNode=new Node();

	newNode->data.first = k;
	newNode->data.second = v;

	tempNode = this->head;
	/*
	while (tempNode != NULL) {
		if (this->relation(k, tempNode->data.first)) {
			newNode->prev = tempNode->prev;
			tempNode->prev = newNode;
			newNode->next = tempNode;
			if (newNode->prev != NULL) {
				newNode->prev->next = newNode;
			}
			else {
				this->head = newNode;
			}
			this->lenght++;
			return NULL_TVALUE;
		}
		tempNode = tempNode->next;
	}
	*/
	newNode->next = NULL;
	if(this->head == NULL) {
		newNode->prev = NULL;
		this->head = newNode;
		this->lenght++;
		return NULL_TVALUE;
	}

	tempNode = this->head;
	while (tempNode->next != NULL)
		tempNode = tempNode->next;

	tempNode->next = newNode;
	newNode->prev = tempNode;
	this->lenght++;
	return NULL_TVALUE;

}

TValue SortedMap::search(TKey k){
	
	Node* tempNode;

	tempNode = this->head;

	while (tempNode != NULL) {
		if (tempNode->data.first == k) {
			return tempNode->data.second;
		}
		tempNode = tempNode->next;
	}
	return NULL_TVALUE;
}

TValue SortedMap::remove(TKey k) {
	
	Node* tempNode;

	tempNode = this->head;

	while (tempNode != NULL) {
		if (tempNode->data.first == k) {
			TValue value = tempNode->data.second;
			if (this->head == tempNode)
				this->head = tempNode->next;
			if (tempNode->next != NULL) {
				tempNode->next->prev = tempNode->prev;
			}
			if (tempNode->prev != NULL) {
				tempNode->prev->next = tempNode->next;
			}
			free(tempNode);
			this->lenght--;
			return value;
		}
		tempNode = tempNode->next;
	}

	return NULL_TVALUE;
}

int SortedMap::size() const {
	
	/*
	int size=0;

	Node* tempNode;

	tempNode = this->head;
	while (tempNode != NULL) {
		size++;
		tempNode = tempNode->next;
	}
	return size;
	*/
	return this->lenght;
}

bool SortedMap::isEmpty() const {
	if (this->lenght == 0)
		return true;
	return false;
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

std::vector<TKey> SortedMap::keySet()
{
	Node* tempNode;
	vector<TKey> keysVector;

	tempNode = this->head;
	while (tempNode != NULL) {
		keysVector.push_back(tempNode->data.first);
	}
	return keysVector;
}

TValue SortedMap::mostFrequent() const
{
	Frequency frequencyMap;
	Node* tempNode;

	tempNode = this->head;
	while (tempNode != NULL) {
		//std::cout << tempNode->data.second << std::endl;
		if (!frequencyMap.increment(tempNode->data.second)) {
			//std:cout << tempNode->data.second<<std::endl;
			frequencyMap.add(tempNode->data.second);
		}
		tempNode = tempNode->next;
	}
	if (frequencyMap.lenght == 0) {
		return NULL_TVALUE;
	}
	else {
		TValue mostFrequent=NULL_TVALUE;
		int frequency=0;
		Node* freqNode;
		freqNode = frequencyMap.head;
		while (freqNode != NULL) {
			if (freqNode->data.second > frequency) {
				//std::cout << freqNode->data.second << std::endl;
				mostFrequent = freqNode->data.first;
				frequency = freqNode->data.second;
			}
			freqNode = freqNode->next;
		}
		
		return mostFrequent;
	}

}

void SortedMap::printSortedMap()
{
	Node* tempNode;
	tempNode = this->head;
	while (tempNode != NULL) {
		cout << "Key: " << tempNode->data.first << " - Value: " << tempNode->data.second << endl;
		tempNode = tempNode->next;
	}
}


SortedMap::~SortedMap() {
	
	Node* tempNode,*destroyedNode;
	tempNode = this->head;
	while (tempNode != NULL) {
		destroyedNode = tempNode;
		tempNode = tempNode->next;
		delete[] destroyedNode;
	}

}

Node::Node()
{
	this->data = NULL_TPAIR;
	this->next = NULL;
	this->prev = NULL;
}

Node::Node(TElem data)
{
	this->data = data;
}

Frequency::Frequency()
{
	this->lenght = 0;

	this->head = NULL;
	this->tail = NULL;
}

bool Frequency::increment(TValue value)
{
	Node* tempNode;

	tempNode = this->head;

	while (tempNode != NULL) {
		if (tempNode->data.first == value) {
			tempNode->data.second++;
			return true;
		}
		tempNode = tempNode->next;
	}
	return false;
}

void Frequency::add(TValue value)
{
	Node* newNode=new Node();
	newNode->data.first = value;
	newNode->data.second = 1;

	if (this->tail != NULL) {
		this->tail->next = newNode;
		newNode->prev = this->tail;
		newNode->next = NULL;
		this->tail = newNode;
		this->lenght++;
	}
	else {
		if (this->head == NULL) {
			newNode->next = NULL;
			newNode->prev = NULL;
			this->head = newNode;
			this->lenght++;
		}
		else if (this->head != NULL) {
			this->head->next = newNode;
			newNode->prev = this->head;
			newNode->next = NULL;
			this->tail = newNode;
			this->lenght++;
		}
	}

}

Frequency::~Frequency()
{
	Node* tempNode, * destroyedNode;
	tempNode = this->head;
	while (tempNode != NULL) {
		destroyedNode = tempNode;
		tempNode = tempNode->next;
		delete[] destroyedNode;
	}
}
