#include "player.h"
#include "basicprojectile.h"
#include "gamewindow.h"
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
#include <vector>
#include <QSettings>
#include <string>


Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    QSettings s;
    qDebug()<<s.value("music setting").toInt();
    addPlayerSprite();
    savePlayerName();
    initMusic();

    _moveTimer = new QTimer(this);
    connect(_moveTimer, &QTimer::timeout, this, &Player::movePlayer);
    _moveTimer->start(_interval);
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

            std::vector<int> playerCenter = getPlayerOrigin(playerWidth, playerHeight);
            basicProjectile *projectile = new basicProjectile();
            projectile->setPos(x() + playerCenter.at(0), y() - playerCenter.at(1));
            scene()->addItem(projectile);
            setMusicChoice();
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
        if(pos().x()  > 0){
            setPos(x() - _spaceshipVelocity, y());
        }
    } else if(_keyRight){
        if(pos().x() + playerWidth  < screenWidth){
            setPos(x() + _spaceshipVelocity, y());
        }
    } else if(_keyUp){
        if(pos().y() > 0){
            setPos(x(), y() - _spaceshipVelocity);
        }
    } else if(_keyDown){

        if(pos().y() + playerHeight < screenHeight){
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

    QSettings settings;
    int chosenSkin = settings.value("player type setting").toInt();
    //qDebug()<< chosenSkin;

    if(chosenSkin == MainMenuDialog::spaceshipOption){
        qDebug()<<"you chose spaceship";
        spaceshipChosen = true;
        setPixmap(spaceshipPic);

    } else if(chosenSkin == MainMenuDialog::tankOption){
        qDebug()<<"you chose tank";
        tankChosen = true;
        setPixmap(tankPic);

    } else if(chosenSkin == MainMenuDialog::ufoOption){
        qDebug()<<"you chose ufo";
        ufoChosen = true;
        setPixmap(ufoPic);
    }

    setDimensions();

}

void Player::initMusic()
{
    _projectileSound = new QSoundEffect(this);
    QSettings musicSetting;
    qDebug()<<musicSetting.value("music setting").toInt();
    int soundEffect = musicSetting.value("projectile soundeffect setting").toInt();
    if(soundEffect == MainMenuDialog::fireballSound){
        _projectileSound->setSource(fireballSound);

    }else if(soundEffect == MainMenuDialog::missileSound){
        _projectileSound->setSource(missileSound);

    }else if(soundEffect == MainMenuDialog::blasterSound){
        _projectileSound->setSource(blasterSound);
    }

}

void Player::configureMusic()
{
    if (_projectileSound->isPlaying()){
        _projectileSound->stop();
    }
    _projectileSound->setVolume(0.25f);
    _projectileSound->play();
}

void Player::setMusicChoice()
{
    QSettings musicSettings;
    int musicOpt = musicSettings.value("music setting").toInt();

    if(musicOpt == settingsDialog::musicStateOn){
        this->musicsOn = true;
        configureMusic();

    } else if(musicOpt == settingsDialog::musicStateOff){
        this->musicsOn = false;
        return;
    }
}

void Player::savePlayerName()
{
    QSettings settings;
    QString playerNickname = settings.value("player name setting").toString();
    playerName = playerNickname.toStdString();
    //qDebug()<<QString::fromStdString(playerName);
}

std::vector<int> Player::getPlayerOrigin(int width, int height)
{
    std::vector<int> playerDimensions;
    int centerWidth = width / 2;
    int centerHeight = height / 2;
    playerDimensions.push_back(centerWidth);
    playerDimensions.push_back(centerHeight);

    return playerDimensions;
}




