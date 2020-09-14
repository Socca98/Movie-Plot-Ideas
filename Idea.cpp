#include "Idea.h"
using namespace std;

std::istream & operator>>(std::istream & is, Idea & i)
{
	string s;
	getline(is, s);

	vector<string> res;
	stringstream ss(s);
	string aux;

	while (getline(ss, aux, '|'))
		res.push_back(aux);

	if (res.size() != 4)
		return is;

	i.description = res[0];
	i.status = res[1];
	i.creator = res[2];
	i.act = stoi(res[3]);

	return is;
}

std::ostream & operator<<(std::ostream & os, Idea & i)
{
	os << i.description << "|" << i.status << "|" << i.creator << "|" << i.act << endl;
	return os;
}

bool Idea::operator==(const Idea & e)
{
	if (this->description == e.description && this->act == e.act)
		return true;
	return false;
}
