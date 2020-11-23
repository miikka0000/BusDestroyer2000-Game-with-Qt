#ifndef BONUSITEM_H
#define BONUSITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>

/**
 * @brief
 * All of the classes done by the student team are found in StudentSide namespace.
 */
namespace StudentSide {

/**
  * @brief Defines a class for the other unique object in the game: bonusItem's (small red diamonds) that appear randomly in the game map every 4 seconds.
  * If the player manages to collect these bonus items either by moving into their location or by shooting them, 10 points are added to the player score.
  */
class bonusItem: public QObject,public QGraphicsPixmapItem{

    Q_OBJECT

public:
    /**
      * @brief Default constructor of the class. As a default, parent is set to a nullpointer to QGraphicsItem.
      * @post bonusItem is at initialization state.
      */
    bonusItem(QGraphicsItem * parent=0);
    // screen dimensions
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
}
#endif // BONUSITEM_H
