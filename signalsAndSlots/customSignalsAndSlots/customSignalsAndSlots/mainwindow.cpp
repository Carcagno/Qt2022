#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800, 600);

    m_button = new QPushButton("Button", this);
    m_button->setGeometry(375, 275, 50, 50);
    m_button->setCheckable(true);

    connect
            (m_button
             , SIGNAL (clicked(bool))
             , this
             , SLOT (slotButtonClicked(bool)));

    m_counter = 0;

    connect
            (this
             , SIGNAL (counterReached())
             , QApplication::instance()
             , SLOT (quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotButtonClicked(bool checked)
{
    if (checked)
        m_button->setText("Checked");
    else
        m_button->setText("Unchecked");

    ++m_counter;
    if (m_counter == 10)
        emit counterReached();
}
