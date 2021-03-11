#include "AdoptAPetGUI.h"

AdoptAPetGUI::AdoptAPetGUI(Service service,QWidget* parent )
	: QMainWindow(parent)
{
	this->service = service;
	this->service.setRunMode("A");
	ui.setupUi(this);
	this->populateList();
	this->connectSignals();
}

void AdoptAPetGUI::populateList()
{
	this->ui.elementsListWidget->clear();

	std::vector<TElem> elements;
	try {
		elements = this->service.getAll();
	}
	catch (ExceptionNoElements error) {
		QMessageBox::critical(this, "Error", error.what());
	}
	for (auto& element : elements) {
		this->ui.elementsListWidget->addItem(QString::fromStdString(element.getPrintable()));
	}
}

void AdoptAPetGUI::populateListSingle()
{
	this->ui.elementsListWidget->clear();

	TElem element = this->service.getAll()[this->service.userCurrentDogIndex];

	this->ui.elementsListWidget->addItem(QString::fromStdString(element.getPrintable()));

}

void AdoptAPetGUI::populateFilter()
{
	this->ui.elementsListWidget->clear();

	std::vector<TElem> elements,tempElements;
	std::string inputFilter, breed;
	int vaccinations=0;
	bool noBreed = true;
	bool noFilter = true;
	tempElements = this->service.getAll();
	
	inputFilter = this->ui.filterLineEdit->text().toStdString();

	if (inputFilter.size() == 0) {
		noFilter = true;
		this->populateList();
		return;
	}
	else {
		for (int i = 0; i < inputFilter.size(); i++) {
			if (inputFilter.at(i) == ',') {
				noBreed = false;
				breed = inputFilter.substr(0, i);
				vaccinations = stoi(inputFilter.substr(i + 1, inputFilter.size()));
				break;
			}
		}
		if (noBreed) {
			vaccinations = stoi(inputFilter);
		}
	}

	for (auto& element : tempElements) {
		if (noBreed) {
			if (element.getVaccinationsCount() <= vaccinations) {
				this->ui.elementsListWidget->addItem(QString::fromStdString(element.getPrintable()));
			}
		}
		else {
			if (element.getBreed() == breed && element.getVaccinationsCount() <= vaccinations) {
				this->ui.elementsListWidget->addItem(QString::fromStdString(element.getPrintable()));
			}
		}
	}
}

void AdoptAPetGUI::connectSignals()
{
	QObject::connect(this->ui.deleteButtonWidget, &QPushButton::clicked, this, &AdoptAPetGUI::deleteElement);
	QObject::connect(this->ui.addButtonWidget, &QPushButton::clicked, this, &AdoptAPetGUI::addElement);
	QObject::connect(this->ui.updateButtonWidget, &QPushButton::clicked, this, &AdoptAPetGUI::updateElement);
	QObject::connect(this->ui.modeSwitchButtonWidget, &QPushButton::clicked, this, &AdoptAPetGUI::switchMode);
	QObject::connect(this->ui.nextButtonWidget, &QPushButton::clicked, this, &AdoptAPetGUI::nextElement);
	QObject::connect(this->ui.saveButtonWidget, &QPushButton::clicked, this, &AdoptAPetGUI::saveElement);
	QObject::connect(this->ui.myListButtonWidget, &QPushButton::clicked, this, &AdoptAPetGUI::myList);
	QObject::connect(this->ui.setMyListLocationButtonWidget, &QPushButton::clicked, this, &AdoptAPetGUI::setMyListLocation);
	QObject::connect(this->ui.setRepositoryFileLocation, &QPushButton::clicked, this, &AdoptAPetGUI::setFileLocation);
	QObject::connect(this->ui.filterButtonWidget, &QPushButton::clicked, this, &AdoptAPetGUI::populateFilter);
	QObject::connect(this->ui.undoButtonWidget, &QPushButton::clicked, this, &AdoptAPetGUI::undo);
	QObject::connect(this->ui.redoButtonWidget, &QPushButton::clicked, this, &AdoptAPetGUI::redo);
	QObject::connect(this->ui.myListWindowButtonWidget, &QPushButton::clicked, this, &AdoptAPetGUI::openMyListWindow);


	QObject::connect(this->ui.elementsListWidget, &QListWidget::itemSelectionChanged, [this] {
		
		if (this->service.getRunMode() == "A") {
			int selectedIndex = this->getElementIndex();

			if (selectedIndex < 0)
				return;

			TElem element = this->service.getAll()[selectedIndex];

			QDate date;

			date.setDate(element.getBirthDate().getYear(), element.getBirthDate().getMonth(), element.getBirthDate().getDay());

			this->ui.nameLineEdit->setText(QString::fromStdString(element.getName()));
			this->ui.breedLineEdit->setText(QString::fromStdString(element.getBreed()));
			this->ui.vaccinationsLineEdit->setText(QString::fromStdString(std::to_string(element.getVaccinationsCount())));
			this->ui.photographLineEdit->setText(QString::fromStdString(element.getPhotograph()));
			this->ui.dateCalendarWidget->dateTextFormat(date);
		}
		else {

			int selectedIndex = this->service.userCurrentDogIndex;

			TElem element = this->service.getAll()[selectedIndex];

			QDate date;

			date.setDate(element.getBirthDate().getYear(), element.getBirthDate().getMonth(), element.getBirthDate().getDay());

			this->ui.nameLineEdit->setText(QString::fromStdString(element.getName()));
			this->ui.breedLineEdit->setText(QString::fromStdString(element.getBreed()));
			this->ui.vaccinationsLineEdit->setText(QString::fromStdString(std::to_string(element.getVaccinationsCount())));
			this->ui.photographLineEdit->setText(QString::fromStdString(element.getPhotograph()));
			this->ui.dateCalendarWidget->dateTextFormat(date);
		}

		});

}

