#include "Service.h"

int checkId(int id)
{	int tempID;
	for (int i = 0; i <= repository.size; i++) {
		tempID = repository.medications[i].id;
		if (tempID == id) return 1;
	}
	return 0;
}

struct Medicine* getElement(int position)
{
	return repository.medications[position];
}

char getName(Medicine element)
{
	return element.name;
}

char getManufacturer(struct Medicine element)
{
	return element.manufacturer;
}

int getID(struct Medicine element)
{
	return element.id;
}

int getQuantity(struct Medicine element)
{
	return element.quantity;
}
