#include "gamecity.h"

#include <QTime>
#include <vector>
#include <memory>
#include <QGraphicsItem>
#include <QPixmap>
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <map>


gameCity::gameCity()
{

}

gameCity::~gameCity()
{

}

/**
 * @brief setBackground sets the bitmap picture of the game area.
 * @param basicbackground  Normal sized picture used as the game area. Bottom left position of the picture in pixelcoordinates can be found out using the offset()-method.
 * @param bigbackground  Background of the game that is bigger than normal. Used only if doing Scrolling map-expansion. Bottom left position of the picture in pixelcoordinates can be found out using the offset()-method.
 * @pre City is in init state.
 * @post Picture for the game area is set. Exception guarantee: basic.
 * @exception InitError Setting the picture was unsuccesful or the picture was invalid.
 */
void gameCity::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    if(!gameStateOn){
        try {
            /*if(this->width() > 500 && this->height() > 500){
                scene()->addPixmap(QPixmap::fromImage(basicbackground.scaled(this->width(), this->height(),
                                                                             Qt::IgnoreAspectRatio)));
            }else {*/
                scene()->addPixmap(QPixmap::fromImage(bigbackground.scaled(800, 600,
                                                                           Qt::IgnoreAspectRatio)));
                backgroundSet = true;


        }  catch (...) {
            throw Interface::InitError("InitError Setting the picture was"
                            " unsuccesful or the picture was invalid.");
        }

    }
}


/**
 * @brief setClock sets the time of the game clock.
 * @param clock Game clock time at the function call.
 * @pre `kello.isValid() == true`.
 * @post Time is set. Exception guarantee: nothrow.
 */
void gameCity::setClock(QTime clock)
{
    if(clock.isValid()){
        gameClock = clock;
        gameClockSet = true;
    }
    return;
}

/**
 * @brief addStop adds a stop to the city.
 * @param stop pointer to a stop object.
 * @pre City is in init state.
 * @post Stop is added to the city. Exception guarantee: basic
 * @exception InitError Stops position is not valid.
 */
void gameCity::addStop(std::shared_ptr<Interface::IStop> stop)
{
    if(!gameStateOn){
        try {
            allStops.push_back(stop);
        }  catch (...) {
            throw Interface::InitError("InitError Stops position is not valid.");
        }

    }
}

/**
 * @brief startGame shifts city from init state to the gamestate.
 * @pre City is in init state. setBackground() and setClock() have been called.
 * @post City is in gamestate. Exception guarantee: nothrow.
 */
void gameCity::startGame()
{
    if(backgroundSet && gameClockSet && !gameStateOn){
        gameStateOn = true;
    }
    return;

}

/**
 * @brief addActor adds a new actor to the city.
 * @param newactor actor to be added to the city that fulfills ActorIF.
 * @pre -
 * @post Actor is added to the city. Exception guarantee: basic.
 * @exception GameError Actor is already in the city.
 */
void gameCity::addActor(std::shared_ptr<Interface::IActor> newactor)
{


    if(findActor(newactor)){
        throw Interface::GameError("GameError Actor is already in the city.");

    } else{

        allActors.push_back(newactor);
    }
    return;

}

/**
 * @brief removeActor removes the actor from the city.
 * @param actor Actor to be removed.
 * @pre City is in gamestate.
 * @post Actor is removed from the city. Exception guarantee: strong.
 * @exception GameError Actor not found in the city
 */
void gameCity::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    if(gameStateOn){
        if(!findActor(actor)){
            throw Interface::GameError("GameError Actor not found in the city");
        } else {
            for(unsigned int i = 0; i < allActors.size(); ++i){
                if(allActors.at(i) == actor){
                    allActors.erase(allActors.begin() + i);
                }
            }
            return;
        }
        return;

    }
    return;
}


/**
 * @brief actorRemoved tells the city that actor is removed ingame.
 * @param actor Actor that is set removed ingame.
 * @pre City is in gamestate. Given actor is found in the city. Actor has `actor.isRemoved() == true`.
 * @post Exception guarantee: strong.
 */
void gameCity::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    if(gameStateOn && findActor(actor) && actor->isRemoved() == true){


        //emit removeThisActor(actor);
        qDebug() << "actor removed ingame. actor removed signal emitted";

    }
    return;


}

/**
 * @brief findActor checks if the given actor is in the city.
 * @param actor Actor that that is looked for in the city.
 * @pre -
 * @return Boolean that tells wether the actor is in the city.
 * @post Exception guarantee: nothrow.
 */
bool gameCity::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    for(unsigned int i = 0; i < allActors.size(); ++i){
        if(allActors.at(i) == actor){
            return true;
        }
    }
    return false;
}

/**
 * @brief actorMoved is an operation that is used to tell wether certain actor has moved.
 * @param actor Actor that has moved.
 * @pre City is in gamestate. Given actor is found in the city.
 * @post Exception guarantee: basic.
 */
void gameCity::actorMoved(std::shared_ptr<Interface::IActor> actor)
{

    if(gameStateOn && findActor(actor)){
        if(actor->giveLocation().calcDistance(startingLoc, actor->giveLocation()) != 0){

            //emit moveThisActor(actor);
            qDebug() << "actor has moved. actor removed signal emitted";

        }
    }
    return;
}

/**
 * @brief getNearbyActors returns actors that are close to given position.
 * @param loc Location for getting the actors close to it.
 * @pre City is in gamestate.
 * @return Vector containing actors close to the location, that pass `getLocation().isClose(loc) == true`.
 * @post Exception guarantee: strong.
 */
std::vector<std::shared_ptr<Interface::IActor> > gameCity::getNearbyActors(Interface::Location loc) const
{
    std::vector<std::shared_ptr<Interface::IActor>> nearbyActors =
            std::vector<std::shared_ptr<Interface::IActor>>();

    if(gameStateOn){
        for(unsigned int i = 0; i < allActors.size(); ++i){
            if(loc.isClose(allActors.at(i)->giveLocation())){
                nearbyActors.push_back(allActors.at(i));
            }

        }

    }
    return nearbyActors;

}


/**
 * @brief isGameOver tells wether the game is overor not.
 * @pre City is in gamestate.
 * @return `true`, if game is over, else ´false´
 * @post Exception guarantee: nothrow.
 */
bool gameCity::isGameOver() const
{
    if(gameStateOn){
        if(gameClock == QTime(0,0)){

            return true;
        }
        return false;

    }
    return false;
}






