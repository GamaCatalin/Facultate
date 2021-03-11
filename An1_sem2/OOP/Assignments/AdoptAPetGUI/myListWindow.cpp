#include "myListWindow.h"

myListWindow::myListWindow(MyListTableModel* model,QWidget *parent)
	: QWidget(parent), model(model)
{
	ui.setupUi(this);
	this->dialog = new QDialog;
	ui.myListTableView->setModel(this->model);
}

myListWindow::~myListWindow()
{
}

void myListWindow::buttonClicked()
{
	this->dialog->show();
}
