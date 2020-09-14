#include "SeniorWindow.h"
using namespace std;

SeniorWindow::SeniorWindow(Controller& c, std::string name, QWidget *parent)
	: ctrl(c), name(name), QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowTitle(this->name.c_str());
	this->ctrl.addObserver(this);
	this->initList();
}

SeniorWindow::~SeniorWindow()
{
	this->ctrl.removeObserver(this);
}

void SeniorWindow::initList()
{
	try
	{
		this->ui.ideasList->clear();
		
		string buffer = "";
		for (auto e : this->ctrl.getRepo().getIdeasSorted())
		{
			buffer = e.getDescription() + "|" + e.getStatus() + "|" + e.getCreator() + "|" + to_string(e.getAct());
			this->ui.ideasList->addItem(new QListWidgetItem{buffer.c_str()});
		}
	}
	catch (BadIdeaException& e)
	{
		QMessageBox::warning(0, "Error", e.what());
	}
}

void SeniorWindow::update()
{
	this->initList();
}

void SeniorWindow::savePlotCommand()
{
	try
	{
		this->ctrl.getRepo().writeIdeas();
	}
	catch (BadIdeaException& e)
	{
		QMessageBox::warning(0, "Error", e.what());
	}
}

void SeniorWindow::removeIdeaCommand()
{
	try
	{
		int idx = this->getSelectedIndex(this->ui.ideasList);
		if (idx == -1)
			throw BadIdeaException("No item selected!");

		Idea e = this->ctrl.getRepo().getIdeasSorted()[idx];
		this->ctrl.removeIdea(e.getDescription(), e.getStatus(), e.getAct());
	}
	catch (BadIdeaException& e)
	{
		QMessageBox::warning(0, "Error", e.what());
	}
}

int SeniorWindow::getSelectedIndex(const QListWidget * l)
{
	//if the list is empty
	if (l->count() == 0)
		return -1;

	QModelIndexList index = l->selectionModel()->selectedIndexes();
	if (index.size() == 0) //if no index was selected
		return -1;

	int idx = index.at(0).row();
	return idx;
}


void SeniorWindow::acceptCommand()
{
	try
	{
		
		int idx = this->getSelectedIndex(this->ui.ideasList);
		if (idx == -1)
			throw BadIdeaException("No item selected!");

		Idea e = this->ctrl.getRepo().getIdeasSorted()[idx];
		
		this->ctrl.changeStatus(e.getDescription(), e.getAct());
	}
	catch (BadIdeaException& e)
	{
		QMessageBox::warning(0, "Error", e.what());
	}
}

void SeniorWindow::checkStatus()
{
	try
	{
		int idx = this->getSelectedIndex(this->ui.ideasList);
		if (idx == -1)
			return;

		Idea e = this->ctrl.getRepo().getIdeasSorted()[idx];
		 
		string s =  this->ui.ideasList->currentItem()->text().toStdString();
		if (s.find("accepted") != string::npos)
		//if(e.getStatus() == "accepted")
			this->ui.acceptButton->setEnabled(false);
		else
			this->ui.acceptButton->setEnabled(true);
	}
	catch (BadIdeaException& e)
	{
		QMessageBox::warning(0, "Error", e.what());
	}

}

void SeniorWindow::addIdeaCommand()
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

