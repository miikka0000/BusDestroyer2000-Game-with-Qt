#include "basicprojectile.h"


#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsItem>

basicProjectile::basicProjectile(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //setProjectilePicture();
    setPixmap(_fireballPic);

    setTransformOriginPoint(5, 10);
    setRotation(-90);


    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &basicProjectile::move);
    timer->start(50);

    this->setDimensions();
    qDebug() << "projectile height:"<<this->_projectileHeight;
    qDebug() << "proejctile width:"<<this->_projectileWidth;

}

basicProjectile::~basicProjectile()
{

}

void basicProjectile::setDimensions()
{
    if(fireballChosen){
        _projectileHeight = _fireballPic.height();
        _projectileWidth = _fireballPic.width();

    } else if(missileChosen){
        _projectileHeight = _missilePic.height();
        _projectileWidth = _missilePic.width();

    } else if(laserChosen){
        _projectileHeight = _laserPic.height();
        _projectileWidth = _laserPic.width();
    }

    qDebug() << "projectile height: "<< _projectileHeight;
    qDebug() << "projectile width: "<< _projectileWidth;
}

void basicProjectile::setProjectilePicture()
{
    if(fireballChosen){
        setPixmap(_fireballPic);

    } else if(missileChosen){
        setPixmap(_missilePic);

    } else if(laserChosen){
        setPixmap(_laserPic);
    }
    setTransformOriginPoint(5, 10);
    setRotation(-90);
}

void basicProjectile::move()
{
    setPos(x(), y() - _projectileVelocity);

    if(pos().y() + _projectileHeight < 0){
        scene()->removeItem(this);
        delete this;
    }
}


