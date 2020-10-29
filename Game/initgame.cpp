#include "player.h"
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

    setFixedSize(200,200);

    dimensions screenSize;


    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0, screenSize.screenWidth, screenSize.screenHeight);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    player_ = new Player();

    player_->setPos(screenSize.screenWidth / 2, screenSize.screenHeight - player_->playerHeight);

    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();

    scene->addItem(player_);

}

initGame::~initGame()
{

}
