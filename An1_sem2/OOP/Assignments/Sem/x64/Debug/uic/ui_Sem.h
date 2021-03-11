/********************************************************************************
** Form generated from reading UI file 'Sem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEM_H
#define UI_SEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SemClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QListView *messagesListView;
    QGridLayout *gridLayout;
    QLineEdit *textLineEdit;
    QPushButton *sendButtonWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SemClass)
    {
        if (SemClass->objectName().isEmpty())
            SemClass->setObjectName(QString::fromUtf8("SemClass"));
        SemClass->resize(543, 890);
        centralWidget = new QWidget(SemClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        messagesListView = new QListView(centralWidget);
        messagesListView->setObjectName(QString::fromUtf8("messagesListView"));
        QFont font;
        font.setPointSize(12);
        messagesListView->setFont(font);

        verticalLayout->addWidget(messagesListView);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textLineEdit = new QLineEdit(centralWidget);
        textLineEdit->setObjectName(QString::fromUtf8("textLineEdit"));
        textLineEdit->setFont(font);
        textLineEdit->setClearButtonEnabled(false);

        gridLayout->addWidget(textLineEdit, 0, 0, 1, 1);

        sendButtonWidget = new QPushButton(centralWidget);
        sendButtonWidget->setObjectName(QString::fromUtf8("sendButtonWidget"));
        sendButtonWidget->setFont(font);

        gridLayout->addWidget(sendButtonWidget, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        SemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SemClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 543, 21));
        SemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SemClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SemClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SemClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SemClass->setStatusBar(statusBar);

        retranslateUi(SemClass);

        QMetaObject::connectSlotsByName(SemClass);
    } // setupUi

    void retranslateUi(QMainWindow *SemClass)
    {
        SemClass->setWindowTitle(QCoreApplication::translate("SemClass", "Sem", nullptr));
        sendButtonWidget->setText(QCoreApplication::translate("SemClass", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SemClass: public Ui_SemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEM_H
