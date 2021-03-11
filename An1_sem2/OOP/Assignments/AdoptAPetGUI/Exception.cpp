#include "Exception.h"

ExceptionNoFile::ExceptionNoFile(std::string message)
{
	this->exists = true;
	this->message = message;
}

const char* ExceptionNoFile::what() const throw()
{
	return this->message.c_str();
}

ExceptionAddAlreadyExisting::ExceptionAddAlreadyExisting(std::string message)
{
	this->exists = true;
	this->message = message;
}

const char* ExceptionAddAlreadyExisting::what() const throw()
{
	return this->message.c_str();
}

ExceptionDeleteDoesNotExist::ExceptionDeleteDoesNotExist(std::string message)
{
	this->exists = true;
	this->message = message;
}

const char* ExceptionDeleteDoesNotExist::what() const throw()
{
	return this->message.c_str();
}

ExceptionUpdateDoesNotExist::ExceptionUpdateDoesNotExist(std::string message)
{
	this->exists = true;
	this->message = message;
}

const char* ExceptionUpdateDoesNotExist::what() const throw()
{
	return this->message.c_str();
}

ExceptionNoElements::ExceptionNoElements(std::string message)
{
	this->exists = true;
	this->message = message;
}

const char* ExceptionNoElements::what() const throw()
{
	return this->message.c_str();
}

ExceptionElementNotFound::ExceptionElementNotFound(std::string message)
{
	this->exists = true;
	this->message = message;
}

const char* ExceptionElementNotFound::what() const throw()
{
	return this->message.c_str();
}

ExceptionIndexTooLarge::ExceptionIndexTooLarge(std::string message)
{
	this->exists = true;
	this->message = message;
}

const char* ExceptionIndexTooLarge::what() const throw()
{
	return this->message.c_str();
}

ExceptionValidationError::ExceptionValidationError(std::string message)
{
	this->exists = true;
	this->message = message;
}

const char* ExceptionValidationError::what() const throw()
{
	return this->message.c_str();
}

ExceptionNoUndo::ExceptionNoUndo(std::string message)
{
	this->exists = true;
	this->message = message;
}

const char* ExceptionNoUndo::what() const throw()
{
	return this->message.c_str();;
}

ExceptionNoRedo::ExceptionNoRedo(std::string message)
{
	this->exists = true;
	this->message = message;
}

const char* ExceptionNoRedo::what() const throw()
{
	return this->message.c_str();
}
