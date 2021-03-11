#pragma once
#include <time.h>
#include <string>

class Message
{
public:
	std::string message;
	time_t timestamp;
	Message(std::string message = "");
};

