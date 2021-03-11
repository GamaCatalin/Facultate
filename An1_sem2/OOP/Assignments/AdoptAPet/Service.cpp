#include "Service.h"

void Service::addElement(TElem element)
{
	this->petShop.add_element(element);
}

void Service::updateElement(TElem element)
{
	DynamicVector<TElem> tempArray = this->getAll();

	for (int i = 0; i < this->lenght(); i++) 
		if (tempArray.get_element(i).getName() == element.getName()) {
			this->petShop.update_element(i, element);
		}
}

void Service::removeElement(std::string name)
{
	DynamicVector<TElem> tempArray;
	tempArray = this->getAll();

	for (int i = 0; i < this->lenght(); i++)
		if (tempArray.get_element(i).getName() == name) {
			this->petShop.remove_element(i);
		}

}

int Service::lenght()
{
	return this->petShop.lenght();
}

DynamicVector<TElem> Service::getAll()
{
	return petShop.get_elements();
}

DynamicVector<TElem> Service::getAdoptionList()
{
	return userAdoptionList;
}

std::string Service::getRunMode()
{
	return this->runMode;
}

void Service::setRunMode(std::string runMode)
{
	this->runMode = runMode;
}

void Service::saveDog(std::string name)
{
	DynamicVector<TElem> tempDogs = this->getAll();
	for (int i = 0; i <= this->lenght() - 1; i++) {
		if (tempDogs.get_element(i).getName() == name) {
			this->userAdoptionList.add(tempDogs.get_element(i));
		}
	}
}

TElem Service::nextDog()
{
	TElem tempElement;
	DynamicVector<TElem> tempArray=this->petShop.get_elements();

	if (this->userCurrentDogIndex == this->petShop.lenght()-1) {
		tempElement = tempArray.get_element(this->userCurrentDogIndex);
		this->userCurrentDogIndex = 0;
	}
	else {
		tempElement = tempArray.get_element(this->userCurrentDogIndex);
		this->userCurrentDogIndex++;
	}
	return tempElement;
}
