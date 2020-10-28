#include "player.h"
#include "basicprojectile.h"
#include "bettermainwindow.h"


#include <QKeyEvent>
#include <QGraphicsScene>
#include <QPixmap>
#include <QDebug>
#include <QImage>
#include <QSoundEffect>
#include <QUrl>
#include <QTimer>

#include <memory>


Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    setPixmap(shipPic);
    projectileSound = new QSoundEffect(this);
    projectileSound->setSource(QUrl("qrc:/sounds/blaster_sound.wav"));

    //BetterMainWindow *temp = new BetterMainWindow();



    moveTimer = new QTimer();
    connect(moveTimer, &QTimer::timeout, this, &Player::movePlayer);
    //connect(temp, &BetterMainWindow::emitDimensions, this, &Spaceship::setLimits);
    moveTimer->start(interval);

    this->setDimensions();
    setPos(mapToParent(pos().x(), pos().y()));
    //qDebug() << "player height:"<<this->spaceshipHeight_;
    //qDebug() << "player width:"<<this->spaceshipWidth_;
    //delete temp;



}

Player::~Player()
{

}


void Player::keyPressEvent(QKeyEvent *event)
{


    if(event->key() == Qt::Key_Left){
        //qDebug() << "key left pressed";
        keyLeft = true;

    }  else if(event->key() == Qt::Key_Right){

        //qDebug() << "key right pressed";
        keyRight = true;
    } else if(event->key() == Qt::Key_Up){
        //qDebug() << "key up pressed";
        keyUp = true;

    } else if(event->key() == Qt::Key_Down){
        //qDebug() << "key down pressed";
        keyDown = true;
    }  else if(event->key() == Qt::Key_Space){

        if ( !event->isAutoRepeat() ){
            //std::unique_ptr<basicProjectile> fireball = std::make_unique<basicProjectile>();
            basicProjectile *fireball = new basicProjectile();
            fireball->setPos(x() + 20, y() - 10);
            scene()->addItem(fireball);

            //Äänet asetetaan tässä alla. HUOM. aiheuttaa latenssia!
            /*
            if (projectileSound->isPlaying()){
                projectileSound->stop();
            }
            projectileSound->setVolume(0.25f);
            projectileSound->play();
            */
        }
        //qDebug() << "space pressed";
        keySpace = true;
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
            keyLeft = false;

        } else if(event->key() == Qt::Key_Right){

            //qDebug() << "Right key relased.";
            keyRight = false;

        } else if(event->key() == Qt::Key_Up){
            //qDebug() << "Up key relased.";
            keyUp = false;
        } else if(event->key() == Qt::Key_Down){
            //qDebug() << "Down key relased.";
            keyDown = false;
        }  else if(event->key() == Qt::Key_Space){
            //qDebug() << "Space key relased.";
            keySpace = false;

        }
        return;


    }

}



void Player::movePlayer(){
    //qDebug() << "from player: mainWindow width:"<<this->screenWidth_;
    //qDebug() << "from player: mainWindow height:"<<this->screenHeight_;


    if(keyLeft){
        if(pos().x()  > 0){
            setPos(x() - spaceshipVelocity_, y());
        }
    } else if(keyRight){
        if(pos().x() + 55  < screenWidth_){
            setPos(x() + spaceshipVelocity_, y());
        }
    } else if(keyUp){
        if(pos().y()- 25 > 0){
            setPos(x(), y() - spaceshipVelocity_);
        }
    } else if(keyDown){

        if(pos().y() +60 < screenHeight_){
            setPos(x(), y() + spaceshipVelocity_);
        }

    }
    //qDebug() << "x-koord: "<<pos().x()<<"and y-koord: "<<pos().y();
    x_ = pos().x();
    y_ = pos().y();
}




void Player::setDimensions()
{
    QImage *spaceship= new QImage(":/images/spaceship.png");
    playerHeight = spaceship->height();
    playerWidth = spaceship->width();
    //qDebug() << "ship height: "<< playerHeight_;
    //qDebug() << "ship width: "<< playerWidth_;
    delete spaceship;

}

void Player::changePlayerSpeed(int delta)
{
    // 10 % increase when player presses '+' -key
    double increaseMultiplier = 1.05;
    double decreaseMultiplier = 0.95;
    if(delta == 1 && spaceshipVelocity_ < 25.0){
        spaceshipVelocity_ = spaceshipVelocity_*increaseMultiplier;
        projectileVelocity_ = projectileVelocity_*increaseMultiplier;
        //interval = interval*increaseMultiplier;

    } else if(delta == 0 && spaceshipVelocity_ > 21.0){
        spaceshipVelocity_ = spaceshipVelocity_*decreaseMultiplier;
         projectileVelocity_ = projectileVelocity_*decreaseMultiplier;
         //interval = interval*decreaseMultiplier;
    }

}

/*void Player::setLimits(int w, int h)
{



    qDebug() << "mainwindow height: "<< h;
    qDebug() << "mainwindow width: "<< w;

    screenWidth_ = w;
    screenHeight_ = h;


}*/

/*
void MyDialog::on_ok_button_clicked()
{
    //stringValue = ui->inputbox->text();
    //o_type = ui->type_input->text();
    o_amount = ui->inputbox->text().toInt();
    //ui->testlabel->setText("you chose "+ QString::number(o_amount) + " objects");
    if(ui->optionBox->currentIndex() == 0){
        emit setValue(o_amount, FASTBALL);
    } else if(ui->optionBox->currentIndex() == 1){
        emit setValue(o_amount, ODDBALL);
    } else if (ui->optionBox->currentIndex() == 2){
        emit setValue(o_amount, END);
    }


}
*/

