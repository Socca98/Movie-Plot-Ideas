#pragma once
#include "Observer.h"
#include <fstream>
#include "Idea.h"
#include "Screenwriter.h"
#include "Exceptions.h"
#include <algorithm>

class Repository : public Observable
{
private:
	std::vector<Idea> ideas;
	std::vector<Screenwriter> writers;
	std::string filename;

public:
	Repository() : filename("") {}
	Repository(std::string fn);

	int getSizeWriters() const { return this->writers.size(); }
	int getSizeIdeas() const { return this->ideas.size(); }
	std::vector<Idea> getIdeas() const { return this->ideas; }
	std::vector<Screenwriter> getWriters() const { return this->writers; }

	//Sorted by act and creator
	std::vector<Idea> getIdeasSorted();

	//Position of idea with same description
	int findByDescription(const Idea& e);

	/*
	Adds a new idea to the vector of Idea. Only if the same description on the 
	same act does not exist already.
	IN: Idea&
	OUT:-
	Throws: BadIdea - if its not unique
	*/
	void addIdea(const Idea& e);

	/*
	Erases the idea 'e' from the vector of Idea. This can be done only if its status
	is accepted.
	IN: Idea
	OUT:-
	Throws: BadIdeaException - if its status is 'proposed'
	*/
	void removeIdea(const Idea& e);

	/*
	Finds this idea in the vector and changes its status.
	IN: Idea
	OUT:-
	*/
	void changeStatus(const Idea& e);

	/*
	Returns all those who have this act
	*/
	std::vector<Idea> findByAct(int act);

	/*
	Ideas separated on acts.
	*/
	std::string generatePlot();

	void writeIdeas();
private:
	void readWriters();
	void readIdeas();
	
};