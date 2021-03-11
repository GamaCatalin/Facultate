#pragma once
#include <qabstractitemmodel.h>
#include <vector>
#include "Pet.h"
typedef Pet TElem;

class MyListTableModel : public QAbstractTableModel
{
private:
	std::vector<TElem> elements;
public:
	MyListTableModel(std::vector<TElem> elements) : elements{ elements } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};

