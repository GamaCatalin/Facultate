#include "MatrixIterator.h"
#include <exception>

MatrixIterator::MatrixIterator(const Matrix& matrix,int line) : matrix(matrix)
{
	/*
	BC: cNr
	WC: cNr
	*/
	if (line > matrix.nrLines() || line < 0) {
		throw;
	}
	this->line = line;
	this->columnsNr = this->matrix.nrColumns();

	elements = new TElem(this->columnsNr);

	for (int i = 0;i <= this->columnsNr; i++) {
		elements[i] = this->matrix.element(this->line, i);
	}

	this->firstPosition = 0;
	this->currentPosition = 0;
}

void MatrixIterator::first()
{
	/*
	BC: 1
	WC: 1
	*/
	this->currentPosition = this->firstPosition;
}

void MatrixIterator::next()
{
	/*
	BC: 1
	WC: 1
	*/

	if (this->currentPosition == this->columnsNr) {
		this->currentPosition = this->firstPosition;
	}
	else {
		this->currentPosition++;
	}
}

TElem MatrixIterator::getCurrent()
{
	/*
	BC: 1
	WC: 1
	*/
	return this->elements[this->currentPosition];
}
