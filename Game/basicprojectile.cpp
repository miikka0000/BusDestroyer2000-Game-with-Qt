#include "basicprojectile.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsItem>
#include <QList>
#include <memory>

extern std::shared_ptr<gameStatistics> smartStats;
extern std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*> smartActors;

basicProjectile::basicProjectile(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
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
    if(_fireballChosen){
        _projectileHeight = _fireballPic.height();
        _projectileWidth = _fireballPic.width();
    } else if(_missileChosen){
        _projectileHeight = _missilePic.height();
        _projectileWidth = _missilePic.width();
    } else if(_laserChosen){
        _projectileHeight = _laserPic.height();
        _projectileWidth = _laserPic.width();
    }
}

void basicProjectile::setProjectilePicture()
{
    int chosenProjectile = _playerSettings->value("projectile type setting").toInt();

    if(chosenProjectile == MainMenuDialog::fireballOption){
        _fireballChosen = true;
        setPixmap(_fireballPic);

    } else if(chosenProjectile == MainMenuDialog::missileOption){
        _missileChosen = true;
        setPixmap(_missilePic);

    } else if(chosenProjectile == MainMenuDialog::laserOption){
        _laserChosen = true;
        setPixmap(_laserPic);
    }
    setTransformOriginPoint(5, 10);
    setRotation(-90);
    setDimensions();
}

bool basicProjectile::removeShootedActors()
{
    std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*>::iterator it;

    for(it = smartActors.begin(); it != smartActors.end(); ++it){

        if(isClose(it->first->giveLocation(), 10, x(), y())){
            if(this->scene() != NULL && it->second->scene() != NULL){

                smartStats->addPoints();
                if(typeid (*(it->first)) == typeid (CourseSide::Nysse)){
                    smartStats->nysseRemoved();
                    smartStats->nysseLeft();
                } else if(typeid (*(it->first)) == typeid (CourseSide::Passenger)){
                    smartStats->passengerDied(1);
                    smartStats->passengerLeft();
                }
                if(!it->first->isRemoved() && it->second != NULL){

                    scene()->removeItem(it->second);

                    smartActors.erase(it);
                }
                return true;
            }
        }
    }
    return false;
}

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
        if (typeid(*(collidingObjects[i])) == typeid(bonusItem)){
            smartStats->addPoints();
            smartStats->addCollectedDiamond();
            scene()->removeItem(collidingObjects[i]);
            scene()->removeItem(this);
            delete collidingObjects[i];
            delete this;
            return;
        }
    }
    bool isRemoved = removeShootedActors();
    if(!isRemoved){
        setPos(x(), y() - _projectileVelocity);
        if(pos().y() + _projectileHeight < 0){
            scene()->removeItem(this);
            delete this;
        }
    }else if(isRemoved){
        scene()->removeItem(this);
        delete this;
    }
}


