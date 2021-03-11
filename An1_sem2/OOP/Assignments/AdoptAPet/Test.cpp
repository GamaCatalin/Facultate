#include "Test.h"

void Test::testAll()
{	
	//Repository test section

	this->add_element__validInput__nameAddedSuccessfully();
	this->add_element__validInput__breedAddedSuccessfully();
	this->add_element__validInput__dateAddedSuccessfully();
	this->add_element__validInput__vaccinationsAddedSuccessfully();
	this->add_element__validInput__photoAddedSuccessfully();
	
	this->update_element__validInput__breedUpdatedSuccessfully();
	this->update_element__validInput__dateUpdatedSuccessfully();
	this->update_element__validInput__vaccinationsUpdatedSuccessfully();
	this->update_element__validInput__photoUpdatedSuccessfully();

	this->delete_element__noInput__successfullyDeleted();

	this->get_elements__noInput__returnedSuccessfully();



	//Service test section

	this->addElement_validInput_nameAddedSuccessfully();
	this->addElement_validInput_breedAddedSuccessfully();
	this->addElement_validInput_dateAddedSuccessfully();
	this->addElement_validInput_vaccinationsAddedSuccessfully();
	this->addElement_validInput_photoAddedSuccessfully();

	this->updateElementBreed_validInput_updateSuccessfully();
	this->updateElementDate_validInput_updateSuccessfully();
	this->updateElementVaccinations_validInput_updateSuccessfully();
	this->updateElementPhoto_validInput_updateSuccessfully();

	this->deleteElement_validInput_deletedSuccessfully();	

	this->getAll_noInput_returnSuccessfully();
	this->getRunMode_noInput_returnSuccessfully();
	this->setRunMode_validInput_returnSuccesfully();
	this->lenght_noInput_returnSuccessfully();

	this->nextDog_noInput_getNextDog();
	this->nextDog_startOverInput_successfullyStartOver();
	this->saveDog_validInput_savedSuccessfully();
	this->getAdoptionList_noInput_returnedSuccessfully();

	//DynamicVector test section

	this->DynamicVector_validInput_createdSuccessfully();
	this->DynamicVector_noInput_createdSuccessfully();
	this->add_validInput_addedSuccesfully();
	this->add_inputOverCapacity_addedSuccessfully();
	this->update_validInput_updatedSuccessfully();
	this->remove_validInput_removedSuccessfully();
	this->vectorLenght_noInput_returnedSuccessfully();
	this->getElement_validInput_returnedSuccessfully();
	this->operatorEqual_validInput_copiedSuccessfully();
	this->operatorEqual_sameVectorInput_copiedSuccessfully();


	//Date test section

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


	//Pet test section

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


	this->operatorEqualsPet_validInput_true();
	this->operatorEqualsPet_invalidInput_false();
	this->operatorNotEqualsPet_invalidInput_true();
	this->operatorNotEqualsPet_validInput_false();


}

void Test::addElement_validInput_nameAddedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Service service;
	service.addElement(element);
	array = service.getAll();
	assert(array.get_element(0).getName() == name);
}

void Test::addElement_validInput_breedAddedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Service service;
	service.addElement(element);
	array = service.getAll();
	assert(array.get_element(0).getBreed() == breed);
}

void Test::addElement_validInput_dateAddedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Service service;
	service.addElement(element);
	array = service.getAll();
	assert(array.get_element(0).getBirthDate().getString() == date.getString());
}

void Test::addElement_validInput_vaccinationsAddedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Service service;
	service.addElement(element);
	array = service.getAll();
	assert(array.get_element(0).getVaccinationsCount() == vaccinations);
}

void Test::addElement_validInput_photoAddedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Service service;
	service.addElement(element);
	array = service.getAll();
	assert(array.get_element(0).getPhotograph() == photo);
}

void Test::updateElementBreed_validInput_updateSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	DynamicVector<TElem> array;
	Service service;
	service.addElement(element);
	service.updateElement(elementUpdate);
	array = service.getAll();
	assert(array.get_element(0).getBreed() == breedUpdate);
}

void Test::updateElementDate_validInput_updateSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	DynamicVector<TElem> array;
	Service service;
	service.addElement(element);
	service.updateElement(elementUpdate);
	array = service.getAll();
	assert(array.get_element(0).getBirthDate().getString() == dateUpdate.getString());
}

void Test::updateElementVaccinations_validInput_updateSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	DynamicVector<TElem> array;
	Service service;
	service.addElement(element);
	service.updateElement(elementUpdate);
	array = service.getAll();
	assert(array.get_element(0).getVaccinationsCount() == vaccinationUpdate);
}

void Test::updateElementPhoto_validInput_updateSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	DynamicVector<TElem> array;
	Service service;
	service.addElement(element);
	service.updateElement(elementUpdate);
	array = service.getAll();
	assert(array.get_element(0).getPhotograph() == photoUpdate);
}

void Test::deleteElement_validInput_deletedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Service service;
	service.addElement(element);
	service.removeElement(name);
	array = service.getAll();
	assert(array.lenght() == 0);
}

void Test::lenght_noInput_returnSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Service service;
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
	DynamicVector<TElem> array;
	Service service;
	service.addElement(element);
	array = service.getAll();
	assert(array.lenght()==1);
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
	service.addElement(element1);
	service.addElement(element2);
	service.saveDog(name1);
	DynamicVector<TElem> array;
	array = service.getAdoptionList();
	assert(array.lenght() == 1);
}

