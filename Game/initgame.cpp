#include "spaceship.h"
#include "basicprojectile.h"
#include "initgame.h"

#include <QTimer>
#include <QGraphicsTextItem>
#include <QImage>
#include <QtDebug>
#include <QGraphicsScene>
#include <QGraphicsView>


initGame::initGame(){

    //struct, joka kuvaa peliruudun kokoa.
    dimensions screenSize;
    basicProjectile *p = new basicProjectile();
    p->setDimensions();
    delete p;

    // create the scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0, screenSize.screenWidth, screenSize.screenHeight);
    //setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player = new Spaceship();
    player->setDimensions();

    player->setPos(screenSize.screenWidth / 2, screenSize.screenHeight - player->spaceshipHeight_);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

}

initGame::~initGame()
{

}
