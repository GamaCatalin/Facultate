#pragma once
#include "Repository.h"

#ifndef SERVICES_H
#define SERVICES_H

/*

Checks if a given ID is already assigned to an element in the repository

*/

int check_id(int id);




struct Medicine* get_currentElement(int index);


/*

Returns the name at the current index

*/

//char get_currentName(struct Medicine element);


/*

Returns the manufacturer at the current index

*/

//char get_currentManufacturer(struct Medicine element);


/*

Returns the ID at the current index

*/

//int get_currentID(struct Medicine element);


/*

Returns the quantity at the current index

*/

//int get_currentQuantity(struct Medicine element);




/*

Calls the repository adder

*/

void call_adder(int id, char name[], char manufacturer[], int quantity);


/*

Calls the repository deleter

*/

void call_deleter(int id);


/*

Calls the repository updater

*/

void call_updater(int id, char newName[], char newManufacturer[], int quantity);


/*

Calls the repository populator

*/

void call_populate();


/*

Calls the undo operation

*/


int undo_caller();


/*

Calls the redo operation

*/

int redo_caller();


/*

Checks if the input string is a number

*/

int checkNumber(char testString[]);



#endif