#include "Repository.h"

bool Repository::isValid(TElem element)
{
	BirthDate date;
	date = element.getBirthDate();
	if (date.getDay() < 1 || date.getDay() > 31)
		return false;
	if (date.getMonth() < 1 || date.getMonth() > 12)
		return false;
	if (date.getYear() < 1 || date.getYear() > 9999)
		return false;
	if (element.getVaccinationsCount() < 1)
		return false;

	return true;
}

bool Repository::add_element(TElem element)
{
	if (this->isValid(element)){
		this->dogs.push_back(element);
		return true;
	}
	return false;
}

bool Repository::update_element(TElem element)
{
	if (!this->isValid(element)) {
		return false;
	}
	int counterIndex=0;
	for (auto current = this->dogs.begin(); current < this->dogs.end(); current++) {
		if (current->getName() == element.getName()) {
			*current = element;	
			return true;
		}
		counterIndex++;
	}
	return false;
}

bool Repository::remove_element(std::string elementName)
{
	for (auto current = this->dogs.begin(); current < this->dogs.end(); current++)
		if (current->getName() == elementName)
		{
			this->dogs.erase(current);
			return true;
		}
	return false;
}

std::vector<TElem> Repository::get_elements()
{
	return this->dogs;
}

int Repository::lenght()
{
	return dogs.size();
}
