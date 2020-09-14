#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository & repo;

public:
	Controller(Repository& r) : repo(r) {}

	Repository& getRepo() const { return this->repo; }

	void addIdea(std::string description, std::string status, std::string creator, int act);
	void removeIdea(std::string description, std::string status, int act);
	void changeStatus(std::string description, int act);

	void addObserver(Observer* e) { this->repo.registerObserver(e); }
	void removeObserver(Observer* e) { this->repo.removeObserver(e); }
};