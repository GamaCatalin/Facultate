#pragma once

#include <QWidget>
#include "ui_myListWindow.h"
#include <vector>
#include <qdialog.h>
#include "Pet.h"
#include "MyListTableModel.h"

typedef Pet TElem;

class myListWindow : public QWidget
{
	Q_OBJECT

public:
	myListWindow(MyListTableModel* model, QWidget *parent = Q_NULLPTR);
	~myListWindow();
	void buttonClicked();
private:
	Ui::myListWindow ui;
	MyListTableModel* model;
	QDialog* dialog;
};
