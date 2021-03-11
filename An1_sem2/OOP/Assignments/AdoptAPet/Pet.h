#pragma once
#include <string>

class BirthDate {
private:

    int day;
    int month;
    int year;

public:
    BirthDate();
    BirthDate(int day, int month, int year);

    std::string getString();
    const bool operator == (const BirthDate& date);
    const bool operator != (const BirthDate& date);
    
    //Setters

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    //Getters
    int getDay();
    int getMonth();
    int getYear();


};




class Pet{
private:
    
    std::string name;
    std::string breed;
    int vaccinationsCount;
    BirthDate birthDate;
    std::string photograph;

public:
    Pet();
    Pet(const std::string& name,const std::string& breed,const BirthDate& birthDate,const int& vaccinationsCount,const std::string& photograph);
    const bool operator == (const Pet& element);
    const bool operator != (const Pet& element);

    //Setters
    void setName(std::string name);
    void setBreed(std::string breed);
    void setBirthDate(BirthDate birthDate);
    void setVaccinationsCount(int vaccinationsCount);
    void setPhotograph(std::string photograph);


    //Getters
    std::string getName() const;
    std::string getBreed() const;
    BirthDate getBirthDate() const;
    int getVaccinationsCount() const;
    std::string getPhotograph() const;
};

