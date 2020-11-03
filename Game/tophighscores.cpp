#include "tophighscores.h"

#include <QDebug>

topHighScores::topHighScores(QObject *parent) : QObject(parent)
{

}

void topHighScores::readFile(QString filename)
{
    QFile textFile(filename);

    if(!textFile.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Error reading the file";
        return;
    }
    QTextStream in(&textFile);
    QString scores = in.readAll();
    qDebug() << scores;


    textFile.close();
}

void topHighScores::writeFile(QString filename)
{
    QFile textFile(filename);

    if(!textFile.open(QFile::WriteOnly | QFile::Text)){
        qDebug() << "Error opening the file";
        return;
    }
    QTextStream out(&textFile);
    out << "Hello World";

    textFile.close();
}
