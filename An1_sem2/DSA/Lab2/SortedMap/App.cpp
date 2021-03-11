#include "ExtendedTest.h"
#include "ShortTest.h"

#include "SortedMap.h"


#include <iostream>
using namespace std;


int main() {
	testAll();
	cout << "Short test over" << endl;

	testMostFrequent();

	cout << "Aditional requierement over" << endl;

	testAllExtended();

	cout << "That's all!" << endl;
	system("pause");
	return 0;
}


