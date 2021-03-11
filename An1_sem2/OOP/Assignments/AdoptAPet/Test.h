#pragma once
#include "Service.h"
#include <assert.h>


class Test {
public:
	void testAll();
private:
	Service service;
public:
	//Service section

	void addElement_validInput_nameAddedSuccessfully();
	void addElement_validInput_breedAddedSuccessfully();
	void addElement_validInput_dateAddedSuccessfully();
	void addElement_validInput_vaccinationsAddedSuccessfully();
	void addElement_validInput_photoAddedSuccessfully();

	void updateElementBreed_validInput_updateSuccessfully();
	void updateElementDate_validInput_updateSuccessfully();
	void updateElementVaccinations_validInput_updateSuccessfully();
	void updateElementPhoto_validInput_updateSuccessfully();

	void deleteElement_validInput_deletedSuccessfully();

	void lenght_noInput_returnSuccessfully();

	void getAll_noInput_returnSuccessfully();

	void getRunMode_noInput_returnSuccessfully();
	void setRunMode_validInput_returnSuccesfully();
	void nextDog_noInput_getNextDog();
	void nextDog_startOverInput_successfullyStartOver();
	void saveDog_validInput_savedSuccessfully();
	void getAdoptionList_noInput_returnedSuccessfully();



	//Repository section


	void add_element__validInput__nameAddedSuccessfully();
	void add_element__validInput__breedAddedSuccessfully();
	void add_element__validInput__dateAddedSuccessfully();
	void add_element__validInput__vaccinationsAddedSuccessfully();
	void add_element__validInput__photoAddedSuccessfully();

	void update_element__validInput__breedUpdatedSuccessfully();
	void update_element__validInput__dateUpdatedSuccessfully();
	void update_element__validInput__vaccinationsUpdatedSuccessfully();
	void update_element__validInput__photoUpdatedSuccessfully();

	void delete_element__noInput__successfullyDeleted();

	void get_elements__noInput__returnedSuccessfully();

	//DynamicVector section
	
	void DynamicVector_validInput_createdSuccessfully();
	void DynamicVector_noInput_createdSuccessfully();
	void add_validInput_addedSuccesfully();
	void add_inputOverCapacity_addedSuccessfully();
	void update_validInput_updatedSuccessfully();
	void remove_validInput_removedSuccessfully();
	void vectorLenght_noInput_returnedSuccessfully();
	void getElement_validInput_returnedSuccessfully();
	void operatorEqual_validInput_copiedSuccessfully();
	void operatorEqual_sameVectorInput_copiedSuccessfully();


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

	void operatorEqualsPet_validInput_true();
	void operatorEqualsPet_invalidInput_false();
	void operatorNotEqualsPet_invalidInput_true();
	void operatorNotEqualsPet_validInput_false();

};