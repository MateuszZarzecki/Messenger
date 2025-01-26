#include "mainwindow.h"

#include <QApplication>

/*
 Splash screen - QSplashScreen
 multiple windows
hidding objects
*/


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowIcon(QIcon(":/images/icon.png"));

    w.show();
    return a.exec();
}
