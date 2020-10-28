#include "basicprojectile.h"


#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsItem>

basicProjectile::basicProjectile(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/fireball_16x16.png"));
    setTransformOriginPoint(5, 10);
    setRotation(-90);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &basicProjectile::move);
    timer->start(50);

    this->setDimensions();
    qDebug() << "projectile height:"<<this->projectileHeight_;
    qDebug() << "proejctile width:"<<this->projectileWidth_;

}

basicProjectile::~basicProjectile()
{

}

void basicProjectile::setDimensions()
{
    QImage *fireball= new QImage(":/images/fireball.png");
    projectileHeight_ = fireball->height();
    projectileWidth_ = fireball->width();
    //qDebug() << "fireball height: "<<bulletHeight_;
    //qDebug() << "fireball width: "<<bulletWidth_;
    delete fireball;
}



void basicProjectile::move()
{

    setPos(x(), y() - projectileVelocity_);

    if(pos().y() + projectileHeight_ < 0){
        scene()->removeItem(this);
        delete this;
    }
}


