#include "Test.h"

void Test::testAll()
{	
	

	//Service test section

	std::cout << "Service test begin\n";

	this->addElement_validInput_elementAddedSuccessfully();
	this->addElement_invalidInput_aditionFailed();


	this->updateElement_validInput_breedUpdatedSuccessfully();
	this->updateElement_validInput_dateUpdatedSuccessfully();
	this->updateElement_validInput_vaccinationsUpdatedSuccessfully();
	this->updateElement_validInput_photoUpdatedSuccessfully();
	this->updateElement_invalidInput_updateFailed();

	this->deleteElement_validInput_deletedSuccessfully();
	this->deleteElement_invalidInput_deletionFailed();

	this->lenght_noInput_returnSuccessfully();

	this->getAll_noInput_returnSuccessfully();

	this->getRunMode_noInput_returnSuccessfully();
	this->setRunMode_validInput_returnSuccesfully();
	this->nextDog_noInput_getNextDog();
	this->nextDog_startOverInput_successfullyStartOver();
	this->saveDog_validInput_savedSuccessfully();
	this->saveDog_invalidInput_notSaved();
	this->getAdoptionList_noInput_returnedSuccessfully();

	this->changeMyListLocation_validInput_changedSuccessfully();
	this->getMyListMode_noInput_htmlReturnedSuccessfully();
	this->getMyListMode_noInput_csvReturnedSuccessfully();
	this->getMyListMode_noInput_memoryReturnedSuccessfully();
	this->getMyListMode_noInput_txtReturnedSuccessfully();

	std::cout << "Service test over\n";

	//RepositoryFiles test section

	std::cout << "Repository test begin\n";

	this->add_element__validInput__addedSuccessfully();
	this->add_element__invalidInput__aditionFailed();
	this->add_element__noFile__aditionFailed();
	this->add_element__invalidElement__aditionFailed();

	this->update_element__validInput__breedUpdatedSuccessfully();
	this->update_element__validInput__dateUpdatedSuccessfully();
	this->update_element__validInput__vaccinationsUpdatedSuccessfully();
	this->update_element__validInput__photoUpdatedSuccessfully();
	this->update_element__invalidInput__updateFailed();
	this->update_element__noFile__updateFailed();
	this->update_element__invalidElement__updateFailed();

	this->remove_element__validInput__removedSuccessfully();
	this->remove_element__invalidInput__removeFailed();
	this->remove_element__noFile__removeFailed();

	this->get_elements__noInput__returnedSuccessfully();
	this->get_elements__noPath__exceptionThrown();
	this->get_elements__noElements__exceptionThrown();

	this->lenght__noInput__returnedSuccessfully();
	this->lenght__noPath__exceptionThrown();

	this->setFileLocation__validInput__setSuccessfully();

	this->getElementByIndex__validInput__returnedSuccessfully();
	this->getElementByIndex__noPath__exceptionThrown();
	this->getElementByIndex__noElements_exceptionThrown();
	this->getElementByIndex__indexTooBig__exceptionThrown();

	this->getElementByName__validINput__returnedSuccessfully();
	this->getElementByName__noPath__exceptionThrown();
	this->getElementByName__noElements_exceptionThrown();
	this->getElementByName__invalidInput__exceptionThrown();

	std::cout << "Repository test over\n";

	//Validator test section

	std::cout << "Validator test begin\n";

	this->validateGoodElement_goodElement_validationSuccessfull();
	this->validateGoodElement_badDay_validationFailed();
	this->validateGoodElement_badMonth_validationFailed();
	this->validateGoodElement_badYear_validationFailed();
	this->validateGoodElement_badVacciantions_validationFailed();

	std::cout << "Validator test over\n";


	//Date test section

	std::cout << "Date test begin\n";

	this->BirthDate_validInput_creadedSuccessfully();
	this->setDay_validInput_daySetSuccessfully();
	this->setMonth_validInput_monthSetSuccessfully();
	this->setYear_validInput_yearSetSuccessfully();
	this->getDay_noInput_returnedSuccessfully();
	this->getMonth_noInput_returnedSuccessfully();
	this->getYear_noInput_returnedSuccessfully();
	this->getString_noInput_stringGeneratedSuccessfully();
	this->operatorEqualsBirthDate_validInput_true();
	this->operatorEqualsBirthDate_invalidInput_false();
	this->operatorNotEqualsBirthDate_invalidInput_true();
	this->operatorNotEqualsBirthDate_validInput_false();

	std::cout << "Date test over\n";


	//Pet test section

	std::cout << "Pet test begin\n";

	this->Pet_validInput_createdSuccessfully();

	this->setName_validInput_nameSetSuccessfully();
	this->setBreed_validInput_breedSetSuccessfully();
	this->setBirthDate_validInput_dateSetSuccessfully();
	this->setVaccinationsCount_validInput_vaccinationsCountSetSuccessfully();
	this->setPhotograph_validInput_photographSetSuccessfully();
	
	this->getName_noInput_nameReturnedSuccessfully();
	this->getBreed_noInput_breedReturnedSuccessfully();
	this->getBirthDate_noInput_birthDatereturnedSuccessfully();
	this->getVaccinationsCount_noInput_vaccinationsCountReturnedSuccessfully();
	this->getPhotograph_noInput_photographReturnedSuccessfully();
	this->getPrintable_noInput_stringReturnedSuccessfully();


	this->operatorEqualsPet_validInput_true();
	this->operatorEqualsPet_invalidInput_false();
	this->operatorNotEqualsPet_invalidInput_true();
	this->operatorNotEqualsPet_validInput_false();

	std::cout << "Pet test over\n";


}

