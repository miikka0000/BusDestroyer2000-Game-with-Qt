#include "player.h"
#include "basicprojectile.h"
#include "bettermainwindow.h"
#include "mainmenudialog.h"


#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPixmap>
#include <QDebug>
#include <QImage>
#include <QSoundEffect>
#include <QUrl>
#include <QTimer>
#include <QString>
#include <memory>


Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    initMusic(blasterSound);
    _moveTimer = new QTimer(this);
    connect(_moveTimer, &QTimer::timeout, this, &Player::movePlayer);

    _moveTimer->start(interval);
    setPos(mapToParent(pos().x(), pos().y()));
}

Player::~Player()
{

}


void Player::keyPressEvent(QKeyEvent *event)
{


    if(event->key() == Qt::Key_Left){
        //qDebug() << "key left pressed";
        _keyLeft = true;

    }  else if(event->key() == Qt::Key_Right){

        //qDebug() << "key right pressed";
        _keyRight = true;

    } else if(event->key() == Qt::Key_Up){
        //qDebug() << "key up pressed";
        _keyUp = true;

    } else if(event->key() == Qt::Key_Down){
        //qDebug() << "key down pressed";
        _keyDown = true;

    }  else if(event->key() == Qt::Key_Space){
        if ( !event->isAutoRepeat() ){
            basicProjectile *projectile = new basicProjectile();
            projectile->setProjectilePicture();
            projectile->setPos(x() + 20, y() - 10);
            scene()->addItem(projectile);

            //Äänet asetetaan tässä alla. HUOM. aiheuttaa latenssia!

            if (musicsOn){
               setMusic();
            }

        }
        //qDebug() << "space pressed";
        _keySpace = true;

    } else if(event->key() == Qt::Key_Plus){
        changePlayerSpeed(1);

    } else if(event->key() == Qt::Key_Minus){
        changePlayerSpeed(0);
        qDebug()<<"minuse pressed";
    }
    return;
}


void Player::keyReleaseEvent(QKeyEvent * event)
{ 
    if (!event->isAutoRepeat())
    {
        if(event->key() == Qt::Key_Left){
            //qDebug() << "Left key relased.";
            _keyLeft = false;

        } else if(event->key() == Qt::Key_Right){

            //qDebug() << "Right key relased.";
            _keyRight = false;

        } else if(event->key() == Qt::Key_Up){
            //qDebug() << "Up key relased.";
            _keyUp = false;
        } else if(event->key() == Qt::Key_Down){
            //qDebug() << "Down key relased.";
            _keyDown = false;
        }  else if(event->key() == Qt::Key_Space){
            //qDebug() << "Space key relased.";
            _keySpace = false;

        }
        return;
    }
}

void Player::movePlayer(){

    if(_keyLeft){
        if(pos().x() + 10  > 0){
            setPos(x() - _spaceshipVelocity, y());
        }
    } else if(_keyRight){
        if(pos().x() + 37  < screenWidth){
            setPos(x() + _spaceshipVelocity, y());
        }
    } else if(_keyUp){
        if(pos().y()- 25 > 0){
            setPos(x(), y() - _spaceshipVelocity);
        }
    } else if(_keyDown){

        if(pos().y() + 30 < screenHeight){
            setPos(x(), y() + _spaceshipVelocity);
        }

    }
    //qDebug() << "x-koord: "<<pos().x()<<"and y-koord: "<<pos().y();
    xCoord = pos().x();
    yCoord = pos().y();
}


void Player::setDimensions()
{
    if(tankChosen){
        playerHeight = tankPic.height();
        playerWidth = tankPic.width();
    } else if(spaceshipChosen){
        playerHeight = spaceshipPic.height();
        playerWidth = spaceshipPic.width();
    } else if(ufoChosen){
        playerHeight = ufoPic.height();
        playerWidth = ufoPic.width();
    }

    qDebug() << "ship height: "<< playerHeight;
    qDebug() << "ship width: "<< playerWidth;
}

void Player::changePlayerSpeed(int delta)
{
    // 5 % increase in velocity when player presses '+' -key
    double increaseMultiplier = 1.05;
    double decreaseMultiplier = 0.95;
    if(delta == 1 && _spaceshipVelocity < 25.0){
        _spaceshipVelocity = _spaceshipVelocity*increaseMultiplier;
        _projectileVelocity = _projectileVelocity*increaseMultiplier;
        // 5 % decrease in velocity when player presses '+' -key
    } else if(delta == 0 && _spaceshipVelocity > 21.0){
        _spaceshipVelocity = _spaceshipVelocity*decreaseMultiplier;
        _projectileVelocity = _projectileVelocity*decreaseMultiplier;
    }
}

void Player::addPlayerSprite()
{

    if(spaceshipChosen){
        setPixmap(spaceshipPic);

    } else if(tankChosen){
        setPixmap(tankPic);

    } else if(ufoChosen){
        setPixmap(ufoPic);
    }

}

void Player::initMusic(QUrl blasterSoundEffect)
{
    _projectileSound = new QSoundEffect(this);
    _projectileSound->setSource(blasterSoundEffect);
}

void Player::setMusic()
{
    if (_projectileSound->isPlaying()){
        _projectileSound->stop();
    }
    _projectileSound->setVolume(0.25f);
    _projectileSound->play();
}




