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
    int bulletVelocity_ = 40;
    int bulletHeight_;
    int bulletWidth_;


public slots:
    void move();


};

#endif // PROJECTILE_H
