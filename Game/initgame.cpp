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


#include <memory>

extern std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*> smartActors;
initGame::initGame(){


    _updateTimer = new QTimer(this);
    connect(_updateTimer, &QTimer::timeout, this, &initGame::moveSceneActors);
    //interval was previously 50, changed it to 200 to see it it affects fps
    _updateTimer->start(200);

}

initGame::~initGame()
{
    delete _updateTimer;
}

void initGame::drawStops(std::shared_ptr<gameCity> currCity, QGraphicsScene *scene)
{

    stopsVec = currCity->allStops;

    for (unsigned int i= 0; i < stopsVec.size(); ++i){

        QGraphicsPixmapItem *stopRect = new QGraphicsPixmapItem(this);
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

    for (unsigned int i= 0; i < actorsVec.size(); ++i){
        if(typeid (*(actorsVec.at(i))) == typeid(CourseSide::Nysse)){
            nysseVec.push_back(actorsVec.at(i));

        }else if(typeid (*(actorsVec.at(i))) == typeid(CourseSide::Passenger)){
            passengerVec.push_back(actorsVec.at(i));
        }
    }
}

void initGame::drawActorItems(QGraphicsScene *scene)
{

    for (unsigned int i= 0; i < nysseVec.size(); ++i){
        QGraphicsPixmapItem *nysseRect = new QGraphicsPixmapItem(this);
        int nysseLocX = nysseVec.at(i)->giveLocation().giveX();
        int nysseLocY = nysseVec.at(i)->giveLocation().giveY();

        setActorPos(nysseLocX, nysseLocY, nysseRect);
        setActorPic(busPic, nysseRect, 10, 20);
        nysseMap.insert({nysseVec.at(i), nysseRect});
        actorsMap.insert({nysseVec.at(i), nysseRect});

        if(nysseLocX + 10 < screenWidth && nysseLocX >= 0 &&
                nysseLocY + 20 < screenHeight && nysseLocY > 0){
            scene->addItem(nysseRect);
        }
    }

    for (unsigned int i= 0; i < passengerVec.size(); ++i){
        QGraphicsPixmapItem *passengerRect = new QGraphicsPixmapItem(this);
        int passengerLocX = passengerVec.at(i)->giveLocation().giveX();
        int passengerLocY = passengerVec.at(i)->giveLocation().giveY();

        setActorPos(passengerLocX, passengerLocY, passengerRect);

        setActorPic(passengerPic, passengerRect, 10, 15);
        passengerMap.insert({passengerVec.at(i), passengerRect});
        actorsMap.insert({passengerVec.at(i), passengerRect});

        if(passengerLocX + 10 < screenWidth && passengerLocX >= 0 &&
                passengerLocY + 15 < screenHeight && passengerLocY > 0){
            scene->addItem(passengerRect);
        }

    }
    smartActors = actorsMap;
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

}

std::shared_ptr<gameCity> initGame::createGame()
{
    std::shared_ptr<gameCity> newGameCity = std::make_shared<gameCity>();

    return newGameCity;
}

void initGame::moveSceneActors()
{
    std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*>::iterator it;

    for(it = smartActors.begin(); it != smartActors.end(); ++it){
        int newX = it->first->giveLocation().giveX();
        int newY = it->first->giveLocation().giveY();

        it->second->setPos(newX, newY);
    }
}

void initGame::endGame()
{
    newCity->isGameOver();
}

int initGame::getActorHeight(QGraphicsPixmapItem *actor)
{
    return actor->boundingRect().height();
}

int initGame::getActorWidth(QGraphicsPixmapItem *actor)
{
    return actor->boundingRect().width();
}




