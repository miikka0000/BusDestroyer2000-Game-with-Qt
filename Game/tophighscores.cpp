#include "tophighscores.h"
#include "playergamescore.h"
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
    sort(scores);
}

void topHighScores::sort(std::map<QString, int> M)
{
    std::multimap<int, QString> MM;

    for (auto it : M) {
        MM.insert({ it.second, it.first });
    }
    int i = 10;
    for (auto it : MM) {
        if (i > 0) {
            strScores += QString::number(i) + ") " + it.second + ": " + QString::number(it.first) + "\n";
        }
        i = i-1;
    }


}


void topHighScores::writeFile(QString filename)
{
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {

        QTextStream stream(&file);

        if (playerAliasName != "") {
            stream <<  playerAliasName << ": "<< smartStats->givePoints() << "\n";
        }

        file.close();
        qDebug() << "Writing finished";
    }
}
