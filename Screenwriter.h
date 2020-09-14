#pragma once
#include <string>
#include <vector>
#include <sstream>


class Screenwriter
{
private:
	std::string name;
	std::string expertize;

public:
	Screenwriter() : name(""), expertize("") {}
	Screenwriter(std::string n, std::string e) : name(n), expertize(e) {}

	std::string getName() const { return this->name; }
	std::string getExpertize() const { return this->expertize; }

	friend std::istream& operator>>(std::istream& is, Screenwriter& i);
	friend std::ostream& operator<<(std::ostream& os, Screenwriter& i);
};
