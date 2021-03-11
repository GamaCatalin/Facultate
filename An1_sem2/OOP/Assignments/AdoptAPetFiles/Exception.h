#pragma once
#include <exception>
#include <string>
#include <iostream>

class ExceptionNoFile : public std::exception
{
private:
	std::string message;
public:
	bool exists;
	ExceptionNoFile(std::string message);
	const char* what() const throw() override;
};

class ExceptionAddAlreadyExisting : public std::exception
{
private:
	std::string message;
public:
	bool exists;
	ExceptionAddAlreadyExisting(std::string message);
	const char* what() const throw() override;
};

class ExceptionDeleteDoesNotExist : public std::exception
{
private:
	std::string message;
public:
	bool exists;
	ExceptionDeleteDoesNotExist(std::string message);
	const char* what() const throw() override;
};

class ExceptionUpdateDoesNotExist : public std::exception
{
private:
	std::string message;
public:
	bool exists;
	ExceptionUpdateDoesNotExist(std::string message);
	const char* what() const throw() override;
};

class ExceptionNoElements : public std::exception
{
private:
	std::string message;
public:
	bool exists;
	ExceptionNoElements(std::string message);
	const char* what() const throw() override;
};

class ExceptionElementNotFound : public std::exception
{
private:
	std::string message;
public:
	bool exists;
	ExceptionElementNotFound(std::string message);
	const char* what() const throw() override;
};

class ExceptionIndexTooLarge : public std::exception
{
private:
	std::string message;
public:
	bool exists;
	ExceptionIndexTooLarge(std::string message);
	const char* what() const throw() override;
};

class ExceptionValidationError : public std::exception
{
private:
	std::string message;
public:
	bool exists;
	ExceptionValidationError(std::string message);
	const char* what() const throw() override;
};