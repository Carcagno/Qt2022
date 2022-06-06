#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget window;
    window.setFixedSize(200, 100);


    QPushButton button2{"other", &window};
    button2.setGeometry(60, 30, 80, 30);

    window.show();

    return a.exec();
}
