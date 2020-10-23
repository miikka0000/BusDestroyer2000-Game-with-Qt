#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsRectItem>

class basicProjectile: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    basicProjectile(QGraphicsItem *parent= 0);
    ~basicProjectile();
    void setDimensions();

private:
    int projectileVelocity_ = 25;
    int projectileHeight_;
    int projectileWidth_;


public slots:
    void move();


};

#endif // PROJECTILE_H
