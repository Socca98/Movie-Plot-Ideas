#include "GUI.h"
#include <QtWidgets/QApplication>

#include "Tests.h"
#include "WriterWindow.h"
#include "SeniorWindow.h"
using namespace std;

int main(int argc, char *argv[])
{
	Tests::testRepository();

	try 
	{
		QApplication a(argc, argv);
		Repository repo{ "Ideas.txt" };
		Controller ctrl{ repo };

		for (auto e : repo.getWriters())
		{
			string name = e.getName() + "-" + e.getExpertize();
			if (e.getExpertize() == "Senior")
			{
				//Senior window
				SeniorWindow* w = new SeniorWindow{ctrl, name};
				w->show();
			}
			else
			{
				//Writer window
				WriterWindow* w = new WriterWindow{ctrl, name};
				w->show();
			}
		}

		return a.exec();
	}
	catch (...)
	{

	}

}
