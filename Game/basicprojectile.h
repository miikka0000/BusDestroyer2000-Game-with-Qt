#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "bonusitem.h"
#include "mainmenudialog.h"
#include "gamestatistics.h"
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
    bool removeShootedActors();
    // isClose function  is a courtesy from the CourseSide (core/location)
    // with slight modifications on params.
    bool isClose(const Interface::Location &loc, int limit, int xCoord, int yCoord);

public slots:
    void move();

private:
    bool _fireballChosen = false;
    bool _missileChosen = false;
    bool _laserChosen = false;

    int _projectileVelocity = 20;
    int _projectileHeight;
    int _projectileWidth;

    QTimer *_projectileTimer;
    int _fireRate = 50;
    std::shared_ptr<QSettings> _playerSettings = std::make_shared<QSettings>();

    const QPixmap _fireballPic = QPixmap(":/images/fireball_16x16.png");
    const QPixmap _missilePic = QPixmap(":/images/missile_23x10.png");
    const QPixmap _laserPic = QPixmap(":/images/laser_32x32.png");

};

#endif // PROJECTILE_H
