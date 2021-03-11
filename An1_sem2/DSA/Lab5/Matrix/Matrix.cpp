#include "Matrix.h"
#include <exception>
using namespace std;



Matrix::Matrix(int nrLines, int nrCols) {
	  
	this->columns = nrCols;
	this->lines = nrLines;
	this->capacity = 10;
	this->table = new Node[this->capacity];
}


int Matrix::nrLines() const {
	
	return this->lines;
}


int Matrix::nrColumns() const {

	return this->columns;
}

int Matrix::hash(int i, int j) const
{
	/*
	BC: 1
	WC: 
	*/
	int sum = i + j;
	while (sum > 9) {
		int tempSum = sum;
		sum = 0;
		while (tempSum > 0) {
			sum = sum + tempSum % 10;
			tempSum = tempSum / 10;
		}
	}

	return sum;
}


TElem Matrix::element(int i, int j) const {
	/*
	BC: 1
	WC: n
	*/


	if (i > this->lines || j > this->columns) {
		throw exception("Invalid position");
	}
	if (i < 0 || j < 0) {
		throw exception("Invalid position");
	}


	int index = this->hash(i, j);


	Node *tempNode = &this->table[index];
	while (tempNode != NULL) {
		if (tempNode->data.line == i && tempNode->data.column == j) {
			return tempNode->data.value;
		}
		tempNode = tempNode->next;
	}


	return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
	/*
	BC: 1
	WC: 2n
	*/
	
	if (i > this->lines || j > this->columns) {
		throw exception("Invalid position");
	}
	if (i < 0 || j < 0) {
		throw exception("Invalid position");
	}

	int index = this->hash(i, j);
	

	Node* tempNode = &this->table[index];

	while (tempNode != NULL) {
		if (tempNode->data.line == i && tempNode->data.column == j) {
			
			TElem value = tempNode->data.value;
			tempNode->data.value = e;
			return value;
		}
		tempNode = tempNode->next;
	}


	Node* newNode=new Node();

	newNode->prev = NULL;
	newNode->next = NULL;

	newNode->add(i, j, e);

	
	
	tempNode = &this->table[index];

	if (tempNode != NULL && tempNode->next==NULL && tempNode->data.value == 0) {
		this->table[index] = *newNode;
		tempNode = newNode;
		
		return NULL_TELEM;
	}

	while (tempNode->next != NULL)
		tempNode = tempNode->next;

	tempNode->next = newNode;
	newNode->prev = tempNode;


	tempNode = tempNode->next;
	return NULL_TELEM;
}

Node::Node()
{
	this->next = NULL;
	this->prev = NULL;
	this->data.column = -1;
	this->data.line = -1;
	this->data.value = NULL_TELEM;
}

void Node::add(int i, int j, TElem e)
{
	this->data.line = i;
	this->data.column = j;
	this->data.value = e;
}
