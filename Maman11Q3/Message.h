#pragma once
#include <string>

class Message
{
private:
	std::string text;
public:
	Message();
	Message(std::string);
	std::string getText();
};

