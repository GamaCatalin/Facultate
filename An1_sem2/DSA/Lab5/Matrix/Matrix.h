#include <iostream>
#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0


struct matrixCell {
	int line;
	int column;
	int value;
};

class Node {
public:
	Node* next;
	Node* prev;
	matrixCell data;
	Node();
	void add(int i, int j, TElem e);
};


class Matrix {

private:
	int lines;
	int columns;
	int capacity;
	
	Node* table;


	//TODO - Representation
public:
	//constructor
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	int hash(int i, int j) const;


	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

};
