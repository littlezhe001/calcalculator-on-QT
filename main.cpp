#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Dialog d;
    w.setFixedSize(500,650);
    d.setFixedSize(450,450);
    w.show();
    d.show();
    return a.exec();
}
