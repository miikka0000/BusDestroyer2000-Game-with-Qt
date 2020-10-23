#include "spaceship.h"
#include "basicprojectile.h"
#include "initgame.h"

#include <QTimer>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QImage>
#include <QtDebug>
#include <QGraphicsScene>
#include <QGraphicsView>


initGame::initGame(){


    //struct, joka kuvaa peliruudun kokoa.
    dimensions screenSize;
    //basicProjectile *p = new basicProjectile();
    //p->setDimensions();
    //delete p;


    // create the scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0, screenSize.screenWidth, screenSize.screenHeight);
    //setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player_ = new Spaceship();
    //player_->setDimensions();

    player_->setPos(screenSize.screenWidth / 2, screenSize.screenHeight - player_->spaceshipHeight_);


    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();

    scene->addItem(player_);

}

initGame::~initGame()
{

}
