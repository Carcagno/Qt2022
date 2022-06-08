#include "textfinder.h"
#include "ui_textfinder.h"

#include <QFile>
#include <QTextStream>

TextFinder::TextFinder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    m_cursor = ui->textEdit->textCursor();

    loadTextFile();

}

TextFinder::~TextFinder()
{
    delete ui;
}


void TextFinder::loadTextFile()
{
    QFile inputFile{":/input.txt"};
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(line);
    m_cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}

void TextFinder::on_findButton_clicked()
{
    QString searchString = ui->lineEdit->text();
    if (!(ui->textEdit->find(searchString, QTextDocument::FindWholeWords)))
    {
        m_cursor.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, 1);
        m_cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, 1);

        ui->textEdit->setTextCursor(m_cursor);
        ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
    }
}

