#include "UI.h"


void UI::printMenu()
{
	for (int i = 0; i < 80; i++) {
		std::cout << "*";
	}
	std::cout << std::endl;
	for (int i = 0; i < 30; i++) {
		std::cout << " ";
	}
	std::cout << "Menu\n";
	std::cout << "mode X\n";
	std::cout << "add name, breed, birthDate, vaccinationsCount, photograph\n";
	std::cout << "update name, newBreed, newBirthDate, newVaccinationsCount, newPhotograph\n";
	std::cout << "delete title\n";
	std::cout << "list\n";
	std::cout << "list breed, vaccinationsCount\n";
	std::cout << "next\n";
	std::cout << "save name\n";
	std::cout << "myList\n";
	std::cout << std::endl;
	std::cout << "exit\n";
	for (int i = 0; i < 80; i++) {
		std::cout << "*";
	}
	std::cout << std::endl;

}

std::string UI::getCommand()
{
	std::string command;
	getline(std::cin, command);
	return command;
}

void UI::listAll()
{
	std::vector<TElem> printArray;
	printArray = service.getAll();
	for (int i = 0; i < printArray.size(); i++) {
		std::cout << printArray.at(i) << std::endl;
	}
}

void UI::listUserAdoptionList()
{
	std::vector<TElem> printArray = service.getAdoptionList();
	for (int i = 0; i < printArray.size(); i++) {
		std::cout << printArray.at(i) << std::endl;
	}
}

void UI::listBreed(std::string breed, int vaccinations)
{
	std::vector<TElem> printArray, tempArray = service.getAll();
	TElem tempElement;
	for (int i = 0; i < tempArray.size(); i++) {
		tempElement = tempArray.at(i);
		if (tempElement.getBreed() == breed && tempElement.getVaccinationsCount() < vaccinations)
			printArray.push_back(tempElement);
	}

	for (int i = 0; i < printArray.size(); i++) {
		std::cout << printArray.at(i) << std::endl;
	}
}

void UI::listVaccinations(int vaccinations)
{
	std::vector<TElem> printArray, tempArray = service.getAll();
	TElem tempElement;
	for (int i = 0; i < tempArray.size(); i++) {
		tempElement = tempArray.at(i);
		if (tempElement.getVaccinationsCount() < vaccinations)
			printArray.push_back(tempElement);
	}

	for (int i = 0; i < printArray.size(); i++) {
		std::cout << printArray.at(i) << std::endl;
	}
}


