#include "MyListTableModel.h"

int MyListTableModel::rowCount(const QModelIndex& parent) const
{
	return this->elements.size();
}

int MyListTableModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant MyListTableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	TElem element=this->elements[row];

	if (role == Qt::DisplayRole) {
		switch (column)
		{
		case 0:
			return QString::fromStdString(element.getName());
		case 1:
			return QString::fromStdString(element.getBreed());
		case 2:
			return QString::fromStdString(element.getBirthDate().getString());
		case 3:
			return QString::number(element.getVaccinationsCount());
		case 4:
			return QString::fromStdString(element.getPhotograph());
		default:
			break;
		}
	}


	return QVariant();
}

QVariant MyListTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			switch (section)
			{
			case 0:
				return QString("Name");
			case 1:
				return QString("Breed");
			case 2:
				return QString("Birth Date");
			case 3:
				return QString("Vaccinations count");
			case 4:
				return QString("Photograph");
			default:
				break;
			}
		}
	}

	return QVariant();
}
