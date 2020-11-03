#include "player.h"
#include "basicprojectile.h"
#include "initgame.h"

#include <QTimer>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QtDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <map>
#include <typeinfo>

#include <memory>


initGame::initGame(){

    /*gameCity *city = new gameCity;

    connect(city, &gameCity::moveThisActor, this,
            &initGame::moveActor);
    connect(city, &gameCity::removeThisActor, this,
            &initGame::moveActor);*/
    _updateTimer = new QTimer(this);
    connect(_updateTimer, &QTimer::timeout, this, &initGame::moveNysses);
     connect(_updateTimer, &QTimer::timeout, this, &initGame::movePassengers);
    _updateTimer->start(10);

}

initGame::~initGame()
{

}

void initGame::drawStops(std::shared_ptr<gameCity> currCity, QGraphicsScene *scene)
{

    stopsVec = currCity->allStops;

    for (unsigned int i= 0; i < stopsVec.size(); ++i){

        QGraphicsPixmapItem *stopRect = new QGraphicsPixmapItem();
        int xCoord = stopsVec.at(i)->getLocation().giveX();
        int yCoord = stopsVec.at(i)->getLocation().giveY();

        setActorPos(xCoord, yCoord, stopRect);
        setActorPic(stopPic, stopRect, 15, 25);

        stopMap.insert({stopsVec.at(i), stopRect});

        if(xCoord < screenWidth && xCoord >= 0 &&
                yCoord + 25 < screenHeight && yCoord > 0){
            scene->addItem(stopRect);
        }

    }
}

void initGame::readActors(std::shared_ptr<gameCity> currCity)
{
    actorsVec = currCity->allActors;
    qDebug()<<"actorsVec size: "<< actorsVec.size();

    for (unsigned int i= 0; i < actorsVec.size(); ++i){
        if(typeid (*actorsVec.at(i)) == typeid(CourseSide::Nysse)){
            nysseVec.push_back(actorsVec.at(i));

        }else if(typeid (*actorsVec.at(i)) == typeid(CourseSide::Passenger)){
            passengerVec.push_back(actorsVec.at(i));
        }

    }
    qDebug()<<"nysseVec size: "<< nysseVec.size();
    qDebug()<<"passengerVec size: "<< passengerVec.size();
}

void initGame::drawActorItems(QGraphicsScene *scene)
{


    for (unsigned int i= 0; i < nysseVec.size(); ++i){
        QGraphicsPixmapItem *nysseRect = new QGraphicsPixmapItem();
        int nysseLocX = nysseVec.at(i)->giveLocation().giveX();
        int nysseLocY = nysseVec.at(i)->giveLocation().giveY();

        setActorPos(nysseLocX, nysseLocY, nysseRect);
        setActorPic(busPic, nysseRect, 10, 20);
        nysseMap.insert({nysseVec.at(i), nysseRect});

        if(nysseLocX < screenWidth && nysseLocX >= 0 &&
                nysseLocY + 20 < screenHeight && nysseLocY > 0){
            scene->addItem(nysseRect);
        }
    }


    for (unsigned int i= 0; i < passengerVec.size(); ++i){
        QGraphicsPixmapItem *passengerRect = new QGraphicsPixmapItem();
        int xCoord = passengerVec.at(i)->giveLocation().giveX();
        int yCoord = passengerVec.at(i)->giveLocation().giveY();

        setActorPos(xCoord, yCoord, passengerRect);


        setActorPic(passengerPic, passengerRect, 10, 15);
        passengerMap.insert({passengerVec.at(i), passengerRect});
        if(xCoord < screenWidth && xCoord >= 0 &&
                yCoord + 15 < screenHeight && yCoord > 0){
            scene->addItem(passengerRect);
        }

    }
}

void initGame::setActorPic(QPixmap pic, QGraphicsPixmapItem *actorItem,int w, int h)
{
    actorItem->setPixmap(pic.scaled(w, h,  Qt::IgnoreAspectRatio, Qt::FastTransformation));
}

