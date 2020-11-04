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


class initGame: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    initGame();
    ~initGame();

    void drawStops(std::shared_ptr<gameCity> currCity, QGraphicsScene *scene);

    void readActors(std::shared_ptr<gameCity> currCity);
    void drawActorItems(QGraphicsScene *scene);

    void setActorPic(QPixmap pic, QGraphicsPixmapItem *actorItem, int w, int h);

    void setActorPos(int newX, int newY, QGraphicsPixmapItem *item);

     void initLogic(QGraphicsScene *scene);

     void drawAllStops(std::shared_ptr<gameCity> currCity, QGraphicsScene *scene);
     void drawBuses(std::shared_ptr<gameCity> currCity, QGraphicsScene *scene);
    std::shared_ptr<gameCity> createGame();
    void moveNysses();
    void movePassengers();
    void moveSceneActors();

    int getActorHeight(QGraphicsPixmapItem *actor);
    int getActorWidth(QGraphicsPixmapItem *actor);

    std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*>::iterator nysseIt;
    std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*>::iterator passengerIt;




    QPixmap stopPic = QPixmap(":/images/stop_15x25.png");
    QPixmap busPic = QPixmap(":/images/bus_10x20.png");
    QPixmap passengerPic = QPixmap(":/images/passenger_20x15.png");


    std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*> nysseMap;
    std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*> passengerMap;
    std::map<std::shared_ptr<Interface::IStop>, QGraphicsPixmapItem*> stopMap;

     std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*> actorsMap;

    std::vector<std::shared_ptr<Interface::IActor>> nysseVec;
    std::vector<std::shared_ptr<Interface::IActor>> passengerVec;
    std::vector<std::shared_ptr<Interface::IStop>> stopsVec;
    std::vector<std::shared_ptr<Interface::IActor>> actorsVec;


    std::shared_ptr<gameCity> newCity;
    std::shared_ptr<CourseSide::Logic> gameLogic;


    QImage basicbackgroung = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage bigbackground = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    int nysseVelocity = 10;
    int passengerVelocity = 5;



private:

    int screenWidth = 800;
    int screenHeight = 600;
    QTimer *_updateTimer;



};

#endif // GAME_H

