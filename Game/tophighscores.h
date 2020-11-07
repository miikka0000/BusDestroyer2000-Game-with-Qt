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

const QString textFilePath = "top10scores.txt";

class topHighScores : public QObject
{
    Q_OBJECT
public:
    explicit topHighScores(QObject *parent = nullptr);

    void readFile(QString filename = textFilePath);
    void writeFile(QString filename = textFilePath);

    std::map<QString, int> scores;
    QString strScores;

    void sortAndDisplay(std::map<QString, int> M);
    int getDuration();
private:
    std::shared_ptr<QSettings> _playerSettings = std::make_shared<QSettings>();

signals:

};


#endif // TOPHIGHSCORES_H
