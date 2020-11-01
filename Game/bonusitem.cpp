#include "bonusitem.h"


#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>



BonusItem::BonusItem(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    int randXCoord = rand() % currentWidth;

    setPos(randXCoord, 0);
    setPixmap(gemPic);

    _bonusTimer = new QTimer(this);
    connect(_bonusTimer, &QTimer::timeout, this, &BonusItem::move);
    _bonusTimer->start(_bonusInterval);
    setPos(mapToParent(pos().x(), pos().y()));
}

void BonusItem::move(){

    setPos(this->x(), this->y() + 5);

    if (pos().y() > currentHeight){

        scene()->removeItem(this);
        delete this;
    }
}
