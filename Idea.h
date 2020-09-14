#pragma once
#include <string>
#include <sstream>
#include <vector>

class Idea
{
private:
	std::string description;
	std::string status;
	std::string creator;
	int act;

public:
	Idea() : description(""), status(""), creator(""), act(1) {}
	Idea(std::string d, std::string s, std::string c, int act) :
		description(d), status(s), creator(c), act(act) {}

	std::string getDescription() const { return this->description; }
	std::string getStatus() const { return this->status; }
	std::string getCreator() const { return this->creator; }
	int getAct() const { return this->act; }

	void setStatus(std::string value) { this->status = value; }

	bool operator==(const Idea& e);

	friend std::istream& operator>>(std::istream& is, Idea& i);
	friend std::ostream& operator<<(std::ostream& os, Idea& i);
};