int AdoptAPetGUI::getElementIndex()
{
	QModelIndexList selectedIndexes = this->ui.elementsListWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0) {
		this->ui.nameLineEdit->clear();
		this->ui.breedLineEdit->clear();
		this->ui.dateCalendarWidget->showToday();
		this->ui.vaccinationsLineEdit->clear();
		this->ui.photographLineEdit->clear();

		return -1;
	}
	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

void AdoptAPetGUI::addElement()
{

	if (this->service.getRunMode() == "B") {
		QMessageBox::critical(this, "Error", "Invalid running mode");
		return;
	}

	std::string name, breed, photo;
	int vaccinations;
	BirthDate date;
	
	name = this->ui.nameLineEdit->text().toStdString();
	breed = this->ui.breedLineEdit->text().toStdString();
	photo = this->ui.photographLineEdit->text().toStdString();
	vaccinations = this->ui.vaccinationsLineEdit->text().toInt();

	QDate qDate;
	qDate = this->ui.dateCalendarWidget->selectedDate();

	date.setDay(qDate.day());
	date.setMonth(qDate.month());
	date.setYear(qDate.year());

	TElem element{ name,breed,date,vaccinations,photo };

	try {
		this->service.addElement(element);
	}
	catch (ExceptionAddAlreadyExisting error) {
		QMessageBox::critical(this, "Error", error.what());
	}
	catch (ExceptionNoElements error) {
		QMessageBox::critical(this, "Error", error.what());
	}
	catch (ExceptionNoFile error) {
		QMessageBox::critical(this, "Error", error.what());
	}
	catch (ExceptionValidationError error) {
		QMessageBox::critical(this, "Error", error.what());
	}

	this->populateList();

	int lastElement = this->service.getAll().size() - 1;
	this->ui.elementsListWidget->setCurrentRow(lastElement);

}

void AdoptAPetGUI::deleteElement()
{

	if (this->service.getRunMode() == "B") {
		QMessageBox::critical(this, "Error", "Invalid running mode");
		return;
	}

	int selectedIndex = this->getElementIndex();
	if (selectedIndex < 0) {
		QMessageBox::critical(this, "Error", "No element selected!");
		return;
	}


	TElem element=this->service.getAll()[selectedIndex];
	
	try{
		this->service.removeElement(element.getName());
	}
	catch (ExceptionDeleteDoesNotExist error) {
		QMessageBox::critical(this, "Error", error.what());
	}
	catch (ExceptionNoElements error) {
		QMessageBox::critical(this, "Error", error.what());
	}
	catch (ExceptionNoFile error) {
		QMessageBox::critical(this, "Error", error.what());
	}
	this->populateList();

}

