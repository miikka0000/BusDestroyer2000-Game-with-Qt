#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsRectItem>
#include <QPixmap>

class basicProjectile: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    basicProjectile(QGraphicsItem *parent= 0);
    ~basicProjectile();
    void setDimensions();
    void setProjectilePicture();


    bool fireballChosen = false;
    bool missileChosen = false;
    bool laserChosen = false;

private:
    int _projectileVelocity = 25;
    int _projectileHeight;
    int _projectileWidth;

    QPixmap _fireballPic = QPixmap(":/images/fireball_16x16.png");
    QPixmap _missilePic = QPixmap(":/images/missile_23x10.png");
    QPixmap _laserPic = QPixmap(":/images/laser_32x32.png");


public slots:
    void move();


};

#endif // PROJECTILE_H
