#include "Pet.h"

Pet::Pet() :name(""), breed(""), birthDate{ BirthDate{0,0,0} }, vaccinationsCount(0), photograph(""){

}

Pet::Pet(const std::string& name, const std::string& breed, const BirthDate& birthDate, const int& vaccinationsCount, const std::string& photograph)
{
	this->birthDate = birthDate;
	this->breed = breed;
	this->name = name;
	this->vaccinationsCount = vaccinationsCount;
	this->photograph = photograph;
}

const bool Pet::operator==(const Pet& element)
{
	if (this->name != element.name || this->breed != element.breed || this->birthDate != element.birthDate || this->vaccinationsCount != element.vaccinationsCount || this->photograph != element.photograph) {
		return false;
	}
	return true;
}

const bool Pet::operator!=(const Pet& element)
{
	if (this->name == element.name && this->breed == element.breed && this->birthDate == element.birthDate && this->vaccinationsCount == element.vaccinationsCount && this->photograph == element.photograph) {
		return false;
	}
	return true;
}

std::vector<std::string> splitString(std::string& inputString, char delimiter)
{
	std::vector<std::string> splitString;
	std::string word;
	std::istringstream wordStream(inputString);
	while (std::getline(wordStream, word, delimiter)) {
		splitString.push_back(word);
	}
	
	return splitString;
}

std::istream& operator >>(std::istream& inputStream, Pet& element)
{
	std::string line;
	getline(inputStream, line);
	char delimiterComma = ',',delimiterLine='-';

	std::vector<std::string> words = splitString(line, delimiterComma);
	if (words.size() != 5)
		return inputStream;
	std::vector<std::string> dateValues = splitString(words[2], delimiterLine);
	int day, month, year;
	day = stoi(dateValues[0]);
	month = stoi(dateValues[1]);
	year = stoi(dateValues[2]);

	element.setName(words[0]);
	element.setBreed(words[1]);
	element.setBirthDate(BirthDate(day, month, year));
	element.setVaccinationsCount(stoi(words[3]));
	element.setPhotograph(words[4]);

	return inputStream;
}

std::ostream& operator <<(std::ostream& outputStream, Pet& element)
{
	outputStream << element.getName() + "," << element.getBreed() << "," << element.getBirthDate().getString() << "," << element.getVaccinationsCount() << "," << element.getPhotograph()<<"\n";
	return outputStream;
}

std::string Pet::getPrintable()
{
	std::string printable;
	printable = this->name + "," + this->breed + "," + this->birthDate.getString() + "," + std::to_string(this->vaccinationsCount) + "," + this->photograph;
	return printable;
}

bool Pet::setName(std::string name)
{
	this->name = name;
	return true;
}

bool Pet::setBreed(std::string breed)
{
	this->breed = breed;
	return true;
}

bool Pet::setBirthDate(BirthDate birthDate)
{
	this->birthDate = birthDate;
	return true;
}


bool Pet::setVaccinationsCount(int vaccinationsCount)
{
	this->vaccinationsCount = vaccinationsCount;
	return true;
}

bool Pet::setPhotograph(std::string photograph)
{
	this->photograph = photograph;
	return true;
}

std::string Pet::getName() const
{
	return this->name;
}

std::string Pet::getBreed() const
{
	return this->breed;
}

BirthDate Pet::getBirthDate() const
{
	return this->birthDate;
}

int Pet::getVaccinationsCount() const
{
	return this->vaccinationsCount;
}

std::string Pet::getPhotograph() const
{
	return this->photograph;
}

BirthDate::BirthDate() :day{ 0 }, month{ 0 }, year{ 0 }{

}

BirthDate::BirthDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

std::string BirthDate::getString()
{
	std::string tempString;
	tempString += std::to_string(this->day) + "-" + std::to_string(this->month) + "-" + std::to_string(this->year);
	return tempString;
}

const bool BirthDate::operator==(const BirthDate& date)
{
	if (this->day != date.day || this->month != date.month || this->year != date.year) {
		return false;
	}
	return true;
}

const bool BirthDate::operator!=(const BirthDate& date)
{
	if (this->day == date.day && this->month == date.month && this->year == date.year) {
		return false;
	}
	return true;
}

void BirthDate::setDay(int day)
{
	this->day = day;
}

void BirthDate::setMonth(int month)
{
	this->month = month;
}

void BirthDate::setYear(int year)
{
	this->year = year;
}

int BirthDate::getDay()
{
	return this->day;
}

int BirthDate::getMonth()
{
	return this->month;
}

int BirthDate::getYear()
{
	return this->year;
}
