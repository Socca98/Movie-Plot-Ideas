#pragma once

#include <QWidget>
#include "ui_SeniorWindow.h"
#include <QMessageBox>

#include "Observer.h"
#include "Controller.h"

class SeniorWindow : public QWidget, public Observer
{
	Q_OBJECT

private:
	Controller & ctrl;
	std::string name;

public:
	SeniorWindow(Controller& ctrl, std::string name, QWidget *parent = Q_NULLPTR);
	~SeniorWindow();

	int getSelectedIndex(const QListWidget * l);
	void initList();
	void update() override;

public slots:
	void addIdeaCommand();
	void savePlotCommand();
	void removeIdeaCommand();
	void acceptCommand();
	void checkStatus();

private:
	Ui::SeniorWindow ui;
};