void Test::addElement_validInput_elementAddedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	std::vector<TElem> array;
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	assert(service.addElement(element));

}

void Test::addElement_invalidInput_aditionFailed()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	std::vector<TElem> array;
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.addElement(element);
	try {
		service.addElement(element);
	}
	catch (ExceptionAddAlreadyExisting error) {
		assert(error.exists);
	}
	
}

void Test::updateElement_validInput_breedUpdatedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.addElement(element);
	service.updateElement(elementUpdate);
	assert(service.getElementByID(name).getBreed()==breedUpdate);
}

void Test::updateElement_validInput_dateUpdatedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.addElement(element);
	service.updateElement(elementUpdate);
	assert(service.getElementByID(name).getBirthDate() == dateUpdate);
}

void Test::updateElement_validInput_vaccinationsUpdatedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.addElement(element);
	service.updateElement(elementUpdate);
	assert(service.getElementByID(name).getVaccinationsCount() == vaccinationUpdate);
}

void Test::updateElement_validInput_photoUpdatedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.addElement(element);
	service.updateElement(elementUpdate);
	assert(service.getElementByID(name).getPhotograph() == photoUpdate);
}

void Test::updateElement_invalidInput_updateFailed()
{
	std::string name = "name", breed = "breed", photo = "photo",nameUpdate="nameUpdate";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ nameUpdate,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.addElement(element);
	try {
		service.updateElement(elementUpdate);
	}
	catch (ExceptionUpdateDoesNotExist error) {
		assert(error.exists);
	}	
}

void Test::deleteElement_validInput_deletedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.addElement(element);
	service.removeElement(name);
	try {
		service.lenght();
	}
	catch (ExceptionNoElements error) {
		assert(error.exists);
	}
}

void Test::deleteElement_invalidInput_deletionFailed()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.addElement(element);
	service.removeElement(name);
	try {
		service.removeElement(name);
	}
	catch (ExceptionDeleteDoesNotExist error) {
		assert(error.exists);
	}
}

void Test::lenght_noInput_returnSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	std::vector<TElem> array;
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.addElement(element);
	array = service.getAll();
	assert(service.lenght()==1);
}

void Test::getAll_noInput_returnSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	std::vector<TElem> array;
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.addElement(element);
	array = service.getAll();
	assert(array.size()==1);
}

