#pragma once
#include <string>
#include <iostream>
#include "Service.h"

class UI
{
private:
	Service service;
	

public:
	std::string runMode = "";
	bool runApplication=true;

	void printMenu();
	std::string getCommand();
	void listAll();
	void listUserAdoptionList();
	void listBreed(std::string breed,int vaccinations);
	void listVaccinations(int vaccinations);
	void processCommand(std::string command);
	std::string getDogPrintable(TElem element);
	TElem getDogElement(std::string name, std::string breed, std::string birthDate, int vaccinationsCount, std::string photograph);
	void userNextDog();

};