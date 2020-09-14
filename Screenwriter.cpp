#include "Screenwriter.h"
using namespace std;

std::istream & operator>>(std::istream & is, Screenwriter & i)
{
	string s;
	getline(is, s);

	vector<string> res;
	stringstream ss(s);
	string aux;

	while (getline(ss, aux, '|'))
		res.push_back(aux);

	if (res.size() != 2)
		return is;

	i.name = res[0];
	i.expertize = res[1];

	return is;
}

std::ostream & operator<<(std::ostream & os, Screenwriter & i)
{
	os << i.name << "|" << i.expertize << endl;
	return os;
}
