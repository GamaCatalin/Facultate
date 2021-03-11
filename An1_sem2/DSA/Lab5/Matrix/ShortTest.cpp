#include <assert.h>
#include "Matrix.h"
#include "ShortTest.h"

using namespace std;

void testAll() { 
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrColumns() == 4);	
	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	TElem old = m.modify(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEM);
	assert(old == 5);
}

void testAditional()
{

	Matrix matrix(10, 10);

	matrix.modify(3, 4, 2);
	matrix.modify(3, 5, 7);
	matrix.modify(3, 9, 9);
	matrix.modify(3, 1, 5);
	matrix.modify(3, 3, 7);
	matrix.modify(3, 2, 1);

	try {
		MatrixIterator iterator(matrix, 3);
		for (int i = 0; i <= 10; i++) {
			assert(matrix.element(3,i)==iterator.getCurrent());
			iterator.next();
		}
	}
	catch(exception){

	}
	
}
