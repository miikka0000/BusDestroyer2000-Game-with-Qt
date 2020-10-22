#include "basicprojectile.h"


#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsItem>

basicProjectile::basicProjectile(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/fireball.png"));
    setTransformOriginPoint(5, 10);
    setRotation(-90);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &basicProjectile::move);
    timer->start(50);



}

basicProjectile::~basicProjectile()
{

}

void basicProjectile::setDimensions()
{
    QImage *fireball= new QImage(":/images/fireball.png");
    bulletHeight_ = fireball->height();
    bulletWidth_ = fireball->width();
    //qDebug() << "fireball height: "<<bulletHeight_;
    //qDebug() << "fireball width: "<<bulletWidth_;
    delete fireball;
}



void basicProjectile::move()
{

    setPos(x(), y() - bulletVelocity_);

    if(pos().y() + bulletHeight_ < 0){
        scene()->removeItem(this);
        delete this;
    }
}


