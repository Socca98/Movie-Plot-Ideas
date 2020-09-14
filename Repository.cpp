#include "Repository.h"
using namespace std;

Repository::Repository(std::string fn)
{
	this->filename = fn;
	this->readWriters();
	this->readIdeas();
}

vector<Idea> Repository::getIdeasSorted()
{
	vector<Idea> res = this->getIdeas();
	auto sortFunction = [](const Idea& e1, const Idea& e2) 
	{ return e1.getAct() < e2.getAct(); };
	//e1.getCreator() < e2.getCreator()
	sort(res.begin(), res.end(), sortFunction);

	return res;
}

int Repository::findByDescription(const Idea & e)
{
	for (int i = 0; i < this->ideas.size(); i++)
	{
		if (this->ideas[i].getDescription() == e.getDescription() && this->ideas[i].getAct() == e.getAct())
			return i;
	}
	return -1;
}

void Repository::addIdea(const Idea & e)
{
	int idx = this->findByDescription(e);
	if (idx != -1)
		throw BadIdeaException("This description on this act already exists!");

	this->ideas.push_back(e);
	this->notify();
}

void Repository::removeIdea(const Idea & e)
{
	//remove(ideas.begin(), ideas.end(), e);
	this->ideas.erase(remove(ideas.begin(), ideas.end(), e), ideas.end());
	this->notify();
}

void Repository::changeStatus(const Idea & e)
{
	int i = this->findByDescription(e);
	if (i == -1)
		throw BadIdeaException("Idea not found!");

	this->ideas[i].setStatus("accepted");
	this->notify();
}

std::vector<Idea> Repository::findByAct(int act)
{
	vector<Idea> res;

	for (auto e : this->ideas)
	{
		if (e.getAct() == act && e.getStatus() == "accepted")
			res.push_back(e);
	}
	return res;
}

std::string Repository::generatePlot()
{
	string res = "";
	vector<Idea> temp;
	for (int j = 1; j <= 3; j++)
	{
		temp = this->findByAct(j);
		if (temp.size() != 0)
		{
			res += "ACT "+ to_string(j) +"\n";
			for (auto e : temp)
			{
				res += e.getDescription() + "[" + e.getCreator() + "]\n";
			}
		}
		res += "\n";
	}
	return res;
}

void Repository::readWriters()
{
	ifstream f("Writers.txt");

	if (!f.is_open())
		throw BadIdeaException("Writers file could not be opened!");

	Screenwriter e{};
	while (f >> e)
		this->writers.push_back(e);

	f.close();
}

void Repository::readIdeas()
{
	ifstream f("Ideas.txt");

	if (!f.is_open())
		throw BadIdeaException("Ideas file could not be opened!");

	Idea e{};
	while (f >> e)
		this->ideas.push_back(e);

	f.close();
}

void Repository::writeIdeas()
{
	//teoretic nu trebe
	ofstream g("plot.txt");

	g << this->generatePlot();

	g.close();
}

