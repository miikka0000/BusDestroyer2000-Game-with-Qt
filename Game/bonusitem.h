#ifndef BONUSITEM_H
#define BONUSITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>

class bonusItem: public QObject,public QGraphicsPixmapItem{

    Q_OBJECT

public:
    bonusItem(QGraphicsItem * parent=0);

    int currentWidth = 800;
    int currentHeight = 600;

public slots:
    void move();

private:
    QTimer *_bonusTimer;
    int _bonusInterval = 50;
    const QPixmap _gemPic = QPixmap(":/images/bonusGem_30x15.png");

};


#endif // BONUSITEM_H
