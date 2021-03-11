#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

int main() {
	//testAll();
	std::cout << "Short tests over!" << std::endl;

	testAllExtended();
	std::cout << "Finished LP Tests!" << std::endl;
	system("pause");
}
