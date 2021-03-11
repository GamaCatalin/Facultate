#include "Message.h"

Message::Message(std::string message)
{
	this->message = message;
	this->timestamp = time(NULL);
}
