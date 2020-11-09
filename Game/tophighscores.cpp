#include "tophighscores.h"
#include "gamestatistics.h"

#include <QDebug>

extern std::shared_ptr<gameStatistics> smartStats;
extern QString playerAliasName;
topHighScores::topHighScores(QObject *parent) : QObject(parent)
{

}

void topHighScores::readFile(QString filename)
{
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        while(!stream.atEnd())
        {
            QString line = stream.readLine();
            QStringList data = line.split(": ");
            QString name = data.at(0);
            int points = data.at(1).toInt();
            scores.insert ( std::pair<QString,int>(name, points) );
        }
        file.close();
        qDebug() << "Reading finished";
    };
    sortAndDisplay(scores);
}

void topHighScores::sortAndDisplay(std::map<QString, int> mapToBeSorted)
{
    std::multimap<int, QString> sortedMap;

    for (auto it : mapToBeSorted) {
        sortedMap.insert({ it.second, it.first });
    }
    int i = 1;
    for (auto it = sortedMap.rbegin(); it != sortedMap.rend(); ++it) {
        if (i <= 10) {
            scoreStream += QString::number(i) + ") " + it->second + ": " + QString::number(it->first) + "\n";
        }
        ++i;
    }
}

int topHighScores::getDuration() {
    int gameDuration = 2;
    int timeOpt = _playerSettings->value("time setting").toInt();
    if(timeOpt == settingsDialog::gameTime1) {
        gameDuration = 1; //min
    }
    else if(timeOpt == settingsDialog::gameTime3) {
        gameDuration = 3;
    }
    return gameDuration;
}

void topHighScores::writeFile(QString filename)
{
    QFile file(filename);

    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        int points = smartStats->givePoints()/getDuration();
        QTextStream stream(&file);

        if (playerAliasName != "") {
            stream <<  playerAliasName << ": "<< points << "\n";
        }

        file.close();
        qDebug() << "Writing finished";
    }
}
