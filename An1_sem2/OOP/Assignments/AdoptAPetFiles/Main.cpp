#include "UI.h"
#include "Test.h"
using namespace std;


int main() {

	bool RunTests = false;

	if(RunTests){
		Test test;
		test.testAll();
	}
	else {

		UI ui;
		ui.printMenu();
		while (ui.runApplication) {
			ui.processCommand(ui.getCommand());
		}

	}

	return 0;
}