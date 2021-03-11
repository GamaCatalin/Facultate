#include "UI.h"

using namespace std;

int main() {

	UI ui;

	while (ui.runApplication) {
		ui.processCommand(ui.getCommand());
	}

	return 0;
}