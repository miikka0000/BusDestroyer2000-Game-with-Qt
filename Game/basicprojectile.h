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
    /**
      * @brief Basic constructor of the class. As a default, parent is set to a nullpointer to QGraphicsItem.
      * @post basicProjectile is at initialization state.
      */
    basicProjectile(QGraphicsItem *parent= 0);

    /**
      * @brief basicProjectile has a basic destructor.
      */
    ~basicProjectile();

    /**
     * @brief setDimensions sets the width and the height of a chosen projectile type.
     * @pre Chosen projectile type is existent and therefore has some kind of dimensions.
     * @post Dimensions for the chosen projectile type are successfully set. Exception guarantee: nothrow.
     */
    void setDimensions();

    /**
     * @brief setProjectilePicture sets the the chosen picture as the projectile icon in the game.
     * @pre Projectile pictures provided are valid and they exist.
     * @post Projectile picture for the chosen projectile type is set. Exception guarantee: nothrow.
     */
    void setProjectilePicture();

    /**
     * @brief removeShootedActors is responsible for removing the Nysses of passengers (actors) that are in contact with the bullet.
     * @pre Projectile comes in contact with a Nysse or a passenger.
     * @post Shooted Nysse or passenger is deleted from the game and map and memory or nothing happens. Exception guarantee: nothrow.
     */
    bool removeShootedActors();

    /**
     * @brief isClose function is a courtesy from Course Side (core/logic) with slight modifications on parameters. It calculates the distance between two items given as a paremeters within specific limit which is also given as a parameter.
     * @param loc is the location of map item 1, limit is the range in which the isClose boolean states true, and xCoord and yCoord are the coordinates of the second comparable item.
     * @pre -
     * @return boolean statement that basically tells if the two items are in close range to each other
     * @post A boolean (true or false) is returned which tells if the two items are close to each other in the game map. Exception guarantee: nothrow.
     */
    bool isClose(const Interface::Location &loc, int limit, int xCoord, int yCoord);

public slots:
    /**
     * @brief move function is responsible for moving the bullet up in the game map. Also if the bullet encounters a bonus diamond, they both are deleted from the map and from the memory.
     * @pre -
     * @post Bullet has moved in the map and is deleted from the scene and the memory if it encounters a object in its way or exits the game screen. Exception guarantee: nothrow.
     */
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
