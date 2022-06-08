#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_button {QPushButton{"Hello Button", this}}
{
    ui->setupUi(this);
    setFixedSize(200, 100);

    m_button.setGeometry(20, 20, 80, 30);
}

MainWindow::~MainWindow()
{
    delete ui;
}
