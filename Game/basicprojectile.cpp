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
extern std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*> smartActors;

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

void basicProjectile::removeShootedActors()
{
    std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*>::iterator it;

    for(it = smartActors.begin(); it != smartActors.end(); ++it){

        int xCoord = it->first->giveLocation().giveX();
        int yCoord= it->first->giveLocation().giveY();

        if(isClose(it->first->giveLocation(), 10, x(), y())){
        if(this->scene() != NULL && it->second->scene() != NULL){
            smartPlayerScore->increasePoints();
            scene()->removeItem(it->second);
            smartActors.erase(it);
        }
        }


    }
}

// isClose function  is a courtesy from the CourseSide (core/location)
bool basicProjectile::isClose(const Interface::Location &loc, int limit, int xCoord, int yCoord)
{

    int dx = loc.giveX() - xCoord;
    int dy = loc.giveY() - yCoord;

    return dx*dx + dy*dy <= limit*limit;

}



void basicProjectile::move()
{

    QList<QGraphicsItem *> collidingObjects = collidingItems();


    for (int i = 0, j = collidingObjects.size(); i < j; ++i){
        if (typeid(*(collidingObjects[i])) == typeid(BonusItem)){

            smartPlayerScore->increasePoints();
            scene()->removeItem(collidingObjects[i]);
            scene()->removeItem(this);
            delete collidingObjects[i];
            delete this;

            return;
        }
    }


    removeShootedActors();
    setPos(x(), y() - _projectileVelocity);
    if(pos().y() + _projectileHeight < 0){
        scene()->removeItem(this);
        delete this;
    }


}


