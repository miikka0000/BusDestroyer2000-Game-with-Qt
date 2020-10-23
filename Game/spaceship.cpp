#include "spaceship.h"
#include "basicprojectile.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPixmap>
#include <QDebug>
#include <QImage>
#include <QSoundEffect>
#include <QUrl>
#include <QTimer>

#include <memory>


Spaceship::Spaceship(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/spaceship.png"));
    projectileSound = new QSoundEffect(this);
    projectileSound->setSource(QUrl("qrc:/sounds/blaster_sound.wav"));


    QTimer * move_timer = new QTimer();
    connect(move_timer, &QTimer::timeout,this, &Spaceship::moveSpaceship);
    move_timer->start(50);

    this->setDimensions();
    qDebug() << "player height:"<<this->spaceshipHeight_;
    qDebug() << "player width:"<<this->spaceshipWidth_;


}

Spaceship::~Spaceship()
{

}


void Spaceship::keyPressEvent(QKeyEvent *event)
{


    if(event->key() == Qt::Key_Left){
        qDebug() << "key left pressed";
        keyLeft = true;

    }  else if(event->key() == Qt::Key_Right){

        qDebug() << "key right pressed";
        keyRight = true;
    } else if(event->key() == Qt::Key_Up){
        qDebug() << "key up pressed";
        keyUp = true;

    } else if(event->key() == Qt::Key_Down){
        qDebug() << "key down pressed";
        keyDown = true;
    }  else if(event->key() == Qt::Key_Space){

        if ( !event->isAutoRepeat() ){
            //std::unique_ptr<basicProjectile> fireball = std::make_unique<basicProjectile>();
            basicProjectile *fireball = new basicProjectile();
            fireball->setPos(x() + 20, y() - 10);
            scene()->addItem(fireball);

            //Äänet asetetaan tässä alla. HUOM. aiheuttaa latenssia!
            if (projectileSound->isPlaying()){
                projectileSound->stop();
            }
            projectileSound->setVolume(0.25f);
            projectileSound->play();
        }
        qDebug() << "space pressed";
        keySpace = true;
    }
    return;


}


void Spaceship::keyReleaseEvent(QKeyEvent * event)
{

    if (!event->isAutoRepeat())
    {

        if(event->key() == Qt::Key_Left){
            qDebug() << "Left key relased.";
            keyLeft = false;

        } else if(event->key() == Qt::Key_Right){

            qDebug() << "Right key relased.";
            keyRight = false;

        } else if(event->key() == Qt::Key_Up){
            qDebug() << "Up key relased.";
            keyUp = false;
        } else if(event->key() == Qt::Key_Down){
            qDebug() << "Down key relased.";
            keyDown = false;
        }  else if(event->key() == Qt::Key_Space){
            qDebug() << "Space key relased.";
            keySpace = false;

        }
        return;


    }

}



void Spaceship::moveSpaceship(){
    dimensions size;

    if(keyLeft){
        if(pos().x() > 0){
            setPos(x() - spaceshipVelocity_, y());
        }
    } else if(keyRight){
        if(pos().x() + 50 < size.screenWidth_){
            setPos(x() + spaceshipVelocity_, y());
        }
    } else if(keyUp){
        if(pos().y() - spaceshipHeight_ > 0){
            setPos(x(), y() - spaceshipVelocity_);
        }
    } else if(keyDown){

        if(pos().y() + spaceshipHeight_ < size.screenHeight_){
            setPos(x(), y() + spaceshipVelocity_);
        }

    }
}




void Spaceship::setDimensions()
{
    QImage *spaceship= new QImage(":/images/spaceship.png");



    spaceshipHeight_ = spaceship->height();
    spaceshipWidth_ = spaceship->width();
    //qDebug() << "ship height: "<< playerHeight_;
    //qDebug() << "ship width: "<< playerWidth_;
    delete spaceship;

}


