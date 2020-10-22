#include "spaceship.h"
#include "basicprojectile.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPixmap>
#include <QDebug>
#include <QImage>
#include <QSoundEffect>
#include <QUrl>

#include <memory>


Spaceship::Spaceship(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/spaceship.png"));
    projectileSound = new QSoundEffect(this);
    projectileSound->setSource(QUrl("qrc:/sounds/blaster_sound.wav"));
}

Spaceship::~Spaceship()
{

}

void Spaceship::keyPressEvent(QKeyEvent *event)
{
    dimensions size;

    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x() - spaceshipVelocity_, y());
        }
    } else if(event->key() == Qt::Key_Right){
        if(pos().x() + 50 < size.screenWidth_){
            setPos(x() + spaceshipVelocity_, y());
        }
    } else if(event->key() == Qt::Key_Up){
        if(pos().y() - spaceshipHeight_ > 0){
            setPos(x(), y() - spaceshipVelocity_);
        }
    } else if(event->key() == Qt::Key_Down){

        if(pos().y() + spaceshipHeight_ < size.screenHeight_){
            setPos(x(), y() + spaceshipVelocity_);
        }

    } else if(event->key() == Qt::Key_Space){
        basicProjectile *fireball = new basicProjectile();
        fireball->setPos(x() + 20, y() - 10);
        scene()->addItem(fireball);

        if (projectileSound->isPlaying()){
            projectileSound->stop();
        }
        projectileSound->setVolume(0.25f);
        projectileSound->play();
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


