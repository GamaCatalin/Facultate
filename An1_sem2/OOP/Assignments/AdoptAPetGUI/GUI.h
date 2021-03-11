#pragma once
#include <qwidget.h>
#include "Service.h"
#include <qlistwidget.h>
#include <qcalendarwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qformlayout.h>
#include <qgridlayout.h>
#include <vector>
#include <QDate>

class GUI :
	public QWidget
{
private:
	Service service;

	QListWidget* elements;
	QLineEdit* nameLineEdit, * breedLineEdit, * photoLineEdit, * vaccinationsLineEdit,*dateLineEdit;
	QCalendarWidget* dateCalendar;
	QPushButton* addButton, * deleteButton, * updateButton;
public:
	GUI(Service service);

private:
	void initializeGUI();
	void populateList();
	void connectFields();
	int getElementIndex();

	void writeFields();
};

