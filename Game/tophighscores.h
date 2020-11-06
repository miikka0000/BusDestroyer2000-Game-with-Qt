#ifndef TOPHIGHSCORES_H
#define TOPHIGHSCORES_H

#include <QObject>
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>

const QString textFilePath = "top10scores.txt";

class topHighScores : public QObject
{
    Q_OBJECT
public:
    explicit topHighScores(QObject *parent = nullptr);

    void readFile(QString filename = textFilePath);
    void writeFile(QString filename = textFilePath);

    QString scores;

signals:

};

#endif // TOPHIGHSCORES_H
