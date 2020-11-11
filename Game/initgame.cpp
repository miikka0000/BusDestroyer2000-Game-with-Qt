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
    _updateTimer->start(200);
}

initGame::~initGame()
{
    delete _updateTimer;
}

void initGame::drawStops(std::shared_ptr<gameCity> currCity, QGraphicsScene *scene)
{

    _stopsVec = currCity->allStops;

    for (unsigned int i= 0; i < _stopsVec.size(); ++i){

        QGraphicsPixmapItem *stopRect = new QGraphicsPixmapItem(this);
        int xCoord = _stopsVec.at(i)->getLocation().giveX();
        int yCoord = _stopsVec.at(i)->getLocation().giveY();

        setActorPos(xCoord, yCoord, stopRect);
        setActorPic(_stopPic, stopRect, 15, 25);

        _stopMap.insert({ _stopsVec.at(i), stopRect });

        if(xCoord < screenWidth && xCoord >= 0 &&
                yCoord + 25 < screenHeight && yCoord > 0){
            scene->addItem(stopRect);
        }
    }
}

void initGame::readActors(std::shared_ptr<gameCity> currCity)
{
    _actorsVec = currCity->allActors;

    for (unsigned int i= 0; i < _actorsVec.size(); ++i){
        if(typeid (*(_actorsVec.at(i))) == typeid(CourseSide::Nysse)){
            _nysseVec.push_back(_actorsVec.at(i));

        }else if(typeid (*(_actorsVec.at(i))) == typeid(CourseSide::Passenger)){
            _passengerVec.push_back(_actorsVec.at(i));
        }
    }
}

void initGame::drawActorItems(QGraphicsScene *scene)
{
    for (unsigned int i= 0; i < _nysseVec.size(); ++i){
        QGraphicsPixmapItem *nysseRect = new QGraphicsPixmapItem(this);
        int nysseLocX = _nysseVec.at(i)->giveLocation().giveX();
        int nysseLocY = _nysseVec.at(i)->giveLocation().giveY();

        setActorPos(nysseLocX, nysseLocY, nysseRect);
        setActorPic(_busPic, nysseRect, 10, 20);
        _nysseMap.insert({ _nysseVec.at(i), nysseRect });
        _actorsMap.insert({ _nysseVec.at(i), nysseRect });

        if(nysseLocX + 10 < screenWidth && nysseLocX >= 0 &&
                nysseLocY + 20 < screenHeight && nysseLocY > 0){
            scene->addItem(nysseRect);
        }
    }

    for (unsigned int i= 0; i < _passengerVec.size(); ++i){
        QGraphicsPixmapItem *passengerRect = new QGraphicsPixmapItem(this);
        int passengerLocX = _passengerVec.at(i)->giveLocation().giveX();
        int passengerLocY = _passengerVec.at(i)->giveLocation().giveY();

        setActorPos(passengerLocX, passengerLocY, passengerRect);

        setActorPic(_passengerPic, passengerRect, 10, 15);
        _passengerMap.insert({ _passengerVec.at(i), passengerRect });
        _actorsMap.insert({ _passengerVec.at(i), passengerRect });

        if(passengerLocX + 10 < screenWidth && passengerLocX >= 0 &&
                passengerLocY + 15 < screenHeight && passengerLocY > 0){
            scene->addItem(passengerRect);
        }
    }
    smartActors = _actorsMap;
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
    _gameLogic = std::make_shared<CourseSide::Logic>();

    _newCity = createGame();

    _gameLogic->takeCity(_newCity);
    _newCity->backgroundSet = true;

    _gameLogic->fileConfig();

    // Logic defines time accuracy within seconds and Nysse within minutes,
    // so it is necessary to call setTime before finalizing gamestart
    _gameLogic->setTime(QTime::currentTime().hour(), QTime::currentTime().minute());

    _gameLogic->finalizeGameStart();
    drawStops(_newCity, scene);
    readActors(_newCity);
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
    _newCity->isGameOver();
}






