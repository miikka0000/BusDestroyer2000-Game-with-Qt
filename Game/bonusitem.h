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
    /**
      * @brief Default constructor of the class. As a default, parent is set to a nullpointer to QGraphicsItem.
      * @post bonusItem is at initialization state.
      */
    bonusItem(QGraphicsItem * parent=0);

    int currentWidth = 800;
    int currentHeight = 600;

public slots:
    /**
     * @brief move function is responsible for moving the bonusItem, that is the bonus diamond, downwards in the game map in a constant speed.
     * @pre -
     * @post The bonusItem has moved in the map and is deleted from the scene and the memory if it exits the game screen without being collected by the player. Exception guarantee: nothrow.
     */
    void move();

private:
    QTimer *_bonusTimer;
    int _bonusInterval = 50;
    const QPixmap _gemPic = QPixmap(":/images/bonusGem_30x15.png");

};


#endif // BONUSITEM_H
