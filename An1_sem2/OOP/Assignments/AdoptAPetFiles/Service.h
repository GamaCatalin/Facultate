#pragma once
#include "RepositoryFiles.h"
#include "MyListController.h"
#include "CSVMyListController.h"
#include "HTMLMyListController.h"
#include "MemoryMyListController.h";
#include "TXTMyListController.h";
#include "Validator.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#ifndef SERVICE_H
#define SERVICE_H



class Service {
private:
	MyListController* myListController;

	RepositoryFiles petShop;
	
	std::string runMode = "";
	int userCurrentDogIndex=0;
public:
	
	bool addElement(TElem element);
	bool updateElement(TElem element);
	bool removeElement(std::string name);

	int lenght();

	std::vector<TElem> getAll();
	std::vector<TElem> getAdoptionList();
	TElem getElementByID(std::string name);

	std::string getRunMode();
	bool setRunMode(std::string runMode);

	bool saveDog(std::string name);

	TElem nextDog();

	bool changeFileLocation(std::string fileLocation);
	bool changeMyListLocation(std::string mylistLocation);

	std::string getMyListMode(std::string mylistLocation);
};




#endif