#ifndef GAMECITY_H
#define GAMECITY_H
#include "interfaces/icity.hh"
#include "interfaces/istop.hh"
#include "interfaces/iactor.hh"
#include <QMainWindow>

#include <vector>
#include <memory>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>


class gameCity : public Interface::ICity, Interface::IStop, Interface::IActor,
        Interface::Location, public QObject, public QGraphicsPixmapItem, public QMainWindow
{
    Q_OBJECT
public:
    gameCity();
    ~gameCity();

    virtual void setBackground(QImage& basicbackground, QImage& bigbackground);

    /**
     * @brief setClock sets the time of the game clock.
     * @param clock Game clock time at the function call.
     * @pre `kello.isValid() == true`.
     * @post Time is set. Exception guarantee: nothrow.
     */
    virtual void setClock(QTime clock);

    /**
     * @brief addStop adds a stop to the city.
     * @param stop pointer to a stop object.
     * @pre City is in init state.
     * @post Stop is added to the city. Exception guarantee: basic
     * @exception InitError Stops position is not valid.
     */
    virtual void addStop(std::shared_ptr<IStop> stop);

    /**
     * @brief startGame shofts city from init state to the gamestate.
     * @pre City is in init state. setBackground() and setClock() have been called.
     * @post City is in gamestate. Exception guarantee: nothrow.
     */
    virtual void startGame();
    /**
     * @brief addActor adds a new actor to the city.
     * @param newactor actor to be added to the city that fulfills ActorIF.
     * @pre -
     * @post Actor is added to the city. Exception guarantee: basic.
     * @exception GameError Actor is already in the city.
     */
    virtual void addActor(std::shared_ptr<IActor> newactor);
    /**
     * @brief removeActor removes the actor from the city.
     * @param actor Actor to be removed.
     * @pre City is in gamestate.
     * @post Actor is removed from the city. Exception guarantee: strong.
     * @exception GameError Actor not found in the city
     */
    virtual void removeActor(std::shared_ptr<IActor> actor);

    /**
     * @brief actorRemoved tells the city that actor is removed ingame.
     * @param actor Actor that is set removed ingame.
     * @pre City is in gamestate. Given actor is found in the city. Actor has `actor.isRemoved() == true`.
     * @post Exception guarantee: strong.
     */
    virtual void actorRemoved(std::shared_ptr<IActor> actor);

    /**
     * @brief findActor checks if the given actor is in the city.
     * @param actor Actor that that is looked for in the city.
     * @pre -
     * @return Boolean that tells wether the actor is in the city.
     * @post Exception guarantee: nothrow.
     */
    virtual bool findActor(std::shared_ptr<IActor> actor) const;

    /**
     * @brief actorMoved is an operation that is used to tell wether certain actor has moved.
     * @param actor Actor that has moved.
     * @pre City is in gamestate. Given actor is found in the city.
     * @post Exception guarantee: basic.
     */
    virtual void actorMoved(std::shared_ptr<IActor> actor);

    /**
     * @brief getNearbyActors returns actors that are close to given position.
     * @param loc Location for getting the actors close to it.
     * @pre City is in gamestate.
     * @return Vector containing actors close to the location, that pass `getLocation().isClose(loc) == true`.
     * @post Exception guarantee: strong.
     */
    virtual std::vector<std::shared_ptr<IActor>> getNearbyActors(Location loc) const;

    /**
     * @brief isGameOver tells wether the game is overor not.
     * @pre City is in gamestate.
     * @return `true`, if game is over, else ´false´
     * @post Exception guarantee: nothrow.
     */
    virtual bool isGameOver() const;


};

#endif // GAMECITY_H
