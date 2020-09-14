#pragma once

#include <QWidget>
#include "ui_WriterWindow.h"
#include <QMessageBox>

#include "Observer.h"
#include "Controller.h"

class WriterWindow : public QWidget, public Observer
{
	Q_OBJECT

private:
	Controller & ctrl;
	std::string name;

public:
	WriterWindow(Controller& ctrl, std::string name, QWidget *parent = Q_NULLPTR);
	~WriterWindow();

	void initList();
	void update() override;

public slots:
	void addIdeaCommand();
	void savePlotCommand();

private:
	Ui::WriterWindow ui;
};
