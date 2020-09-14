#include "Controller.h"

void Controller::addIdea(std::string description, std::string status, std::string creator, int act)
{
	if (description == "")
		throw BadIdeaException("The description is empty!");

	if(act < 1 || act > 3)
		throw BadIdeaException("The act is not valid! (1/2/3)");

	Idea e{ description, status, creator, act };
	this->repo.addIdea(e);
}

void Controller::removeIdea(std::string description, std::string status, int act)
{
	if (status == "accepted")
		throw BadIdeaException("Cannot delete accepted ideas!");

	Idea e{ description, status, "", act };
	this->repo.removeIdea(e);
}

void Controller::changeStatus(std::string description, int act)
{
	Idea e{ description, "proposed", "", act };
	this->repo.changeStatus(e);
}
