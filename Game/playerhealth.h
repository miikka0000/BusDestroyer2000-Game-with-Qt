#ifndef PLAYERHEALTH_H
#define PLAYERHEALTH_H

#include <QObject>

#include <QGraphicsTextItem>

class playerHealth: public QGraphicsTextItem{

public:
    playerHealth(QGraphicsItem * parent=0);
    void decreaseHealth();
    int increaseHealth();

private:
    int _healthPoints;
};

#endif // PLAYERHEALTH_H