void Test::getRunMode_noInput_returnSuccessfully()
{
	Service service;
	assert(service.getRunMode() == "");
}

void Test::setRunMode_validInput_returnSuccesfully()
{
	Service service;
	service.setRunMode("A");
	assert(service.getRunMode() == "A");
}

void Test::nextDog_noInput_getNextDog()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2, };
	std::string name1 = "name1", name2 = "name2", breed1 = "breed1", breed2 = "breed2", photo1 = "photo1", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.addElement(element1);
	service.addElement(element2);
	assert(element1 == service.nextDog());
}

void Test::nextDog_startOverInput_successfullyStartOver()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2, };
	std::string name1 = "name1", name2 = "name2", breed1 = "breed1", breed2 = "breed2", photo1 = "photo1", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 },tempElement;
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.addElement(element1);
	service.addElement(element2);
	tempElement = service.nextDog();
	tempElement = service.nextDog();
	assert(element1 == service.nextDog());
}

void Test::saveDog_validInput_savedSuccessfully()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2, };
	std::string name1 = "name1", name2 = "name2", breed1 = "breed1", breed2 = "breed2", photo1 = "photo1", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.html");
	service.changeMyListLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.html");
	service.addElement(element1);
	service.addElement(element2);
	service.saveDog(name1);
	std::vector<TElem> array;
	array = service.getAdoptionList();
	std::cout << array.size();
	assert(array.size() == 1);
}

void Test::saveDog_invalidInput_notSaved()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2, };
	std::string name1 = "name1", name2 = "name2", breed1 = "breed1", breed2 = "breed2", photo1 = "photo1", photo2 = "photo2", name3 = "name3";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.html");
	service.changeMyListLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.html");
	service.addElement(element1);
	service.addElement(element2);
	assert(!service.saveDog(name3));
}

void Test::getAdoptionList_noInput_returnedSuccessfully()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2, };
	std::string name1 = "name1", name2 = "name2", breed1 = "breed1", breed2 = "breed2", photo1 = "photo1", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	TElem element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	service.changeFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.html");
	service.changeMyListLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.html");
	service.addElement(element1);
	service.addElement(element2);
	service.saveDog(name1);
	service.saveDog(name2);
	std::vector<TElem> array;
	array = service.getAdoptionList();
	assert(array.at(0) == element1 && array.at(1)==element2);
}

