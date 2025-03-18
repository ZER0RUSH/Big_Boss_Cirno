#include "mainwindow.h"
#include <config.h>
#include <QResource>
#include <QApplication>
#include "startmenu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    startmenu menu;

    return a.exec();
}
