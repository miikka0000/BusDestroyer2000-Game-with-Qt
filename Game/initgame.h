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
    void endGame();


private:

    int screenWidth = 800;
    int screenHeight = 600;
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

#endif // GAME_H

