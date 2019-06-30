#include "gui/mainwindow.h"
#include <QApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // qDebug() << "Max count: " << QThreadPool::globalInstance()->maxThreadCount();
    MainWindow w;
    w.show();

    return a.exec();
}
