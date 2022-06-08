#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QWidget>
#include <QTextCursor>

QT_BEGIN_NAMESPACE
namespace Ui { class TextFinder; }
QT_END_NAMESPACE

class TextFinder : public QWidget
{
    Q_OBJECT

public:
    TextFinder(QWidget *parent = nullptr);
    ~TextFinder();

private slots:
    void on_findButton_clicked();

private:
    Ui::TextFinder *ui;
    QTextCursor m_cursor;

    void loadTextFile();

};
#endif // TEXTFINDER_H
