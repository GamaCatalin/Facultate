#include "GUI.h"

GUI::GUI(Service service)
{
	this->service = service;
	this->initializeGUI();
	this->populateList();
	this->connectFields();
}

void GUI::initializeGUI()
{
	this->elements = new QListWidget{};

	this->nameLineEdit = new QLineEdit{};
	this->breedLineEdit = new QLineEdit{};
	this->dateLineEdit = new QLineEdit{};
	this->vaccinationsLineEdit = new QLineEdit{};
	this->photoLineEdit = new QLineEdit{};

	this->dateCalendar = new QCalendarWidget{};

	this->addButton = new QPushButton{"Add"};
	this->deleteButton = new QPushButton{"Delete"};
	this->updateButton = new QPushButton{"Update"};

	QVBoxLayout* mainLayout = new QVBoxLayout{ this };

	mainLayout->addWidget(this->elements);

	QFormLayout* detailsLayout = new QFormLayout{};

	detailsLayout->addRow("Name", this->nameLineEdit);
	detailsLayout->addRow("Breed", this->breedLineEdit);
	detailsLayout->addRow("Birth Date", this->dateCalendar);
	detailsLayout->addRow("Vaccinations count", this->vaccinationsLineEdit);
	detailsLayout->addRow("Photograph", this->photoLineEdit);

	mainLayout->addLayout(detailsLayout);

	QGridLayout* buttonsLayout = new QGridLayout{};

	buttonsLayout->addWidget(this->addButton, 0, 0);
	buttonsLayout->addWidget(this->deleteButton, 0, 1);
	buttonsLayout->addWidget(this->updateButton, 1, 0);

	mainLayout->addLayout(buttonsLayout);
}

void GUI::populateList()
{
	this->elements->clear();

	std::vector<TElem> elements;
	elements = this->service.getAll();

	for (auto& element : elements) {
		this->elements->addItem(QString::fromStdString(element.getPrintable()));
	}
}

void GUI::connectFields()
{
	QObject::connect(this->elements, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = this->getElementIndex();

		if (selectedIndex < 0)
			return;

		TElem element = this->service.getAll()[selectedIndex];

		QDate date;

		date.setDate(element.getBirthDate().getYear(), element.getBirthDate().getMonth(), element.getBirthDate().getDay());

		this->nameLineEdit->setText(QString::fromStdString(element.getName()));
		this->breedLineEdit->setText(QString::fromStdString(element.getBreed()));
		this->vaccinationsLineEdit->setText(QString::fromStdString(std::to_string(element.getVaccinationsCount())));
		this->photoLineEdit->setText(QString::fromStdString(element.getPhotograph()));
		this->dateCalendar->selectedDate() = date;

		});
}

int GUI::getElementIndex()
{
	QModelIndexList selectedIndexes = this->elements->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0) {
		this->nameLineEdit->clear();
		this->breedLineEdit->clear();
		this->dateCalendar->showToday();
		this->vaccinationsLineEdit->clear();
		this->photoLineEdit->clear();

		return -1;
	}
	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

void GUI::writeFields()
{
	int selectedIndex = this->getElementIndex();

	if (selectedIndex < 0)
		return;

	TElem element = this->service.getAll()[selectedIndex];

	QDate date;

	date.setDate(element.getBirthDate().getYear(), element.getBirthDate().getMonth(), element.getBirthDate().getDay());

	this->nameLineEdit->setText(QString::fromStdString(element.getName()));
	this->breedLineEdit->setText(QString::fromStdString(element.getBreed()));
	this->vaccinationsLineEdit->setText(QString::fromStdString(std::to_string(element.getVaccinationsCount())));
	this->photoLineEdit->setText(QString::fromStdString(element.getPhotograph()));
	this->dateCalendar->selectedDate() = date;

}
