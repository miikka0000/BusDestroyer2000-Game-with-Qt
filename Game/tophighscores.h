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

// default file where the player name and score are saved in this kind of format:
// playerName:scaledPoints
const QString textFilePath = "top10highscores.txt";

class topHighScores : public QObject
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor of the class. As a default, parent is set to a nullpointer to QGraphicsItem.
      * @post basicProjectile is at initialization state.
      */
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
