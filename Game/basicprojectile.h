#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "gamesetupdata.h"

#include <QGraphicsRectItem>
#include <QPixmap>
#include <QTimer>

class basicProjectile: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    basicProjectile(QGraphicsItem *parent= 0);
    ~basicProjectile();
    void setDimensions();
    void setProjectilePicture();

    bool fireballChosen;
    bool missileChosen;
    bool laserChosen;

private:

    setUp::gameSetUpData *_playerData;
    int _projectileVelocity = 25;
    int _projectileHeight;
    int _projectileWidth;

    QTimer *_projectileTimer;
    int _fireRate = 50;

    QPixmap _fireballPic = QPixmap(":/images/fireball_16x16.png");
    QPixmap _missilePic = QPixmap(":/images/missile_23x10.png");
    QPixmap _laserPic = QPixmap(":/images/laser_32x32.png");

public slots:
    void move();

};

#endif // PROJECTILE_H
