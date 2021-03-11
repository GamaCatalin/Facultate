#include "Repository.h"

void Repository::add_element(TElem element)
{
	dogs.add(element);
}

void Repository::update_element(int position, TElem element)
{
	dogs.update(position, element);
}

void Repository::remove_element(int position)
{
	dogs.remove(position);
}

DynamicVector<TElem> Repository::get_elements()
{
	return this->dogs;
}

int Repository::lenght()
{
	return dogs.lenght();
}
