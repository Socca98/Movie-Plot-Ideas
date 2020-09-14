#include "WriterWindow.h"
using namespace std;

WriterWindow::WriterWindow(Controller& c, std::string name, QWidget *parent)
	: ctrl(c), name(name), QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowTitle(this->name.c_str());
	this->ctrl.addObserver(this);
	this->initList();
}

WriterWindow::~WriterWindow()
{
	this->ctrl.removeObserver(this);
}

void WriterWindow::initList()
{
	try
	{
		this->ui.ideasList->clear();

		string buffer = "";
		for (auto e : this->ctrl.getRepo().getIdeasSorted())
		{
			buffer = e.getDescription() + "|" + e.getStatus() + "|" + e.getCreator() + "|" + to_string(e.getAct());
			this->ui.ideasList->addItem(new QListWidgetItem{ buffer.c_str() });
		}
	}
	catch (BadIdeaException& e)
	{
		QMessageBox::warning(0, "Error", e.what());
	}
}

void WriterWindow::update()
{
	this->initList();
}

void WriterWindow::savePlotCommand()
{
	try
	{

	}
	catch (BadIdeaException& e)
	{
		QMessageBox::warning(0, "Error", e.what());
	}
}


void WriterWindow::addIdeaCommand()
{
	try
	{
		string descr = this->ui.descriptionLineEdit->text().toStdString();
		int act = this->ui.actLineEdit->text().toInt();
		string creator = "";
		for (auto c : this->name)
		{
			//Take only the name not the expertize
			if (c == '-')
				break;
			creator += c;
		}
		this->ctrl.addIdea(descr, "proposed", creator, act);
	}
	catch (BadIdeaException& e)
	{
		QMessageBox::warning(0, "Error", e.what());
	}
}
