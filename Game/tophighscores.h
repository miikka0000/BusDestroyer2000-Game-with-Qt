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
#include <map>

/**
 * @brief
 * All of the classes done by the student team are found in StudentSide namespace.
 */
namespace StudentSide {

// default file where the player name and score are saved in this kind of format:
// playerName:scaledPoints
const QString textFilePath = "top10highscores.txt";

/**
  * @brief Defines a Class which is responsible for saving and reading player name and SCALED points to and from a top10highscores.txt file.
  * The class also implements a top10-highscore feature which gives the player information about all-time best players when the metric is the highest scaled points count.
  */
class topHighScores : public QObject
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor of the class. As a default, parent is set to a nullpointer to QGraphicsItem.
      * @post topHighScores is at initialization state.
      */
    explicit topHighScores(QObject *parent = nullptr);

    /**
     * @brief readFile reads data from a textfile into map.
     * @param Default path to the top10highscores.txt -file where the data is ultimately stored.
     * @pre The textfile exists in the path set.
     * @post Data from textfile (playerName: scaledPoints) has been read into a map. Exception guarantee: nothrow.
     */
    void readFile(QString filename = textFilePath);

    /**
     * @brief writeFile writes data into a textfile (player name and his points scaled according to the chosen game duration).
     * @param Default path to the top10highscores.txt -file where the data is ultimately stored.
     * @pre -
     * @post Data has been written to the textfile (playerName: scaledPoints). Exception guarantee: nothrow.
     */
    void writeFile(QString filename = textFilePath);

    /**
     * @brief sortAndDisplay sorts the players according to their points into a top10 -subset and appends these top10 -players into a QString which is shown to the player later in GameOverDialog's QTextBrowser.
     * @param Unsorted map that contains all-time player data.
     * @pre -
     * @post Map is sorted and its contents are appended into a QString. Exception guarantee: nothrow.
     */
    void sortAndDisplay(std::map<QString, int> mapToBeSorted);

    /**
     * @brief getDuration reads the game duration setting saved before and returns it as an integer which represents game duration in minutes.
     * @pre -
     * @return Chosen game duration as an integer which represents game duration in minutes. If the player has not chosen game durations, it is by default 2 minutes.
     * @post Game duration has been returned. Exception guarantee: nothrow.
     */
    int getDuration();

    std::map<QString, int> scores;
    QString scoreStream;

private:
    std::shared_ptr<QSettings> _playerSettings = std::make_shared<QSettings>();

};
}
#endif // TOPHIGHSCORES_H