void UI::processCommand(std::string command)
{
	bool invalidCommandSwitch=true;



	std::string commandArray[100], tempCommand = "";
	char delimiterSpace = ' ',delimiterComma=',';
	
	int counter = 0,commandIndex=0;

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



	int startIndex=counter+1, endIndex=startIndex;

	for (int i = counter + 1; i < command.length(); i++) {
		if (command[i] != delimiterComma) {
			tempCommand += command[i];
		}
		if (command[i] == delimiterComma || i== command.length() -1) {
			commandArray[commandIndex] = tempCommand;
			commandIndex++;
			tempCommand = "";
			if(command[i+1]==' ')
				i++;
		}
		
	}
	std::cout << std::endl;
	int commandArrayLenght = commandIndex,constBreedVaccinations=2;
	commandIndex = 0;

	int modeIndex = 1, nameIndex = 1, breedIndex = 2, dateIndex = 3, vaccinationsIndex = 4, photographIndex = 5, saveNameIndex = 1, listVaccinationsBreedIndex = 1, listVaccinationsIndex = 2, fileLocationIndex = 1, myListLocationIndex=1;
	std::string commandExit = "exit", commandList = "list", commandMode = "mode", commandAdd = "add", commandDelete = "delete", commandUpdate = "update", constantModeA = "A", constantModeB = "B", commandSave = "save", commandNext = "next", commandMyList = "mylist", commandFileLocation = "fileLocation", commandMyListLocation = "mylistLocation";



	if (command == commandExit) {
		this->runApplication = false;
		return;
	}
	if (command == commandList) {
		invalidCommandSwitch = false;
		
		if (service.getRunMode() == constantModeA) {
			try {
				this->listAll();
			}
			catch (ExceptionNoElements error) {
				std::cout << error.what() << std::endl;
			}
		}
		else std::cout << "Can't execute operation!\n";
		return;
	}

	if (commandArray[commandIndex] == commandMode) {
		invalidCommandSwitch = false;
		if (commandArray[modeIndex] != constantModeA && commandArray[modeIndex] != constantModeB) {
			std::cout << "Invalid running mode!\n";
		}
		if (service.getRunMode() == commandArray[modeIndex]) std::cout << "Aplication already running in the given mode!\n";
		else service.setRunMode(commandArray[modeIndex]);
	}

	if (commandArray[commandIndex] == commandFileLocation) {
		invalidCommandSwitch = false;
		try {
			service.changeFileLocation(commandArray[fileLocationIndex]);
		}
		catch (ExceptionNoFile error) {
			std::cout << error.what();
		}
	}

	if (commandArray[commandIndex] == commandMyListLocation) {
		invalidCommandSwitch = false;
		service.changeMyListLocation(commandArray[myListLocationIndex]);
	}

	if (commandArray[commandIndex] == commandAdd) {
		invalidCommandSwitch = false;
		if (service.getRunMode() == constantModeA) {
			TElem tempElement;
			tempElement = this->getDogElement(commandArray[nameIndex], commandArray[breedIndex], commandArray[dateIndex], stoi(commandArray[vaccinationsIndex]), commandArray[photographIndex]);
			try {
				service.addElement(tempElement);
			}
			catch (ExceptionAddAlreadyExisting error) {
				std::cout << error.what();
			}
			catch (ExceptionNoElements error) {
				std::cout << error.what();
			}
			catch (ExceptionNoFile error) {
				std::cout << error.what();
			}
			catch (ExceptionValidationError error) {
				std::cout << error.what();
			}
		}
		else std::cout << "Can't execute operation!\n";
	}

	if (commandArray[commandIndex] == commandUpdate) {
		invalidCommandSwitch = false;
		if (service.getRunMode() == constantModeA) {
			TElem tempElement;
			tempElement = this->getDogElement(commandArray[nameIndex], commandArray[breedIndex], commandArray[dateIndex], stoi(commandArray[vaccinationsIndex]), commandArray[photographIndex]);
			try {
				service.updateElement(tempElement);
			}
			catch (ExceptionUpdateDoesNotExist error) {
				std::cout << error.what();
			}
			catch (ExceptionNoElements error) {
				std::cout << error.what();
			}
			catch (ExceptionNoFile error) {
				std::cout << error.what();
			}
			catch (ExceptionValidationError error) {
				std::cout << error.what();
			}
		}
		else std::cout << "Can't execute operation!\n";
	}

	if (commandArray[commandIndex] == commandDelete) {
		invalidCommandSwitch = false;
		if (service.getRunMode() == constantModeA) {
			try {
			service.removeElement(commandArray[nameIndex]);
			}
			catch (ExceptionDeleteDoesNotExist error) {
				std::cout << error.what();
			}
			catch (ExceptionNoElements error) {
				std::cout << error.what();
			}
			catch (ExceptionNoFile error) {
				std::cout << error.what();
			}
		}
		else std::cout << "Can't execute operation!\n";
	}

	if (commandArray[commandIndex] == commandSave) {
		invalidCommandSwitch = false;
		if (service.getRunMode() == constantModeB) 
			service.saveDog(commandArray[saveNameIndex]);
		else std::cout << "Can't execute operation!\n";
	}

	if (command == commandNext) {
		invalidCommandSwitch = false;
		if (service.getRunMode() == constantModeB)this->userNextDog();
		else std::cout << "Can't execute operation!\n";
	}
	
	if (command == commandMyList) {
		invalidCommandSwitch = false;
		if (service.getRunMode() == constantModeB) {
			service.getAdoptionList();
		}
			
		else std::cout << "Can't execute operation!\n";
	}

	if (commandArray[commandIndex] == commandList) {
		invalidCommandSwitch = false;
		if (commandArrayLenght == constBreedVaccinations) {
			try {
				this->listVaccinations(stoi(commandArray[listVaccinationsBreedIndex]));
			}
			catch (ExceptionNoElements error) {
				std::cout << error.what();
			}
			catch (ExceptionNoFile error) {
				std::cout << error.what();
			}
		}
		else {
			this->listBreed(commandArray[listVaccinationsBreedIndex], stoi(commandArray[listVaccinationsIndex]));
		}
	}

	

	if (invalidCommandSwitch) {
		std::cout << "Invalid command!\n";
	}

}

std::string UI::getDogPrintable(TElem element)
{
	std::string tempString;
	BirthDate tempDate;
	tempDate = element.getBirthDate();
	tempString = element.getName() + ", " + element.getBreed() + ", " + std::to_string(tempDate.getDay()) + "-" + std::to_string(tempDate.getMonth()) + "-" + std::to_string(tempDate.getYear()) + ", " + std::to_string(element.getVaccinationsCount()) + ", " + element.getPhotograph();
	return tempString;
}

TElem UI::getDogElement(std::string name, std::string breed, std::string birthDate, int vaccinationsCount, std::string photograph)
{
	TElem tempElement;
	BirthDate tempDate;


	std::string dateArray[3], tempString;
	char delimiter = '-';
	int counter = 0;

	for (int i = 0; i < birthDate.length(); i++) {
		if (birthDate[i] != delimiter) {
			tempString += birthDate[i];
		}
		else {
			dateArray[counter] = tempString;
			counter++;
			tempString = "";
		}
		if (i == birthDate.length() - 1) {
			dateArray[counter] = tempString;
			counter++;
			tempString = "";
		}
	}


	tempDate.setDay(stoi(dateArray[0]));
	tempDate.setMonth(stoi(dateArray[1]));
	tempDate.setYear(stoi(dateArray[2]));

	tempElement.setName(name);
	tempElement.setBreed(breed);
	tempElement.setBirthDate(tempDate);
	tempElement.setVaccinationsCount(vaccinationsCount);
	tempElement.setPhotograph(photograph);

	return tempElement;
}

void UI::userNextDog()
{
	TElem nextDog=service.nextDog();
	std::cout << this->getDogPrintable(nextDog) << std::endl;
}
