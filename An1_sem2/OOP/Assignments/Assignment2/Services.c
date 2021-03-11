#include "Services.h"
#include "Repository.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int check_id(int id) {

	int i;

	for (i = 0; i <= repository.index; i++) {
		
		if (repository.medications[i].id == id) {
			return 1;
		}

	}

	return 0;
}

struct Medicine* get_currentElement(int index) {

	return repository.medications[index];

}

int get_maxIndex() {

	return repository.index;

}


void call_adder(int id, char name[], char manufacturer[], int quantity){

	add_medicine(id, name, manufacturer, quantity);

}

void call_deleter(int id){

	delete_medicine(id);

}

void call_updater(int id, char newName[], char newManufacturer[], int quantity){

	update_medicine(id, newName, newManufacturer, quantity);

}

void call_populate() {

	populate();

}

int undo_caller(){

	if (memory.index > 0) {

		undo();
		return 1;

	}
	else {

		return 0;

	}
}

int redo_caller(){

	if (memory.index <= memory.maxIndex) {

		redo();
		return 1;

	}
	else {

		return 0;

	}

}

int checkNumber(char testString[]) {

	for (int i = 0; i < strlen(testString); i++) {

		if (testString[i] < '0' || testString[i]>'9') {

			return 0;

		}

	}

	return 1;



}
