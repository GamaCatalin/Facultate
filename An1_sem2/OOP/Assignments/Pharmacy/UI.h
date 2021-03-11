#pragma once
#include "Service.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

#ifndef UI_H
#define UI_H

/*

Prints a menu containing all the command

*/

void menu();



/*

Prints all the elements in the repository

*/

void list_all();



/*

Prints the elements matching a given name

*/

void list_name(char name[]);


/*

Prints the elements with a quantity less than the given quantity

*/

void list_quantity(int maxQuantity);


#endif