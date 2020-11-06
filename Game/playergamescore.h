#ifndef PLAYERGAMESCORE_H
#define PLAYERGAMESCORE_H

#include <QObject>

class playerGameScore : public QObject
{
    Q_OBJECT
public:
    explicit playerGameScore(QObject *parent = nullptr);
    ~playerGameScore();

    void increasePoints() {playerScore += 10;};
    int getPlayerScore() {return playerScore;};

    int playerScore = 0;


};

#endif // PLAYERGAMESCORE_H
