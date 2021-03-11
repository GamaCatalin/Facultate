#include "Service.h"

bool Service::addElement(TElem element)
{
	if (this->petShop.add_element(element))
		return true;
}

bool Service::updateElement(TElem element)
{
	if (this->petShop.update_element(element))
		return true;
}

bool Service::removeElement(std::string name)
{
	if (this->petShop.remove_element(name))
		return true;
}

int Service::lenght()
{
	return this->petShop.lenght();
}

std::vector<TElem> Service::getAll()
{
	std::vector<TElem> vector;
	vector = this->petShop.get_elements();
	return vector;
}

std::vector<TElem> Service::getAdoptionList()
{
	return this->myListController->getElements();
}

TElem Service::getElementByID(std::string name)
{
	return this->petShop.getElementByName(name);
}

std::string Service::getRunMode()
{
	return this->runMode;
}

bool Service::setRunMode(std::string runMode)
{
	this->runMode = runMode;
	return true;
}

bool Service::saveDog(std::string name)
{
	//std::cout << name << std::endl;
	std::vector<TElem> elements = this->getAll();
	for (auto& current : elements) {
		if (current.getName() == name)
		return (this->myListController->saveElement(current));
	}
	return false;
}

TElem Service::nextDog()
{
	TElem tempElement;
	std::vector<TElem> tempArray=this->petShop.get_elements();

	if (this->userCurrentDogIndex == this->petShop.lenght()-1) {
		tempElement = tempArray.at(this->userCurrentDogIndex);
		this->userCurrentDogIndex = 0;
	}
	else {
		tempElement = tempArray.at(this->userCurrentDogIndex);
		this->userCurrentDogIndex++;
	}
	return tempElement;
}

bool Service::changeFileLocation(std::string fileLocation)
{
	this->petShop.setFileLocation(fileLocation);
	return true;
}

bool Service::changeMyListLocation(std::string mylistLocation)
{
	std::string fileMode = this->getMyListMode(mylistLocation);

	if (fileMode == "html") {
		this->myListController = new HTMLMyListController();
	}
	if (fileMode == "csv") {
		this->myListController = new CSVMyListController();
	}
	if (fileMode == "txt") {
		this->myListController = new TXTMyListController();
	}
	if (fileMode == "") {
		this->myListController = new MemoryMyListController();
	}

	this->myListController->setFileName(mylistLocation);
	return true;
}

std::string Service::getMyListMode(std::string mylistLocation)
{
	std::string mode="";
	if (mylistLocation == "") {
		mode = "";
	}
	else if (mylistLocation.at(mylistLocation.size() - 4) == '.') {
		if (mylistLocation.at(mylistLocation.size() - 3) == 'c')
			mode = "csv";
		if (mylistLocation.at(mylistLocation.size() - 3) == 't')
			mode = "txt";
	}
	else {
		if (mylistLocation.at(mylistLocation.size() - 5) == '.')
			if (mylistLocation.at(mylistLocation.size() - 4) == 'h')
				mode = "html";
	}

	return mode;
}
