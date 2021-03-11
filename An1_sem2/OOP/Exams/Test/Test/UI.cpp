#include "UI.h"


std::string UI::getCommand()
{
	std::string command;
	getline(std::cin, command);
	return command;
}

void UI::processCommand(std::string command)
{
	bool invalidCommandSwitch = true;



	std::string commandArray[100], tempCommand = "";
	char delimiterSpace = ' ', delimiterComma = ',';

	int counter = 0, commandIndex = 0;

	for (int i = 0; i < command.length(); i++) {
		if (command[i] == delimiterSpace) {
			commandArray[commandIndex] = tempCommand;
			commandIndex++;
			tempCommand = "";
			break;
		}
		tempCommand += command[i];
		counter++;
	}



	int startIndex = counter + 1, endIndex = startIndex;

	for (int i = counter + 1; i < command.length(); i++) {
		if (command[i] != delimiterComma) {
			tempCommand += command[i];
		}
		if (command[i] == delimiterComma || i == command.length() - 1) {
			commandArray[commandIndex] = tempCommand;
			commandIndex++;
			tempCommand = "";
			if (command[i + 1] == ' ')
				i++;
		}

	}

	int mainCommandIndex = 0, nameIndex = 1, typeIndex = 2, doctorsIndex = 3, patientIndex = 4, mothersIndex = 4, babiesIndex = 5, gradeIndex = 6,fileIndex=1;
	std::string addCommand = "add", listCommand = "list", fileLocationCommand = "fileLocation", exitCommand = "exit";


	if (command == exitCommand) {
		this->runApplication = false;
		return;
	}

	if (command == listCommand) {
		this->listAll();
	}

	if (commandArray[mainCommandIndex] == addCommand) {
		if (commandArray[typeIndex] == "Surgery")
			this->controller.addDepartament(commandArray[nameIndex], commandArray[typeIndex], stoi(commandArray[doctorsIndex]), stoi(commandArray[patientIndex]), 0, 0);
		else
			this->controller.addDepartament(commandArray[nameIndex], commandArray[typeIndex], stoi(commandArray[doctorsIndex]), stoi(commandArray[patientIndex]), stoi(commandArray[babiesIndex]), stod(commandArray[gradeIndex]));
	}

	if (commandArray[mainCommandIndex] == listCommand) {
		this->listAllEfficient();
	}

	if (commandArray[mainCommandIndex] == fileLocationCommand) {
		this->controller.changeFileName(commandArray[fileIndex]);
	}


}

void UI::listAll()
{
	std::vector<std::string> tempVector = this->controller.getAllDepartments();
	for (int i = 0; i < tempVector.size(); i++) {
		std::cout << tempVector.at(i) << std::endl;
	}
}

void UI::listAllEfficient()
{
	std::vector<std::string> tempVector = this->controller.getAllEfficientDepartments();
	for (int i = 0; i < tempVector.size(); i++) {
		std::cout << tempVector.at(i) << std::endl;
	}

}
