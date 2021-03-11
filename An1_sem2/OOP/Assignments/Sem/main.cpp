#include "Sem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sem w;
    w.show();
    return a.exec();
}
