#include "Tests.h"

void Tests::testRepository()
{
	Repository repo{};

	Idea e1 = { "Choose chosen one" , "proposed" , "Socaciu Mihai" , 2 };
	Idea e2 = { "Help poor people", "proposed", "Stefan Suhani", 1 };
	Idea e3 = { "Choose chosen one" , "accepted" , "Duca Andrada" , 2 };

	//Add function
	repo.addIdea(e1);

	int len = repo.getSizeIdeas();
	assert(len == 1);

	//same descr and act
	try
	{
		repo.addIdea(e3);
		assert(false);
	}
	catch (BadIdeaException&)
	{
		assert(true);
	}

	//Remove function
	repo.removeIdea(e1);
	len = repo.getSizeIdeas();
	assert(len == 0);
}
