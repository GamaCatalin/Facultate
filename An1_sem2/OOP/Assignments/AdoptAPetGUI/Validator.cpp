#include "Validator.h"

bool Validator::validateGoodElement(Pet element)
{
	if (element.getBirthDate().getDay() < 1 || element.getBirthDate().getDay() > 31) {
		return false;
	}
	if (element.getBirthDate().getMonth() < 1 || element.getBirthDate().getMonth() > 12) {
		return false;
	}
	if (element.getBirthDate().getYear() < 1 || element.getBirthDate().getYear() > 2100) {
		return false;
	}
	if (element.getVaccinationsCount() < 1) {
		return false;
	}

	return true;
}
