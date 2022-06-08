#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QProgressBar *m_bar;
    QSlider *m_slider;
    m_bar = new QProgressBar{&w};
    m_bar->setRange(0, 100);
    m_bar->setValue(50);
    m_bar->setGeometry(0, 290, 800, 20);

    m_slider = new QSlider{&w};
    m_slider->setOrientation(Qt::Horizontal);
    m_slider->setRange(0, 100);
    m_slider->setValue(50);
    m_slider->setGeometry(0, 550, 800, 50);

    w.show();

    QObject::connect
        (m_slider
        , SIGNAL (valueChanged(int))
        , m_bar
        , SLOT (setValue(int)));

    return a.exec();
}
