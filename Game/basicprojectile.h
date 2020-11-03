#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "bonusitem.h"
#include "mainmenudialog.h"
#include "actors/nysse.hh"
#include "actors/passenger.hh"
#include "initgame.h"
#include "core/location.hh"


#include <QGraphicsRectItem>
#include <QPixmap>
#include <QTimer>
#include <QSettings>
#include <memory>
#include <map>

class basicProjectile: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    basicProjectile(QGraphicsItem *parent= 0);
    ~basicProjectile();
    void setDimensions();
    void setProjectilePicture();
    void removeShootedActors();
    // isClose function  is a courtesy from the CourseSide (core/location)
    bool isClose(const Interface::Location &loc, int limit, int xCoord, int yCoord) const;



    bool fireballChosen;
    bool missileChosen;
    bool laserChosen;


    QPixmap _fireballPic = QPixmap(":/images/fireball_16x16.png");
    QPixmap _missilePic = QPixmap(":/images/missile_23x10.png");
    QPixmap _laserPic = QPixmap(":/images/laser_32x32.png");


private:

    int _projectileVelocity = 20;
    int _projectileHeight;
    int _projectileWidth;

    QTimer *_projectileTimer;
    int _fireRate = 50;
    std::shared_ptr<QSettings> _playerSettings = std::make_shared<QSettings>();




public slots:
    void move();

};

#endif // PROJECTILE_H
