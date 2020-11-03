#include "basicprojectile.h"
#include "playergamescore.h"
#include "playerhealth.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsItem>
#include <QList>
#include <memory>

extern std::shared_ptr<playerGameScore> smartPlayerScore;
extern std::shared_ptr<playerHealth> smartPlayerHealth;

basicProjectile::basicProjectile(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setProjectilePicture();
    _projectileTimer = new QTimer(this);
    connect(_projectileTimer, &QTimer::timeout, this, &basicProjectile::move);
    _projectileTimer->start(_fireRate);
    setPos(mapToParent(pos().x(), pos().y()));

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

}

void basicProjectile::setProjectilePicture()
{

    int chosenProjectile = _playerSettings->value("projectile type setting").toInt();
    //qDebug()<< chosenProjectile;

    if(chosenProjectile == MainMenuDialog::fireballOption){
        //qDebug()<<"you chose spaceship";
        fireballChosen = true;
        setPixmap(_fireballPic);

    } else if(chosenProjectile == MainMenuDialog::missileOption){
        //qDebug()<<"you chose tank";
        missileChosen = true;
        setPixmap(_missilePic);

    } else if(chosenProjectile == MainMenuDialog::laserOption){
        //qDebug()<<"you chose ufo";
        laserChosen = true;
        setPixmap(_laserPic);
    }
    setTransformOriginPoint(5, 10);
    setRotation(-90);
    setDimensions();
}


void basicProjectile::move()
{

    QList<QGraphicsItem *> collidingObjects = collidingItems();
    //qDebug()<<"colliding items list: "<<collidingObjects;

    for (int i = 0, j = collidingObjects.size(); i < j; ++i){
        if (typeid(*(collidingObjects[i])) == typeid(BonusItem) ||

                typeid(*(collidingObjects[i])) == typeid(CourseSide::Nysse)

                || typeid(*(collidingObjects[i])) == typeid(CourseSide::Passenger)){



            smartPlayerScore->increasePoints();
            scene()->removeItem(collidingObjects[i]);
            scene()->removeItem(this);
            delete collidingObjects[i];
            delete this;

            return;
       }
    }


    setPos(x(), y() - _projectileVelocity);
    if(pos().y() + _projectileHeight < 0){
        scene()->removeItem(this);
        delete this;
    }

}