void Test::changeMyListLocation_validInput_changedSuccessfully()
{
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.html");
	assert(service.changeMyListLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.html"));
}

void Test::getMyListMode_noInput_htmlReturnedSuccessfully()
{
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.html");
	std::string listLocation = "D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.html";
	assert(service.changeMyListLocation(listLocation) && service.getMyListMode(listLocation) == "html");
}

void Test::getMyListMode_noInput_csvReturnedSuccessfully()
{
	Service service;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.csv");
	std::string listLocation = "D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.csv";
	assert(service.changeMyListLocation(listLocation)&& service.getMyListMode(listLocation)=="csv");
}

void Test::getMyListMode_noInput_memoryReturnedSuccessfully()
{
	Service service;
	std::string listLocation = "";
	assert(service.changeMyListLocation(listLocation) && service.getMyListMode(listLocation) == "");
}

void Test::getMyListMode_noInput_txtReturnedSuccessfully()
{
	Service service;
	std::string listLocation = "D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt";
	assert(service.changeMyListLocation(listLocation) && service.getMyListMode(listLocation) == "txt");
}

void Test::add_element__validInput__addedSuccessfully()
{
	BirthDate date{ 1,1,1 };
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	Pet element{ name,breed,date,vaccinations,photo };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");

	assert(repository.add_element(element));
}

void Test::add_element__invalidInput__aditionFailed()
{
	BirthDate date{ 1,1,1 };
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	Pet element{ name,breed,date,vaccinations,photo };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.add_element(element);
	try {
		repository.add_element(element);
	}
	catch (ExceptionAddAlreadyExisting error) {
		assert(error.exists);
	}
}

void Test::add_element__noFile__aditionFailed()
{
	BirthDate date{ 1,1,1 };
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	Pet element{ name,breed,date,vaccinations,photo };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	try {
		repository.add_element(element);
	}
	catch (ExceptionNoFile error) {
		assert(error.exists);
	}
}

void Test::add_element__invalidElement__aditionFailed()
{
	BirthDate date{ 1,1,1 };
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 0;
	Pet element{ name,breed,date,vaccinations,photo };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	try {
		repository.add_element(element);
	}
	catch (ExceptionValidationError error) {
		assert(error.exists);
	}
}

void Test::update_element__validInput__breedUpdatedSuccessfully()
{
	BirthDate date{ 1,1,1 }, dateUpdate{ 2,2,2, };
	std::string name = "name", breed = "breed", photo = "photo", breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100, vaccinationsUpdate = 200;
	Pet element{ name,breed,date,vaccinations,photo }, elementUpdate{ name,breedUpdate,dateUpdate,vaccinationsUpdate,photoUpdate };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.add_element(element);
	assert(repository.update_element(elementUpdate) && repository.getElementByName(name).getBreed()==elementUpdate.getBreed());	
}

void Test::update_element__validInput__dateUpdatedSuccessfully()
{
	BirthDate date{ 1,1,1 }, dateUpdate{ 2,2,2, };
	std::string name = "name", breed = "breed", photo = "photo", breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100, vaccinationsUpdate = 200;
	Pet element{ name,breed,date,vaccinations,photo }, elementUpdate{ name,breedUpdate,dateUpdate,vaccinationsUpdate,photoUpdate };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.add_element(element);
	assert(repository.update_element(elementUpdate) && repository.getElementByName(name).getBirthDate() == elementUpdate.getBirthDate());
}

void Test::update_element__validInput__vaccinationsUpdatedSuccessfully()
{
	BirthDate date{ 1,1,1 }, dateUpdate{ 2,2,2, };
	std::string name = "name", breed = "breed", photo = "photo", breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100, vaccinationsUpdate = 200;
	Pet element{ name,breed,date,vaccinations,photo }, elementUpdate{ name,breedUpdate,dateUpdate,vaccinationsUpdate,photoUpdate };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.add_element(element);
	assert(repository.update_element(elementUpdate) && repository.getElementByName(name).getVaccinationsCount() == elementUpdate.getVaccinationsCount());
}

void Test::update_element__validInput__photoUpdatedSuccessfully()
{
	BirthDate date{ 1,1,1 }, dateUpdate{ 2,2,2, };
	std::string name = "name", breed = "breed", photo = "photo", breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100, vaccinationsUpdate = 200;
	Pet element{ name,breed,date,vaccinations,photo }, elementUpdate{ name,breedUpdate,dateUpdate,vaccinationsUpdate,photoUpdate };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.add_element(element);
	assert(repository.update_element(elementUpdate) && repository.getElementByName(name).getPhotograph() == elementUpdate.getPhotograph());
}

void Test::update_element__invalidInput__updateFailed()
{
	BirthDate date{ 1,1,1 }, dateUpdate{ 2,2,2, };
	std::string name = "name", breed = "breed", photo = "photo", breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100, vaccinationsUpdate = 200;
	Pet element{ name,breed,date,vaccinations,photo }, elementUpdate{ name,breedUpdate,dateUpdate,vaccinationsUpdate,photoUpdate };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	try {
		repository.update_element(elementUpdate);
	}
	catch (ExceptionUpdateDoesNotExist error) {
		assert(error.exists);
	}
}

void Test::update_element__noFile__updateFailed()
{
	BirthDate date{ 1,1,1 }, dateUpdate{ 2,2,2, };
	std::string name = "name", breed = "breed", photo = "photo", breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100, vaccinationsUpdate = 200;
	Pet element{ name,breed,date,vaccinations,photo }, elementUpdate{ name,breedUpdate,dateUpdate,vaccinationsUpdate,photoUpdate };
	RepositoryFiles repository;
	try {
		repository.update_element(elementUpdate);
	}
	catch (ExceptionNoFile error) {
		assert(error.exists);
	}
}

void Test::update_element__invalidElement__updateFailed()
{
	BirthDate date{ 1,1,1 }, dateUpdate{ 2,2,2, };
	std::string name = "name", breed = "breed", photo = "photo", breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100, vaccinationsUpdate = 0;
	Pet element{ name,breed,date,vaccinations,photo }, elementUpdate{ name,breedUpdate,dateUpdate,vaccinationsUpdate,photoUpdate };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	try {
		repository.update_element(elementUpdate);
	}
	catch (ExceptionValidationError error) {
		assert(error.exists);
	}
}

void Test::remove_element__validInput__removedSuccessfully()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.add_element(element1);
	repository.add_element(element2);
	assert(repository.remove_element(name1));
}

