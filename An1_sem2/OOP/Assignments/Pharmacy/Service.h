#pragma once
#include "Repository.h"

int checkId(int id);

struct Medicine* getElement(int position);

char getName(Medicine element);

char getManufacturer(Medicine element);

int getID(Medicine element);

int getQuantity( Medicine element);