#include "basicprojectile.h"
#include "gamesetupdata.h"


#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsItem>

basicProjectile::basicProjectile(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    setProjectilePicture();
    //setPixmap(_fireballPic);
    //setDimensions();

    _projectileTimer = new QTimer(this);
    connect(_projectileTimer, &QTimer::timeout, this, &basicProjectile::move);
    _projectileTimer->start(_fireRate);

    //qDebug() << "projectile height:"<<this->_projectileHeight;
    //qDebug() << "proejctile width:"<<this->_projectileWidth;

}

basicProjectile::~basicProjectile()
{

}

void basicProjectile::setDimensions()
{

    if(setUp::gameSetUpData().fireballChosen){
        _projectileHeight = _fireballPic.height();
        _projectileWidth = _fireballPic.width();

    } else if(setUp::gameSetUpData().missileChosen){
        _projectileHeight = _missilePic.height();
        _projectileWidth = _missilePic.width();

    } else if(setUp::gameSetUpData().laserChosen){
        _projectileHeight = _laserPic.height();
        _projectileWidth = _laserPic.width();
    }

}

void basicProjectile::setProjectilePicture()
{

    if(setUp::gameSetUpData().fireballChosen){
        setPixmap(_fireballPic);

    } else if(setUp::gameSetUpData().missileChosen){
        setPixmap(_missilePic);

    } else if(setUp::gameSetUpData().laserChosen){
        setPixmap(_laserPic);
    }
    //qDebug() << _playerData->fireballChosen;
    setTransformOriginPoint(5, 10);
    setRotation(-90);   
    setDimensions();
}

void basicProjectile::move()
{
    setPos(x(), y() - _projectileVelocity);
    if(pos().y() + _projectileHeight < 0){
        scene()->removeItem(this);
        delete this;
    }
}