void Test::remove_element__invalidInput__removeFailed()
{
	BirthDate date{ 1,1,1 };
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	Pet element{ name,breed,date,vaccinations,photo };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	try {
		repository.remove_element(name);
	}
	catch (ExceptionDeleteDoesNotExist error) {
		assert(error.exists);
	}
}

void Test::remove_element__noFile__removeFailed()
{
	BirthDate date{ 1,1,1 };
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	Pet element{ name,breed,date,vaccinations,photo };
	RepositoryFiles repository;
	try {
		repository.remove_element(name);
	}
	catch (ExceptionNoFile error) {
		assert(error.exists);
	}
}

void Test::get_elements__noInput__returnedSuccessfully()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	std::vector<TElem> array,testArray;
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.add_element(element1);
	array.push_back(element1);
	repository.add_element(element2);
	array.push_back(element2);
	testArray = repository.get_elements();
	assert(array[0]==testArray[0] && array[1]==testArray[1]);
}

void Test::get_elements__noPath__exceptionThrown()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	std::vector<TElem> array, testArray;
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("");
	try {
		repository.get_elements();
	}
	catch (ExceptionNoFile error) {
		assert(error.exists);
	}
}

void Test::get_elements__noElements__exceptionThrown()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	std::vector<TElem> array, testArray;
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	try {
		repository.get_elements();
	}
	catch (ExceptionNoElements error) {
		assert(error.exists);
	}
}

void Test::lenght__noInput__returnedSuccessfully()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.add_element(element1);
	repository.add_element(element2);
	assert(repository.lenght()==2);
}

void Test::lenght__noPath__exceptionThrown()
{
	RepositoryFiles repository;
	try {
		repository.lenght();
	}
	catch (ExceptionNoFile error) {
		assert(error.exists);
	}

}

void Test::setFileLocation__validInput__setSuccessfully()
{
	RepositoryFiles repository;
	assert(repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt"));
}

void Test::getElementByIndex__validInput__returnedSuccessfully()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.add_element(element1);
	repository.add_element(element2);
	assert(repository.getElementByIndex(1)==element2);
}

void Test::getElementByIndex__noPath__exceptionThrown()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	try {
		repository.getElementByIndex(1);
	}
	catch (ExceptionNoFile error) {
		assert(error.exists);
	}
}

void Test::getElementByIndex__noElements_exceptionThrown()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	try {
		repository.getElementByIndex(1);
	}
	catch (ExceptionNoElements error) {
		assert(error.exists);
	}
}

void Test::getElementByIndex__indexTooBig__exceptionThrown()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.add_element(element1);
	repository.add_element(element2);
	try {
		repository.getElementByIndex(3);
	}
	catch (ExceptionIndexTooLarge error) {
		assert(error.exists);
	}
}

void Test::getElementByName__validINput__returnedSuccessfully()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.add_element(element1);
	repository.add_element(element2);
	assert(repository.getElementByName(name2) == element2);
}

