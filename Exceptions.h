#pragma once
#include <exception>
#include <string>
#include <vector>

class BadIdeaException : public std::exception
{
private:
	std::string message;

public:
	BadIdeaException(std::string s) : message(s) {}
	const char* what()
	{
		return this->message.c_str();
	}

};