void AdoptAPetGUI::updateElement()
{

	if (this->service.getRunMode() == "B") {
		QMessageBox::critical(this, "Error", "Invalid running mode");
		return;
	}

	std::string name, breed, photo;
	int vaccinations;
	BirthDate date;

	name = this->ui.nameLineEdit->text().toStdString();
	breed = this->ui.breedLineEdit->text().toStdString();
	photo = this->ui.photographLineEdit->text().toStdString();
	vaccinations = this->ui.vaccinationsLineEdit->text().toInt();

	QDate qDate;
	qDate = this->ui.dateCalendarWidget->selectedDate();

	date.setDay(qDate.day());
	date.setMonth(qDate.month());
	date.setYear(qDate.year());

	TElem element{ name,breed,date,vaccinations,photo };

	try {
		this->service.updateElement(element);
	}
	catch (ExceptionUpdateDoesNotExist error) {
		QMessageBox::critical(this,"Error", error.what());
	}
	catch (ExceptionNoElements error) {
		QMessageBox::critical(this, "Error", error.what());
	}
	catch (ExceptionNoFile error) {
		QMessageBox::critical(this, "Error", error.what());
	}
	catch (ExceptionValidationError error) {
		QMessageBox::critical(this, "Error", error.what());
	}
	this->populateList();
}

void AdoptAPetGUI::undo()
{
	if (this->service.getRunMode() == "B") {
		QMessageBox::critical(this, "Error", "Invalid running mode");
		return;
	}

	try {
		this->service.undo();
	}
	catch (ExceptionNoUndo error) {
		QMessageBox::critical(this, "Error", error.what());
	}
	this->populateList();
}

void AdoptAPetGUI::redo()
{
	if (this->service.getRunMode() == "B") {
		QMessageBox::critical(this, "Error", "Invalid running mode");
		return;
	}

	try{
		this->service.redo();
	}
	catch (ExceptionNoRedo error) {
		QMessageBox::critical(this, "Error", error.what());
	}
	this->populateList();
}

void AdoptAPetGUI::nextElement()
{
	if (this->service.getRunMode() == "A") {
		QMessageBox::critical(this, "Error", "Invalid running mode");
		return;
	}

	this->ui.elementsListWidget->clear();

	TElem element = this->service.nextDog();

	this->populateListSingle();
}

void AdoptAPetGUI::saveElement()
{
	if (this->service.getRunMode() == "A") {
		QMessageBox::critical(this, "Error", "Invalid running mode");
		return;
	}
	if (this->service.getCurrentMyListMode() == "") {
		QMessageBox::critical(this, "Error", "Invalid my list file location");
		return;
	}

	this->service.saveDog(this->ui.nameLineEdit->text().toStdString());

}

void AdoptAPetGUI::setMyListLocation()
{
	std::string myListPath = this->ui.myListLocationLineEdit->text().toStdString();
	this->service.changeMyListLocation(myListPath);	
}

void AdoptAPetGUI::setFileLocation()
{
	std::string filePath = this->ui.fileLocationLineEdit->text().toStdString();
	this->service.changeFileLocation(filePath);
	this->populateList();
}

void AdoptAPetGUI::myList()
{
	this->service.getAdoptionList();
}

void AdoptAPetGUI::openMyListWindow()
{
	std::vector<TElem> elements;
	try {
		elements = this->service.getAdoptionVector();
	}
	catch (ExceptionNoElements error) {
		QMessageBox::critical(this, "Error", error.what());
	}

	MyListTableModel* model = new MyListTableModel{elements};

	myListWindow *window=new myListWindow{ model };
	window->show();
}

void AdoptAPetGUI::switchMode()
{
	std::string currentMode = this->ui.modeLabel->text().toStdString();


	if (currentMode == "Mode: A") {
		this->ui.modeLabel->setText(QString::fromStdString("Mode: B"));
		this->service.setRunMode("B");
		this->populateListSingle();
	}
	else {
		this->ui.modeLabel->setText(QString::fromStdString("Mode: A"));
		this->service.setRunMode("A");
		this->populateList();
	}

}
