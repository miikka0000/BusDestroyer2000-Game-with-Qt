#ifndef TOPHIGHSCORES_H
#define TOPHIGHSCORES_H

#include "settingsdialog.h"

#include <QObject>
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QSettings>
#include <memory>

const QString textFilePath = "top10highscores.txt";

class topHighScores : public QObject
{
    Q_OBJECT
public:
    explicit topHighScores(QObject *parent = nullptr);

    void readFile(QString filename = textFilePath);
    void writeFile(QString filename = textFilePath);
    void sortAndDisplay(std::map<QString, int> mapToBeSorted);
    int getDuration();

    std::map<QString, int> scores;
    QString scoreStream;

private:
    std::shared_ptr<QSettings> _playerSettings = std::make_shared<QSettings>();

};


#endif // TOPHIGHSCORES_H
