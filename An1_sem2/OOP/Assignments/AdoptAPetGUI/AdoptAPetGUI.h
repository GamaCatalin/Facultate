#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AdoptAPetGUI.h"
#include "Service.h"
#include <qmessagebox.h>
#include <qshortcut.h>
#include "myListWindow.h"

class AdoptAPetGUI : public QMainWindow
{
	Q_OBJECT

public:
	AdoptAPetGUI(Service service,QWidget *parent = Q_NULLPTR);
	Service service;
private:
	
	Ui::AdoptAPetGUIClass ui;
	void populateList();
	void populateListSingle();
	void populateFilter();
	void connectSignals();
	int getElementIndex();
	
	void addElement();
	void deleteElement();
	void updateElement();

	void undo();
	void redo();

	void nextElement();
	void saveElement();

	void setMyListLocation();
	void setFileLocation();

	void myList();
	void openMyListWindow();

	void switchMode();
};