void initGame::setActorPos(int newX, int newY, QGraphicsPixmapItem *item)
{
    item->setPos(newX, newY);
}

void initGame::initLogic(QGraphicsScene *scene)
{
    gameLogic = std::make_shared<CourseSide::Logic>();

    newCity = createGame();

    gameLogic->takeCity(newCity);
    newCity->backgroundSet = true;

    gameLogic->fileConfig();

    // Logic defines time accuracy within seconds and Nysse within minutes,
    // so it is necessary to call setTime before finalizing gamestart
    gameLogic->setTime(QTime::currentTime().hour(), QTime::currentTime().minute());

    gameLogic->finalizeGameStart();
    drawStops(newCity, scene);
    readActors(newCity);
    drawActorItems(scene);
    qDebug()<<"stop amount: "<<stopsVec.size();
    qDebug()<<"nysse bus amount: "<<nysseVec.size();
    qDebug()<<"passenger amount: "<<passengerVec.size();


}



std::shared_ptr<gameCity> initGame::createGame()
{
    std::shared_ptr<gameCity> newGameCity = std::make_shared<gameCity>();

    return newGameCity;
}

void initGame::movePassengers()
{
    for(passengerIt = passengerMap.begin(); passengerIt != passengerMap.end(); ++passengerIt){
        int newX = passengerIt->first->giveLocation().giveX();
        int newY = passengerIt->first->giveLocation().giveY();
        //qDebug()<<"passRect type: "<<  typeid(passengerIt->first).name();
        passengerIt->second->setPos(newX, newY);
    }
}

void initGame::moveNysses()
{
   for(nysseIt = nysseMap.begin(); nysseIt != nysseMap.end(); ++nysseIt){
       int newX = nysseIt->first->giveLocation().giveX();
       int newY = nysseIt->first->giveLocation().giveY();
       //qDebug()<<"nysse type: "<<  typeid(nysseIt->first).name();
       nysseIt->second->setPos(newX, newY);
   }


}

int initGame::getActorHeight(QGraphicsPixmapItem *actor)
{
    return actor->boundingRect().height();
}

int initGame::getActorWidth(QGraphicsPixmapItem *actor)
{
    return actor->boundingRect().width();
}

void initGame::removeActor(std::shared_ptr<Interface::IActor> removedActor)
{
    using std::shared_ptr;
    using std::map;

    map<shared_ptr<Interface::IActor>, QGraphicsPixmapItem*>::iterator itN;
    map<shared_ptr<Interface::IActor>, QGraphicsPixmapItem*>::iterator itP;

    if(typeid (*removedActor) == typeid(CourseSide::Nysse)){
        for(itN = nysseMap.begin(); itN != nysseMap.end(); itN++){
            if(itN->first == removedActor){

                nysseMap.erase(itN);
            }
        }
    } else if(typeid (*removedActor) == typeid(CourseSide::Passenger)){
        for(itP = nysseMap.begin(); itP != nysseMap.end(); itP++){
            if(itP->first == removedActor){
                nysseMap.erase(itP);

            }
        }
    }
}

void initGame::moveActor(std::shared_ptr<Interface::IActor> movedActor)
{
    using std::shared_ptr;
    using std::map;

    map<shared_ptr<Interface::IActor>, QGraphicsPixmapItem*>::iterator itN;
    map<shared_ptr<Interface::IActor>, QGraphicsPixmapItem*>::iterator itP;

    if(typeid (*movedActor) == typeid(CourseSide::Nysse)){
        for(itN = nysseMap.begin(); itN != nysseMap.end(); itN++){
            if(itN->first == movedActor){

                itN->first->move(Interface::Location(300, 300));
                setPos(300 - nysseVelocity, 300 - nysseVelocity);
            }
        }
    } else if(typeid (*movedActor) == typeid(CourseSide::Passenger)){
        for(itP = nysseMap.begin(); itP != nysseMap.end(); itP++){
            if(itP->first == movedActor){



                itP->first->move(Interface::Location(300, 300));
                setPos(300 - passengerVelocity, 300 - passengerVelocity);
            }
        }
    }


}