void Test::getElementByName__noPath__exceptionThrown()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	try {
		repository.getElementByName(name1);
	}
	catch (ExceptionNoFile error) {
		assert(error.exists);
	}
}

void Test::getElementByName__noElements_exceptionThrown()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	try {
		repository.getElementByName(name1);
	}
	catch (ExceptionNoElements error) {
		assert(error.exists);
	}
}

void Test::getElementByName__invalidInput__exceptionThrown()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2 };
	std::string name1 = "name1", breed1 = "breed1", photo1 = "photo1", name2 = "name2", breed2 = "breed2", photo2 = "photo2", name3 = "name3";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	RepositoryFiles repository;
	remove("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.setFileLocation("D:\\Faculta\\An1_sem2\\OOP\\Assignments\\AdoptAPetFiles\\Tests\\test.txt");
	repository.add_element(element1);
	repository.add_element(element2);
	try {
		repository.getElementByName(name3);
	}
	catch (ExceptionElementNotFound error) {
		assert(error.exists);
	}
}

void Test::validateGoodElement_goodElement_validationSuccessfull()
{
	BirthDate date{ 1,1,1 };
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	Pet element{ name,breed,date,vaccinations,photo };
	Validator validate;
	assert(validate.validateGoodElement(element));
}

void Test::validateGoodElement_badDay_validationFailed()
{
	BirthDate date{ 0,1,1 };
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	Pet element{ name,breed,date,vaccinations,photo };
	Validator validate;
	assert(!validate.validateGoodElement(element));
}

void Test::validateGoodElement_badMonth_validationFailed()
{
	BirthDate date{ 1,0,1 };
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	Pet element{ name,breed,date,vaccinations,photo };
	Validator validate;
	assert(!validate.validateGoodElement(element));
}

void Test::validateGoodElement_badYear_validationFailed()
{
	BirthDate date{ 1,1,0 };
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	Pet element{ name,breed,date,vaccinations,photo };
	Validator validate;
	assert(!validate.validateGoodElement(element));
}

void Test::validateGoodElement_badVacciantions_validationFailed()
{
	BirthDate date{ 1,1,1 };
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 0;
	Pet element{ name,breed,date,vaccinations,photo };
	Validator validate;
	assert(!validate.validateGoodElement(element));
}



void Test::BirthDate_validInput_creadedSuccessfully()
{
	int day = 1, month = 1, year = 1;
	BirthDate date;
	date = { 1,1,1 };
	BirthDate tempDate{ day,month,year };
	assert(date == tempDate);
}

void Test::setDay_validInput_daySetSuccessfully()
{
	int day = 1, month = 1, year = 1;
	BirthDate date;
	date = { day,month,year };
	int newDay = 2;
	date.setDay(newDay);
	assert(date.getDay() == newDay);
}

void Test::setMonth_validInput_monthSetSuccessfully()
{
	int day = 1, month = 1, year = 1;
	BirthDate date;
	date = { day,month,year };
	int newMonth = 2;
	date.setMonth(newMonth);
	assert(date.getMonth() == newMonth);
}

void Test::setYear_validInput_yearSetSuccessfully()
{
	int day = 1, month = 1, year = 1;
	BirthDate date;
	date = { day,month,year };
	int newYear = 2;
	date.setYear(newYear);
	assert(date.getYear() == newYear);
}

void Test::getDay_noInput_returnedSuccessfully()
{
	int day = 1, month = 1, year = 1;
	BirthDate date;
	date = { day,month,year };
	assert(date.getDay() == day);
	
}

void Test::getMonth_noInput_returnedSuccessfully()
{
	int day = 1, month = 1, year = 1;
	BirthDate date;
	date = { day,month,year };
	assert(date.getMonth() == month);
}

void Test::getYear_noInput_returnedSuccessfully()
{
	int day = 1, month = 1, year = 1;
	BirthDate date;
	date = { day,month,year };
	assert(date.getYear() == year);
}