void Test::getAdoptionList_noInput_returnedSuccessfully()
{
	BirthDate date1{ 1,1,1 }, date2{ 2,2,2, };
	std::string name1 = "name1", name2 = "name2", breed1 = "breed1", breed2 = "breed2", photo1 = "photo1", photo2 = "photo2";
	int vaccinations1 = 100, vaccinations2 = 200;
	TElem element1{ name1,breed1,date1,vaccinations1,photo1 }, element2{ name2,breed2,date2,vaccinations2,photo2 };
	Service service;
	service.addElement(element1);
	service.addElement(element2);
	service.saveDog(name1);
	service.saveDog(name2);
	DynamicVector<TElem> array;
	array = service.getAdoptionList();
	assert(array.get_element(0) == element1 && array.get_element(1)==element2);
}






void Test::add_element__validInput__nameAddedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Repository repository;
	repository.add_element(element);
	array = repository.get_elements();
	assert(array.get_element(0).getName() == name);
}

void Test::add_element__validInput__breedAddedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Repository repository;
	repository.add_element(element);
	array = repository.get_elements();
	assert(array.get_element(0).getBreed() == breed);
}

void Test::add_element__validInput__dateAddedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Repository repository;
	repository.add_element(element);
	array = repository.get_elements();
	assert(array.get_element(0).getBirthDate().getString() == date.getString());
}

void Test::add_element__validInput__vaccinationsAddedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Repository repository;
	repository.add_element(element);
	array = repository.get_elements();
	assert(array.get_element(0).getVaccinationsCount() == vaccinations);
}

void Test::add_element__validInput__photoAddedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Repository repository;
	repository.add_element(element);
	array = repository.get_elements();
	assert(array.get_element(0).getPhotograph() == photo);
}

void Test::update_element__validInput__breedUpdatedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	DynamicVector<TElem> array;
	Repository repository;
	repository.add_element(element);
	repository.update_element(0,elementUpdate);
	array = repository.get_elements();
	assert(array.get_element(0).getBreed() == breedUpdate);
}

void Test::update_element__validInput__dateUpdatedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	DynamicVector<TElem> array;
	Repository repository;
	repository.add_element(element);
	repository.update_element(0, elementUpdate);
	array = repository.get_elements();
	assert(array.get_element(0).getBirthDate().getString() == dateUpdate.getString());
}

void Test::update_element__validInput__vaccinationsUpdatedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	DynamicVector<TElem> array;
	Repository repository;
	repository.add_element(element);
	repository.update_element(0, elementUpdate);
	array = repository.get_elements();
	assert(array.get_element(0).getVaccinationsCount() == vaccinationUpdate);
}

void Test::update_element__validInput__photoUpdatedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	DynamicVector<TElem> array;
	Repository repository;
	repository.add_element(element);
	repository.update_element(0, elementUpdate);
	array = repository.get_elements();
	assert(array.get_element(0).getPhotograph() == photoUpdate);
}

void Test::delete_element__noInput__successfullyDeleted()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Repository repository;
	repository.add_element(element);
	repository.remove_element(0);
	array = repository.get_elements();
	assert(array.lenght() == 0);
}

void Test::get_elements__noInput__returnedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> array;
	Repository repository;
	repository.add_element(element);
	array = repository.get_elements();
	assert(array.lenght() == 1);
}

void Test::DynamicVector_validInput_createdSuccessfully()
{
	DynamicVector<TElem> vector{ 1 };
	assert(&vector != NULL);
}

void Test::DynamicVector_noInput_createdSuccessfully()
{
	DynamicVector<TElem> vector;
	assert(&vector != NULL);
}

void Test::add_validInput_addedSuccesfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> vector;
	vector.add(element);
	assert(vector.get_element(0) == element);	
}

void Test::add_inputOverCapacity_addedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> vector{1};
	vector.add(element);
	vector.add(element);
	vector.add(element);
	assert(vector.get_element(2) == element);
}

void Test::update_validInput_updatedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	std::string breedUpdate = "breedUpdate", photoUpdate = "photoUpdate";
	int vaccinations = 100;
	int vaccinationUpdate = 200;
	BirthDate date{ 12,12,2012 };
	BirthDate dateUpdate{ 1,1,1453 };
	TElem element{ name,breed,date,vaccinations,photo };
	TElem elementUpdate{ name,breedUpdate,dateUpdate,vaccinationUpdate,photoUpdate };
	DynamicVector<TElem> vector;
	vector.add(element);
	vector.update(0,elementUpdate);
	assert(vector.get_element(0) == elementUpdate);
}

void Test::remove_validInput_removedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> vector;
	vector.add(element);
	vector.remove(0);
	assert(vector.lenght()==0);
}

void Test::vectorLenght_noInput_returnedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> vector;
	vector.add(element);
	vector.add(element);
	vector.add(element);
	vector.add(element);
	assert(vector.lenght() == 4);
}

void Test::getElement_validInput_returnedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> vector;
	vector.add(element);
	assert(vector.get_element(0) == element);
}

void Test::operatorEqual_validInput_copiedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> vector,copyVector;
	vector.add(element);
	copyVector = vector;
	assert(&copyVector != NULL);
}

void Test::operatorEqual_sameVectorInput_copiedSuccessfully()
{
	std::string name = "name", breed = "breed", photo = "photo";
	int vaccinations = 100;
	BirthDate date{ 12,12,2012 };
	TElem element{ name,breed,date,vaccinations,photo };
	DynamicVector<TElem> vector;
	vector.add(element);
	vector = vector;
	assert(&vector != NULL);
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
