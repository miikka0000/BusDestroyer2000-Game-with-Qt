#ifndef BONUSITEM_H
#define BONUSITEM_H

#include "gamewindow.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>

class BonusItem: public QObject,public QGraphicsPixmapItem{

    Q_OBJECT

public:
    BonusItem(QGraphicsItem * parent=0);

    GameWindow *game;
    QPixmap gemPic = QPixmap(":/images/bonusGem_30x15.png");





public slots:
    void move();


private:
    QTimer * _bonusTimer;
    int _bonusInterval = 50;
};


#endif // BONUSITEM_H