void Test::getString_noInput_stringGeneratedSuccessfully()
{
	int day = 1, month = 1, year = 1;
	BirthDate date;
	date = { day,month,year };
	std::string dateString = std::to_string(day) + "-" + std::to_string(month) + "-" + std::to_string(year);
	assert(date.getString() == dateString);
}

void Test::operatorEqualsBirthDate_validInput_true()
{
	int day1 = 1, day2 = 1, month1 = 1, month2 = 1, year1 = 1, year2 = 1;
	BirthDate date1{ day1,month1,year1 }, date2{ day2,month2,year2 };
	assert((date1 == date2) == true);
}

void Test::operatorEqualsBirthDate_invalidInput_false()
{
	int day1 = 1, day2 = 2, month1 = 1, month2 = 2, year1 = 1, year2 = 2;
	BirthDate date1{ day1,month1,year1 }, date2{ day2,month2,year2 };
	assert((date1 == date2) == false);
}

void Test::operatorNotEqualsBirthDate_invalidInput_true()
{
	int day1 = 1, day2 = 2, month1 = 1, month2 = 2, year1 = 1, year2 = 2;
	BirthDate date1{ day1,month1,year1 }, date2{ day2,month2,year2 };
	assert((date1 != date2) == true);
}

void Test::operatorNotEqualsBirthDate_validInput_false()
{
	int day1 = 1, day2 = 1, month1 = 1, month2 = 1, year1 = 1, year2 = 1;
	BirthDate date1{ day1,month1,year1 }, date2{ day2,month2,year2 };
	assert((date1 != date2) == false);
}





void Test::Pet_validInput_createdSuccessfully()
{
	BirthDate date{12,12,2012};
	int vaccinations = 100;
	std::string name = "name", breed = "breed", photo = "photo";
	Pet element;
	element = { "name","breed",BirthDate{12,12,2012},100,"photo" };
	Pet tempElement{ name,breed,date,vaccinations,photo};

	assert(element == tempElement);
}

void Test::setName_validInput_nameSetSuccessfully()
{
	BirthDate date{ 12,12,2012 };
	int vaccinations = 100;
	std::string name = "name", breed = "breed", photo = "photo";
	Pet element{ name,breed,date,vaccinations,photo };

	std::string newName = "newName";
	element.setName(newName);
	assert(element.getName() == newName);
}

void Test::setBreed_validInput_breedSetSuccessfully()
{
	BirthDate date{ 12,12,2012 };
	int vaccinations = 100;
	std::string name = "name", breed = "breed", photo = "photo";
	Pet element{ name,breed,date,vaccinations,photo };

	std::string newBreed = "newBreed";
	element.setBreed(newBreed);
	assert(element.getBreed() == newBreed);
}

void Test::setBirthDate_validInput_dateSetSuccessfully()
{
	BirthDate date{ 12,12,2012 };
	int vaccinations = 100;
	std::string name = "name", breed = "breed", photo = "photo";
	Pet element{ name,breed,date,vaccinations,photo };

	BirthDate newDate{ 1,1,1 };
	element.setBirthDate(newDate);
	assert(element.getBirthDate() == newDate);
}

void Test::setVaccinationsCount_validInput_vaccinationsCountSetSuccessfully()
{
	BirthDate date{ 12,12,2012 };
	int vaccinations = 100;
	std::string name = "name", breed = "breed", photo = "photo";
	Pet element{ name,breed,date,vaccinations,photo };

	int newVaccinations = 200;
	element.setVaccinationsCount(newVaccinations);
	assert(element.getVaccinationsCount() == newVaccinations);
}

void Test::setPhotograph_validInput_photographSetSuccessfully()
{
	BirthDate date{ 12,12,2012 };
	int vaccinations = 100;
	std::string name = "name", breed = "breed", photo = "photo";
	Pet element{ name,breed,date,vaccinations,photo };

	std::string newPhoto = "newPhoto";
	element.setPhotograph(newPhoto);
	assert(element.getPhotograph() == newPhoto);
}

