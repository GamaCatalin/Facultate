#pragma once
#include "Controller.h"
#include <iostream>
class UI
{
private:
	Controller controller;
public:
	bool runApplication = true;

	std::string getCommand();
	void processCommand(std::string command);
	void listAll();
	void listAllEfficient();
};

