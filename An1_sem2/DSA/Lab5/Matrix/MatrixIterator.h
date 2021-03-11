#pragma once
#include "Matrix.h"
#include <exception>

class MatrixIterator
{
	friend class Matrix;
private:
	const Matrix& matrix;
	int line;
	int columnsNr;

	int currentPosition;
	int firstPosition;

	TElem* elements;
public:
	MatrixIterator(const Matrix& matrix,int line);

	void first();
	void next();

	TElem getCurrent();
};

