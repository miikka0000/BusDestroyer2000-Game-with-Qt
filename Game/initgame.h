#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "basicprojectile.h"
#include "graphics/simplemainwindow.hh"
#include "gamecity.h"
#include "core/logic.hh"
#include "core/location.hh"
#include "interfaces/iactor.hh"
#include "interfaces/icity.hh"
#include "interfaces/istop.hh"
#include "actors/nysse.hh"
#include "actors/stop.hh"
#include "actors/passenger.hh"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <memory>
#include <vector>
#include <map>
#include <QTime>
#include <QImage>
#include <QObject>
#include <map>
#include <QTimer>

/**
 * @brief
 * All of the classes done by us are found in StudentSide namespace.
 */
namespace StudentSide {

/**
  * @brief Defines a Class in which the CourseSide integration mostly happens.
  * The class is also responsible for moving and showing all the actors offered by CourseSide.
  * Furthermore, CreateGame -function is implemented here.
  */
class initGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor for initGame.
      * @post initGame is at initialization state.
      */
    initGame();

    /**
      * @brief initGame has a basic destructor.
      */
    ~initGame();

    /**
     * @brief drawStops adds all the bus stops that fit in the game mip to the QGraphicsScene and also set the picture for each stop (red flag).
     * @param Shared pointer to the gameCity and a raw pointer to the game's main QGraphicsScene.
     * @pre QGraphicsScene has been created and is active.
     * @post Stops have been added to the game map and they are depicted with a red flag. Exception guarantee: strong.
     */
    void drawStops(std::shared_ptr<gameCity> currCity, QGraphicsScene *scene);

    /**
     * @brief drawActorItems adds all the Nysse-buses and passengers that fit in the game mip to the QGraphicsScene and also set the picture for each Nysse and passenger.
     * @param Raw pointer to the game's main QGraphicsScene.
     * @pre QGraphicsScene has been created and is active.
     * @post Nysses and passengers have been added to the game map and they are depicted with a proper icon. Exception guarantee: strong.
     */
    void drawActorItems(QGraphicsScene *scene);

    /**
     * @brief readActors separates the actors for one another: Nysses and passengers are being pushed to their own vectors.
     * @param Shared pointer to the gameCity.
     * @pre -
     * @post Nysses and passengers are added into their own separate vectors. Exception guarantee: nothrow.
     */
    void readActors(std::shared_ptr<gameCity> currCity);

    /**
     * @brief setActorPic sets an icon picture for desired actor.
     * @param QPixmap pic (picture to be set), QGraphicsPixmapItem raw pointer to the actor, width and the height of the to-be-set picture.
     * @pre -
     * @post Picture for the actor has been set. Exception guarantee: nothrow.
     */
    void setActorPic(QPixmap pic, QGraphicsPixmapItem *actorItem, int w, int h);

    /**
     * @brief setActorPos sets the position of the actor (x- and y-coordinates).
     * @param newX x-coordinate, newY y-coordinate and QGraphicsPixmapItem raw pointer to the actor whose position we want to set.
     * @pre -
     * @post Position for the actor has been set. Exception guarantee: nothrow.
     */
    void setActorPos(int newX, int newY, QGraphicsPixmapItem *actorItem);

    /**
     * @brief initLogic initializes the Logic so that that the CourseSide integration would be possible.
     * @param Raw pointer to the game's main QGraphicsScene.
     * @pre QGraphicsScene has been created and is active.
     * @post New Logic object has been created and properly initialized and finally finalizeGameStart method of Logic is being called to start the back-end functionality. Exception guarantee: nothrow.
     */
    void initLogic(QGraphicsScene *scene);

    /**
     * @brief createGame creates the games city (gameCity object) and returns a shared pointer to it.
     * @pre -
     * @return pointer to the created city which is in initialization state.
     * @post Exception guarantee: basic.
     */
    std::shared_ptr<gameCity> createGame();

    /**
     * @brief moveSceneActors moves the actors in the scene (sets new positions according to their current Location).
     * @pre -
     * @post If actor has moved (it has a different Location than before), then the method updates the actor's new position to the scene. Exception guarantee: nothrow.
     */
    void moveSceneActors();

    /**
     * @brief endGame calls the gameCity's function isGameOver.
     * @pre -
     * @post ICity's function isGameOver has been called. Exception guarantee: nothrow.
     */
    void endGame();

    int screenWidth = 800;
    int screenHeight = 600;

private:
    QTimer *_updateTimer;

    std::map<std::shared_ptr<Interface::IStop>, QGraphicsPixmapItem*> _stopMap;
    std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*> _nysseMap;
    std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*> _passengerMap;
    std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*> _actorsMap;

    std::vector<std::shared_ptr<Interface::IActor>> _nysseVec;
    std::vector<std::shared_ptr<Interface::IActor>> _passengerVec;
    std::vector<std::shared_ptr<Interface::IStop>> _stopsVec;
    std::vector<std::shared_ptr<Interface::IActor>> _actorsVec;

    std::shared_ptr<gameCity> _newCity;
    std::shared_ptr<CourseSide::Logic> _gameLogic;

    const QPixmap _stopPic = QPixmap(":/images/stop_15x25.png");
    const QPixmap _busPic = QPixmap(":/images/bus_10x20.png");
    const QPixmap _passengerPic = QPixmap(":/images/passenger_20x15.png");

};
}
#endif // GAME_H

