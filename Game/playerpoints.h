#ifndef PLAYERPOINTS_H
#define PLAYERPOINTS_H

#include <QGraphicsTextItem>

class playerPoints: public QGraphicsTextItem{

public:
    playerPoints(QGraphicsItem * parent=0);
    void increasePoints();
    int getPlayerScore();

private:
    int _playerScore;
};

#endif // PLAYERPOINTS_H
