#pragma once
#include "Pet.h"
#include "RepositoryFiles.h"
#include "Service.h"
#include <assert.h>


class Test {
public:
	void testAll();
private:
	Service service;
public:
	//Service section

	void addElement_validInput_elementAddedSuccessfully();
	void addElement_invalidInput_aditionFailed();


	void updateElement_validInput_breedUpdatedSuccessfully();
	void updateElement_validInput_dateUpdatedSuccessfully();
	void updateElement_validInput_vaccinationsUpdatedSuccessfully();
	void updateElement_validInput_photoUpdatedSuccessfully();
	void updateElement_invalidInput_updateFailed();

	void deleteElement_validInput_deletedSuccessfully();
	void deleteElement_invalidInput_deletionFailed();

	void lenght_noInput_returnSuccessfully();

	void getAll_noInput_returnSuccessfully();

	void getRunMode_noInput_returnSuccessfully();
	void setRunMode_validInput_returnSuccesfully();
	void nextDog_noInput_getNextDog();
	void nextDog_startOverInput_successfullyStartOver();
	void saveDog_validInput_savedSuccessfully();
	void saveDog_invalidInput_notSaved();
	void getAdoptionList_noInput_returnedSuccessfully();

	void changeMyListLocation_validInput_changedSuccessfully();
	void getMyListMode_noInput_htmlReturnedSuccessfully();
	void getMyListMode_noInput_csvReturnedSuccessfully();
	void getMyListMode_noInput_memoryReturnedSuccessfully();
	void getMyListMode_noInput_txtReturnedSuccessfully();

	//Repository section


	void add_element__validInput__addedSuccessfully();
	void add_element__invalidInput__aditionFailed();
	void add_element__noFile__aditionFailed();
	void add_element__invalidElement__aditionFailed();

	void update_element__validInput__breedUpdatedSuccessfully();
	void update_element__validInput__dateUpdatedSuccessfully();
	void update_element__validInput__vaccinationsUpdatedSuccessfully();
	void update_element__validInput__photoUpdatedSuccessfully();
	void update_element__invalidInput__updateFailed();
	void update_element__noFile__updateFailed();
	void update_element__invalidElement__updateFailed();

	void remove_element__validInput__removedSuccessfully();
	void remove_element__invalidInput__removeFailed();
	void remove_element__noFile__removeFailed();

	void get_elements__noInput__returnedSuccessfully();
	void get_elements__noPath__exceptionThrown();
	void get_elements__noElements__exceptionThrown();

	void lenght__noInput__returnedSuccessfully();
	void lenght__noPath__exceptionThrown();

	void setFileLocation__validInput__setSuccessfully();


	void getElementByIndex__validInput__returnedSuccessfully();
	void getElementByIndex__noPath__exceptionThrown();
	void getElementByIndex__noElements_exceptionThrown();
	void getElementByIndex__indexTooBig__exceptionThrown();


	void getElementByName__validINput__returnedSuccessfully();
	void getElementByName__noPath__exceptionThrown();
	void getElementByName__noElements_exceptionThrown();
	void getElementByName__invalidInput__exceptionThrown();

	//Validator section

	void validateGoodElement_goodElement_validationSuccessfull();
	void validateGoodElement_badDay_validationFailed();
	void validateGoodElement_badMonth_validationFailed();
	void validateGoodElement_badYear_validationFailed();
	void validateGoodElement_badVacciantions_validationFailed();


	//Date section

	void BirthDate_validInput_creadedSuccessfully();
	void setDay_validInput_daySetSuccessfully();
	void setMonth_validInput_monthSetSuccessfully();
	void setYear_validInput_yearSetSuccessfully();
	void getDay_noInput_returnedSuccessfully();
	void getMonth_noInput_returnedSuccessfully();
	void getYear_noInput_returnedSuccessfully();
	void getString_noInput_stringGeneratedSuccessfully();

	void operatorEqualsBirthDate_validInput_true();
	void operatorEqualsBirthDate_invalidInput_false();
	void operatorNotEqualsBirthDate_invalidInput_true();
	void operatorNotEqualsBirthDate_validInput_false();


	//Pet section

	void Pet_validInput_createdSuccessfully();

	void setName_validInput_nameSetSuccessfully();
	void setBreed_validInput_breedSetSuccessfully();
	void setBirthDate_validInput_dateSetSuccessfully();
	void setVaccinationsCount_validInput_vaccinationsCountSetSuccessfully();
	void setPhotograph_validInput_photographSetSuccessfully();

	void getName_noInput_nameReturnedSuccessfully();
	void getBreed_noInput_breedReturnedSuccessfully();
	void getBirthDate_noInput_birthDatereturnedSuccessfully();
	void getVaccinationsCount_noInput_vaccinationsCountReturnedSuccessfully();
	void getPhotograph_noInput_photographReturnedSuccessfully();
	void getPrintable_noInput_stringReturnedSuccessfully();

	void operatorEqualsPet_validInput_true();
	void operatorEqualsPet_invalidInput_false();
	void operatorNotEqualsPet_invalidInput_true();
	void operatorNotEqualsPet_validInput_false();

};
