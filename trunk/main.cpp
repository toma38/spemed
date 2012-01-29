#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Omed");
    QCoreApplication::setOrganizationDomain("http://www.omed-soft.com");
    QCoreApplication::setApplicationName("Spemed");
    QCoreApplication::setApplicationName("Spemed");
    QCoreApplication::setApplicationVersion("0.2");


    MainWindow w;
    w.show();
    
    return a.exec();
}
