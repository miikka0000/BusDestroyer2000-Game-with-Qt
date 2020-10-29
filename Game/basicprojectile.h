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
    int _projectileVelocity = 25;
    int _projectileHeight;
    int _projectileWidth;


public slots:
    void move();


};

#endif // PROJECTILE_H
