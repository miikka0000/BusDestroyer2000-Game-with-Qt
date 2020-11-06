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
        int line_count = 0;
        while(!stream.atEnd() && line_count <= 10)
        {

            QString line = stream.readLine();
            if (line_count > 0) {
                scores += QString::number(line_count) + ") " + line + "\n";
            }
            line_count++;
        }
        file.close();
        qDebug() << "Reading finished";
    };

}


void topHighScores::writeFile(QString filename)
{
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {

        QTextStream stream(&file);

        stream <<  playerAliasName << ": "<< smartStats->givePoints() << "\n";

        file.close();
        qDebug() << "Writing finished";
    }
}
