#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    QPushButton button ("Hello world !");
    QFont font("courrier");

    button.setText("Button 1");
    button.setToolTip("Button 1 Tooltip");
    button.setFont(font);

    button.show();

    return app.exec();
}
