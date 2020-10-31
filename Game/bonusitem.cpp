#include "bonusitem.h"
#include "gamewindow.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>



BonusItem::BonusItem(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    // here we generate a random x position
    int random_number = rand() % 700;

    setPos(random_number,0);

    setPixmap(gemPic);

    _bonusTimer = new QTimer(this);
    connect(_bonusTimer, &QTimer::timeout, this, &BonusItem::move);
    _bonusTimer->start(_bonusInterval);
}

void BonusItem::move(){

    setPos(this->x(), this->y() + 5);



    if (pos().y() > 600){


        scene()->removeItem(this);
        delete this;
    }
}
