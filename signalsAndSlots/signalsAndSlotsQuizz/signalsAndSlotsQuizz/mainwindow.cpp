#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);

    m_buttonQuit = new QPushButton{"Quit", this};
    m_buttonQuit->setGeometry(580, 260, 40, 80);
    connect
            (m_buttonQuit
             , SIGNAL(clicked(bool))
             , QApplication::instance()
             , SLOT(quit()));


    m_buttonInfo = new QPushButton{"Info", this};
    m_buttonInfo->setGeometry(180, 260, 40, 80);
    connect
            (m_buttonInfo
             , SIGNAL(clicked(bool))
             , QApplication::instance()
             , SLOT(aboutQt()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

