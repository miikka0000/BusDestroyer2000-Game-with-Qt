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

extern std::shared_ptr<StudentSide::gameStatistics> smartStats;
extern QTime _gameTime;
namespace StudentSide {

gameCity::gameCity()
{
}

gameCity::~gameCity()
{
}

void gameCity::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    if(!gameStateOn){
        if(scene()->width() > 500 && scene()->height() > 500)
            scene()->addPixmap(QPixmap::fromImage(bigbackground.scaled(800, 600,
                                                                       Qt::IgnoreAspectRatio)));
        else{
            scene()->addPixmap(QPixmap::fromImage(basicbackground.scaled(800, 600,
                                                                         Qt::IgnoreAspectRatio)));
        }
        backgroundSet = true;

    } else {
        throw Interface::InitError("InitError Setting the picture was"
                                   " unsuccesful or the picture was invalid.");
    }
}

void gameCity::setClock(QTime clock)
{
    if(clock.isValid()){
        gameClock = clock;
        gameClockSet = true;
    }
    return;
}

void gameCity::addStop(std::shared_ptr<Interface::IStop> stop)
{
    if(!gameStateOn){
        allStops.push_back(stop);

    } else{
        throw Interface::InitError("InitError Stops position is not valid.");
    }
}

void gameCity::startGame()
{
    if(backgroundSet && gameClockSet && !gameStateOn){
        gameStateOn = true;
    }
    return;
}

void gameCity::addActor(std::shared_ptr<Interface::IActor> newactor)
{

    if(findActor(newactor)){
        throw Interface::GameError("GameError Actor is already in the city.");
    } else{
        allActors.push_back(newactor);
    }
    return;
}

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

void gameCity::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    if(gameStateOn && findActor(actor) && actor->isRemoved() == true){

        if(typeid (*(actor)) == typeid(CourseSide::Nysse)){
            smartStats->nysseLeft();
        } else if(typeid (*(actor)) == typeid (CourseSide::Passenger)){
            smartStats->passengerLeft();
        }
    }
    return;
}

bool gameCity::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    for(unsigned int i = 0; i < allActors.size(); ++i){
        if(allActors.at(i) == actor){
            return true;
        }
    }
    return false;
}

void gameCity::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    if(gameStateOn && findActor(actor)){
        if(actor->giveLocation().calcDistance(startingLoc, actor->giveLocation()) != 0){

            smartStats->actorMoved();
        }
    }
    return;
}

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

bool gameCity::isGameOver() const
{
    if(gameStateOn){
        if(_gameTime.second() == 0 && _gameTime.minute() == 0){

            return true;
        }
        return false;
    }
    return false;
}
}