void Test::getName_noInput_nameReturnedSuccessfully()
{
	BirthDate date{ 12,12,2012 };
	int vaccinations = 100;
	std::string name = "name", breed = "breed", photo = "photo";
	Pet element{ name,breed,date,vaccinations,photo };

	assert(element.getName() == name);
}

void Test::getBreed_noInput_breedReturnedSuccessfully()
{
	BirthDate date{ 12,12,2012 };
	int vaccinations = 100;
	std::string name = "name", breed = "breed", photo = "photo";
	Pet element{ name,breed,date,vaccinations,photo };

	assert(element.getBreed() == breed);
}

void Test::getBirthDate_noInput_birthDatereturnedSuccessfully()
{
	BirthDate date{ 12,12,2012 };
	int vaccinations = 100;
	std::string name = "name", breed = "breed", photo = "photo";
	Pet element{ name,breed,date,vaccinations,photo };

	assert(element.getBirthDate() == date);
}

void Test::getVaccinationsCount_noInput_vaccinationsCountReturnedSuccessfully()
{
	BirthDate date{ 12,12,2012 };
	int vaccinations = 100;
	std::string name = "name", breed = "breed", photo = "photo";
	Pet element{ name,breed,date,vaccinations,photo };

	assert(element.getVaccinationsCount() == vaccinations);
}

void Test::getPhotograph_noInput_photographReturnedSuccessfully()
{
	BirthDate date{ 12,12,2012 };
	int vaccinations = 100;
	std::string name = "name", breed = "breed", photo = "photo";
	Pet element{ name,breed,date,vaccinations,photo };

	assert(element.getPhotograph() == photo);
}

void Test::getPrintable_noInput_stringReturnedSuccessfully()
{
	BirthDate date{ 12,12,2012 };
	int vaccinations = 100;
	std::string name = "name", breed = "breed", photo = "photo";
	Pet element{ name,breed,date,vaccinations,photo };
	std::string string = name + "," + breed + "," + date.getString() + "," + std::to_string(vaccinations) + "," + photo;
	assert(element.getPrintable() == string);

}

void Test::operatorEqualsPet_validInput_true()
{
	int day1 = 1, day2 = 1, month1 = 1, month2 = 1, year1 = 1, year2 = 1;
	BirthDate date1{ day1,month1,year1 }, date2{ day2,month2,year2 };
	std::string name1 = "name1", name2 = "name1", breed1 = "breed1", breed2 = "breed1", photo1 = "photo1", photo2 = "photo1";
	int vaccinations1 = 100, vaccinations2 = 100;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	assert((element1 == element2) == true);

}

void Test::operatorEqualsPet_invalidInput_false()
{
	int day1 = 1, day2 = 2, month1 = 1, month2 = 2, year1 = 1, year2 = 2;
	BirthDate date1{ day1,month1,year1 }, date2{ day2,month2,year2 };
	std::string name1 = "name1", name2 = "name2", breed1 = "breed1", breed2 = "breed2", photo1 = "photo1", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	assert((element1 == element2) == false);
}

void Test::operatorNotEqualsPet_invalidInput_true()
{
	int day1 = 1, day2 = 2, month1 = 1, month2 = 2, year1 = 1, year2 = 2;
	BirthDate date1{ day1,month1,year1 }, date2{ day2,month2,year2 };
	std::string name1 = "name1", name2 = "name2", breed1 = "breed1", breed2 = "breed2", photo1 = "photo1", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	assert((element1 != element2) == true);
}

void Test::operatorNotEqualsPet_validInput_false()
{
	int day1 = 1, day2 = 1, month1 = 1, month2 = 1, year1 = 1, year2 = 1;
	BirthDate date1{ day1,month1,year1 }, date2{ day2,month2,year2 };
	std::string name1 = "name1", name2 = "name1", breed1 = "breed1", breed2 = "breed1", photo1 = "photo1", photo2 = "photo1";
	int vaccinations1 = 100, vaccinations2 = 100;
	Pet element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	assert((element1 != element2) == false);
}
