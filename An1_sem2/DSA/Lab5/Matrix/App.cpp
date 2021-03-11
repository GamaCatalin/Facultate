
#include <iostream>
#include "Matrix.h"
#include "MatrixIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"

using namespace std;


int main() {


	testAll();
	testAllExtended();
	testAditional();



	cout << "Test End" << endl;
	system("pause");
}