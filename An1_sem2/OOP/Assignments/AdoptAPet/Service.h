#pragma once
#include "Repository.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#ifndef SERVICE_H
#define SERVICE_H



class Service {
private:
	Repository petShop;
	std::string runMode = "";
	DynamicVector<TElem> userAdoptionList;
	int userCurrentDogIndex=0;
public:
	
	void addElement(TElem element);
	void updateElement(TElem element);
	void removeElement(std::string name);

	int lenght();

	DynamicVector<TElem> getAll();
	DynamicVector<TElem> getAdoptionList();

	std::string getRunMode();
	void setRunMode(std::string runMode);


	void saveDog(std::string name);
	TElem nextDog();


};




#endif