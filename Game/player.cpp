#include "player.h"
#include "basicprojectile.h"
#include "gamewindow.h"
#include "mainmenudialog.h"
#include "bonusitem.h"




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
#include <QList>
#include <QGraphicsItem>
#include <memory>

extern std::shared_ptr<gameStatistics> smartStats;


Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    //qDebug()<<_playerSettings->value("music setting").toInt();
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
            //std::unique_ptr<basicProjectile> projectile = std::make_unique<basicProjectile>();
            basicProjectile *projectile = new basicProjectile();
            projectile->setPos(x() + playerCenter.at(0), y() - playerCenter.at(1));
            scene()->addItem(projectile);
            setMusicChoice();
        }
        //qDebug() << "space pressed";
        _keySpace = true;

    } changePlayerSpeed(event);

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

    removeCollidingItem();

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
}

void Player::changePlayerSpeed(QKeyEvent *speedEvent)
{
    // 5 % increase in velocity when player presses '+' -key
    double increaseMultiplier = 1.05;
    // 5 % decrease in velocity when player presses '+' -key
    double decreaseMultiplier = 0.95;

    if(speedEvent->key() == Qt::Key_Plus && _spaceshipVelocity < 26.0){

        _spaceshipVelocity = _spaceshipVelocity*increaseMultiplier;


    } else if(speedEvent->key() == Qt::Key_Minus && _spaceshipVelocity > 23.0){

        _spaceshipVelocity = _spaceshipVelocity*decreaseMultiplier;

    }
}

void Player::addPlayerSprite()
{

    int chosenSkin = _playerSettings->value("player type setting").toInt();  

    if(chosenSkin == MainMenuDialog::spaceshipOption){

        spaceshipChosen = true;
        setPixmap(spaceshipPic);

    } else if(chosenSkin == MainMenuDialog::tankOption){

        tankChosen = true;
        setPixmap(tankPic);

    } else if(chosenSkin == MainMenuDialog::ufoOption){

        ufoChosen = true;
        setPixmap(ufoPic);
    }

    setDimensions();

}

void Player::initMusic()
{
    _projectileSound = new QSoundEffect(this);

    int soundEffect = _playerSettings->value("projectile soundeffect setting").toInt();
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

    int musicOpt = _playerSettings->value("music setting").toInt();

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

    QString playerNickname = _playerSettings->value("player name setting").toString();
    playerName = playerNickname.toStdString();

}

void Player::removeCollidingItem()
{
    QList<QGraphicsItem *> collidingObjects = collidingItems();

    for (int i = 0, j = collidingObjects.size(); i < j; ++i){
        if (typeid(*(collidingObjects[i])) == typeid(bonusItem)){

            smartStats->addPoints();
            smartStats->addCollectedDiamond();
            scene()->removeItem(collidingObjects[i]);
            delete collidingObjects[i];

            return;
        }
    }
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




