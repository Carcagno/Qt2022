#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set the size and location of the window & button
    setFixedSize(800, 600);

    m_button = new QPushButton("QUit", this);
    m_button->setGeometry(350, 250, 100, 100);

    //Do the signal connection using existing slot of QApplication
    // & signal of QPushButton
    connect
        (m_button //signal sender
        , SIGNAL (clicked()) // signal sent
        , QApplication::instance() //signal receiver
        , SLOT (quit())); // function to call when signal received
}

MainWindow::~MainWindow()
{
    delete ui;
}

