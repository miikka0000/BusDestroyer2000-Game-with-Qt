#include "bonusitem.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

bonusItem::bonusItem(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    int randXCoord = rand() % currentWidth;

    setPos(randXCoord, 0);
    setPixmap(_gemPic);

    _bonusTimer = new QTimer(this);
    connect(_bonusTimer, &QTimer::timeout, this, &bonusItem::move);
    _bonusTimer->start(_bonusInterval);
    setPos(mapToParent(pos().x(), pos().y()));
}

void bonusItem::move(){

    setPos(this->x(), this->y() + 5);

    if (pos().y() > currentHeight){

        scene()->removeItem(this);
        delete this;
    }
}
