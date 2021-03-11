#include "Repository.h"
#include "Module.h"
#include <string.h>
#include <stdlib.h>

void add_medicine(int id, char name[], char manufacturer[], int quantity) {

	int index = repository.index++;

	repository.medications[index].id = id;
	repository.medications[index].quantity = quantity;
	strcpy(&repository.medications[index].name, name);
	strcpy(&repository.medications[index].manufacturer, manufacturer);

	update_memory();

}

void delete_medicine(int id) {

	int i, j;

	for (i = 0; i <= repository.index; i++) {
		if (repository.medications[i].id == id) {
			for (j = i; j < repository.index; j++) {
				repository.medications[j].id = repository.medications[j + 1].id;
				strcpy(repository.medications[j].name, repository.medications[j + 1].name);
				strcpy(repository.medications[j].manufacturer, repository.medications[j + 1].manufacturer);
				repository.medications[j].quantity = repository.medications[j + 1].quantity;
			}
			repository.index--;
			break;
		}
	}

	update_memory();

}

void update_medicine(int id,char newName[],char newManufacturer[], int newQuantity) {

	int i;

	for (i = 0; i <= repository.index; i++) {

		if (repository.medications[i].id == id) {

			repository.medications[i].quantity = newQuantity;
			strcpy(&repository.medications[i].name, newName);
			strcpy(&repository.medications[i].manufacturer, newManufacturer);
			break;
		}
	}

	update_memory();
}


void populate() {

	add_medicine(1, "name1", "manufacturer1", 1);
	add_medicine(2, "name2", "manufacturer2", 2);
	add_medicine(3, "name3", "manufacturer3", 3);
	add_medicine(4, "name4", "manufacturer4", 4);
	add_medicine(5, "name5", "manufacturer5", 5);

}

void update_memory(){

	memory.index++;

	if (memory.index > memory.maxIndex) {

		memory.maxIndex = memory.index;

	}

	memory.repositoryMemory[memory.index] = repository;

}

void undo() {

	memory.index--;
	repository = memory.repositoryMemory[memory.index];

}

void redo() {

	memory.index++;
	repository = memory.repositoryMemory[memory.index];

}




char get_currentName(struct Medicine element) {

	return element.name;

}


char get_currentManufacturer(struct Medicine element) {

	return element.manufacturer;

}

int get_currentID(struct Medicine element) {

	return element.id;

}

int get_currentQuantity(struct Medicine element) {

	return element.quantity;

}
