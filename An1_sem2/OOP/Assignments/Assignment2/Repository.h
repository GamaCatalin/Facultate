#pragma once

#ifndef REPOSITORY_H
#define REPOSITORY_H

typedef struct Repository {

	struct Medicine medications[100];
	struct Medicine tempElement;
	int index;

};

typedef struct Memory {

	struct Repository repositoryMemory[100];
	int index;
	int maxIndex; 

};


struct Memory memory;
struct Repository repository;


/*

Adds an element to the repository

*/

void add_medicine(id, name, manufacturer, quantity);


/*

Deletes the element with the matching ID

*/

void delete_medicine(id);


/*

Updates the element with the matching ID with the new values

*/

void update_medicine(id, newName, newManufacturer, newQuantity);


/*

Populates the repository 

*/

void populate();


/*

Updates the memory with the current repository

*/

void update_memory();


/*

Undoes the last operation

*/

void undo();


/*

Redoes the last operation

*/

void redo();


/*

Returns the name at the current index

*/

char get_currentName(struct Medicine element);


/*

Returns the manufacturer at the current index

*/

char get_currentManufacturer(struct Medicine element);


/*

Returns the ID at the current index

*/

int get_currentID(struct Medicine element);


/*

Returns the quantity at the current index

*/

int get_currentQuantity(struct Medicine element);




#endif