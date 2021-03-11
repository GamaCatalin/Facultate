#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Sem.h"

class Sem : public QMainWindow
{
    Q_OBJECT

public:
    Sem(QWidget *parent = Q_NULLPTR);

private:
    Ui::SemClass ui;
};
