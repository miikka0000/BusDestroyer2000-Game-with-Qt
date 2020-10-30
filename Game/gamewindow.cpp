#include "player.h"
#include "basicprojectile.h"
#include "initgame.h"
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <mainmenudialog.h>
#include <ufo.h>
#include <tank.h>
#include <spaceship.h>

#include <QTimer>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QImage>
#include <QtDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPalette>
#include <QPixmap>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QDesktopWidget>
#include <vector>
#include <QString>
#include <QList>
#include <QScreen>



GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    dimensions size;

    _scene = new QGraphicsScene();

    setPicture(bkgndBig);
    ui->graphicsView->setScene(_scene);
    _scene->setSceneRect(0,0, size.width, size.height);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, _scene, &QGraphicsScene::advance);
    timer->start(interval);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    _player = new Player();

    _mainMenu = new MainMenuDialog();
    connect(_mainMenu, &MainMenuDialog::setPlayerName, this, &GameWindow::setPlayerNick);
    connect(_mainMenu, &MainMenuDialog::setPlayerType, this, &GameWindow::setPlayerIcon);
    connect(_mainMenu, &MainMenuDialog::setMusicState, this, &GameWindow::setMusicChoice);

    //connect(_mainMenu, &MainMenuDialog::setProjectileType, this, &BetterMainWindow::setProjectileIcon);

    _player->setPos(size.width / 2, size.height - 100);
    _player->setFlag(QGraphicsItem::ItemIsFocusable);
    _player->setFocus();
    _scene->addItem(_player);



}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::resizeEvent(QResizeEvent *event)
{
    if(_largeMode){

        int newWidth = event->size().width();
        int newHeight = event->size().height();
        dimensions size;

        size.width = newWidth;
        size.height = newHeight;
        //player_->screenWidth_ = newWidth;
        //player_->screenHeight_ = newHeight;

        _player->xCoord = _player->pos().x();
        _player->yCoord = _player->pos().y();
        qDebug() << _player->xCoord;
        qDebug() << _player->yCoord;


        if(ui->graphicsView->width() > 800){
            std::vector<int> screen = getAvailableSize();
            _player->setPos(screen.at(0) / 5, screen.at(1) / 2 );}
        else{
            _player->setPos(400,500);
        }

        qDebug()<<"resize Window width: " << newWidth;
        qDebug()<<"resize Window width: " << newHeight;

        setPicture(bkgndBig);
        ui->graphicsView->fitInView(_scene->sceneRect(), Qt::IgnoreAspectRatio);

    }
    _largeMode = true;

}

void GameWindow::setPicture(QImage img)
{

    _scene->setBackgroundBrush(QBrush(img));
}

/*void BetterMainWindow::keyReleaseEvent(QKeyEvent *keyEvent)
{
    if(keyEvent->key() == Qt::Key_Escape){
        qDebug()<<"esc pressed";
        if(this->width() > 800 && this->height() > 600){
            this->resize(800,600);
        }


    }
}*/

std::vector<int> GameWindow::getAvailableSize()
{

    QList<QScreen *> rec = QGuiApplication::screens();
    QRect availableGeometry = rec.at(0)->geometry();
    int availableHeight = availableGeometry.height();

    int availableWidth = availableGeometry.width();

    qDebug() << "available w: " << availableWidth;
    qDebug() << "available h: " << availableHeight;
    return {availableWidth, availableHeight};

}

void GameWindow::setPlayerNick(QString name)
{
    qDebug() << "setPlayerName signal received";
    _player->playerName = name;
    qDebug() << "player name: "<< _player->playerName;

}

void GameWindow::setPlayerIcon(int type)
{
    qDebug() << "setPlayerIcon signal received";
    if(type == MainMenuDialog::tankOption){
        _player->tankChosen = true;
    } else if(type == MainMenuDialog::spaceshipOption){
        _player->spaceshipChosen = true;
    } else if(type == MainMenuDialog::ufoOption){
        _player->ufoChosen = true;
    }
    _player->addPlayerSprite();
    _player->setDimensions();
}

void GameWindow::setMusicChoice(int choice)
{
    qDebug() << "setMusicChoice signal received";
    if(choice == MainMenuDialog::musicStateOn){
        _player->musicsOn = true;
    } else if(choice == MainMenuDialog::musicStateOff){
        _player->musicsOn = false;
    }

    /*void BetterMainWindow::setProjectileIcon(int projectileType)
{

    qDebug() << "setProjectileIcon signal received, you chose: "<<projectileType;
    //_projectile = new basicProjectile();
    if(projectileType == MainMenuDialog::fireballOption){
        _player->projectile->fireballChosen = true;

    } else if(projectileType == MainMenuDialog::missileOption){
        _player->projectile->missileChosen = true;

    } else if(projectileType == MainMenuDialog::laserOption){
        _player->projectile->laserChosen = true;
    }
    _player->projectile->setProjectilePicture();
    _player->projectile->setDimensions();
}*/


}


