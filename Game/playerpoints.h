#ifndef PLAYERPOINTS_H
#define PLAYERPOINTS_H

#include <QGraphicsTextItem>

class playerPoints: public QGraphicsTextItem{

public:
    playerPoints(QGraphicsItem * parent=0);
    void increasePoints();

    int playerScore;

private:

};

#endif // PLAYERPOINTS_H
