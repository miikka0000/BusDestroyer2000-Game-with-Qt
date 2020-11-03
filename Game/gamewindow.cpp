#include "player.h"
#include "basicprojectile.h"
#include "initgame.h"
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "gamecity.h"
#include "bonusitem.h"
#include "playergamescore.h"
#include "playerhealth.h"
#include "gameoverdialog.h"
#include "graphics/simpleactoritem.hh"
#include "actors/nysse.hh"
#include "actors/passenger.hh"




#include <QTimer>
#include <QTime>
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
#include <QColor>
#include <QGraphicsRectItem>
#include <QBrush>
#include <memory>


extern std::shared_ptr<playerGameScore> smartPlayerScore;
extern std::shared_ptr<playerHealth> smartPlayerHealth;
extern QTime _gameTime;



GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->centralwidget->layout()->setContentsMargins(0, 0, 0, this->height() * 0.03);

    setLCDStyle();

    _scene = new QGraphicsScene();

    setPicture(bkgndBig);
    ui->graphicsView->setScene(_scene);
    _scene->setSceneRect(0,0, screenWidth, screenHeight);

    mainTimer = new QTimer(this);
    labelTimer = new QTimer(this);
    connect(mainTimer, &QTimer::timeout, _scene, &QGraphicsScene::advance);
    // adding player score by 10 if gem is picked
    connect(labelTimer, &QTimer::timeout, this, &GameWindow::addDataToLCD);
    mainTimer->start(interval);
    labelTimer->start(interval);

    bonusTimer = new QTimer(this);
    connect(bonusTimer,&QTimer::timeout, this, &GameWindow::spawnBonusItem);


    // Spawning bonus gems every 4 seconds
    bonusTimer->start(4000);


    _player = new Player();

    _player->setPos(screenWidth / 2, screenHeight - 100);
    _player->setFlag(QGraphicsItem::ItemIsFocusable);
    _player->setFocus();
    _scene->addItem(_player);
    addDataToLCD();


    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setGameTime();
    gameTimer = new QTimer(this);

    connect(gameTimer, &QTimer::timeout, this, &GameWindow::updateCountDown);
    gameTimer->start(1000);


    /*
    //luodaan uusi Logic-olio
    CourseSide::Logic *gameLogic =  new CourseSide::Logic();
    // parametri creategame palauttaa shared_ptr<Interface::gameCity>
    std::shared_ptr<Interface::gameCity> newCity = createGame();
    gameLogic->takeCity(newCity);
    gameLogic->fileConfig();
    //Logic määrittelee ajan sekunnin tarkkuudella ja Nysset minuutin tarkkuudella
    // ->vaihdetaan Logicin aika minuutin tarkkuuteen
    gameLogic->setTime(QTime::currentTime().hour(), QTime::currentTime().minute());
    gameLogic->finalizeGameStart();
    qDebug()<<"stop amount: "<<newCity->allStops.size();
    drawStops(newCity);
    drawBuses(newCity);
    //qDebug()<<_playerSettings->value("time setting").toInt();*/

    initGame *courseSide = new initGame();
    courseSide->initLogic(_scene);

}

GameWindow::~GameWindow()
{
    delete ui;
    delete _player;
    delete bonusObject;
    delete mainTimer;
    delete bonusTimer;
    delete gameTimer;
    delete labelTimer;

}

void GameWindow::resizeEvent(QResizeEvent *event)
{
    if(_largeMode){

        int newWidth = event->size().width();
        int newHeight = event->size().height();


        screenWidth = newWidth;
        screenHeight = newHeight;
        //player_->screenWidth_ = newWidth;
        //player_->screenHeight_ = newHeight;

        if(ui->graphicsView->width() > 800){
            std::vector<int> screen = getAvailableSize();
            _player->setPos(screen.at(0) / 5, screen.at(1) / 2 );}
        else{
            _player->setPos(400,500);
        }

        //qDebug()<<"resize Window width: " << newWidth;
        //qDebug()<<"resize Window width: " << newHeight;

        //setPicture(bkgndBig);
        ui->graphicsView->fitInView(_scene->sceneRect(), Qt::IgnoreAspectRatio);

    }
    _largeMode = true;

}

void GameWindow::setPicture(QImage img)
{

    _scene->addPixmap(QPixmap::fromImage(img.scaled(this->width(), this->height(),
                                                    Qt::IgnoreAspectRatio)));
}

/*void GameWindow::keyReleaseEvent(QKeyEvent *keyEvent)
{
    if(keyEvent->key() == Qt::Key_Escape){
        qDebug()<<"esc pressed";
        _player->musicsOn = false;


    }
}*/

std::vector<int> GameWindow::getAvailableSize()
{

    QList<QScreen *> rec = QGuiApplication::screens();
    QRect availableGeometry = rec.at(0)->geometry();
    int availableHeight = availableGeometry.height();

    int availableWidth = availableGeometry.width();

    //qDebug() << "available w: " << availableWidth;
    //qDebug() << "available h: " << availableHeight;
    return {availableWidth, availableHeight};

}


void GameWindow::setLCDStyle()
{
    ui->healthLCD->setPalette(Qt::red);
    ui->pointsLCD->setPalette(Qt::black);
    ui->clockLCD->setPalette(Qt::black);
}

void GameWindow::spawnBonusItem()
{

    BonusItem * bonusGem = new BonusItem();
    bonusGem->currentWidth = this->width();
    bonusGem->currentHeight = this->height();
    _scene->addItem(bonusGem);
}

void GameWindow::addDataToLCD()
{

    ui->pointsLCD->display(smartPlayerScore->getPlayerScore());
    ui->healthLCD->display(smartPlayerHealth->getPlayerHealth());
    ui->clockLCD->display(_gameTime.toString("m:ss"));

}


void GameWindow::setGameTime()
{
    int timeOpt = _playerSettings->value("time setting").toInt();
    if(timeOpt == settingsDialog::gameTime1) {
        _gameDuration = 1; //min
    }
    else if(timeOpt == settingsDialog::gameTime2) {
        _gameDuration = 2;
    }
    else if(timeOpt == settingsDialog::gameTime3) {
        _gameDuration = 3;
    }

    _gameTime.setHMS(0,_gameDuration, 0);
    // testauksen ajaksi sekunnit 5
    //_gameTime.setHMS(0,0, 5);

}

void GameWindow::updateCountDown() {
    if (_gameTime.second() > 0 || _gameTime.minute() > 0) {
        _gameTime = _gameTime.addSecs(-1);
    }
    else if (_gameTime.second() == 0 && _gameTime.minute() == 0) {
        GameOverDialog *gameOverDialog = new GameOverDialog();
        gameTimer->stop();
        bonusTimer->stop();
        mainTimer->stop();

        gameOverDialog->show();
        this->close();
    }

}

/*void GameWindow::drawStops(std::shared_ptr<Interface::gameCity> currCity)
{


    std::vector<std::shared_ptr<Interface::IStop>> stops = currCity->allStops;
    for (unsigned int i= 0; i < stops.size(); ++i){


        auto rectItem = new QGraphicsPixmapItem();
        rectItem->setPos(stops.at(i)->getLocation().giveX() , stops.at(i)->getLocation().giveY());
        rectItem->setPixmap(stopPic);
        _scene->addItem(rectItem);

    }


}

void GameWindow::drawBuses(std::shared_ptr<Interface::gameCity> currCity)
{

    std::vector<std::shared_ptr<Interface::IActor>> actors = currCity->allActors;
    std::vector<std::shared_ptr<Interface::IActor>> nysses;
    std::vector<std::shared_ptr<Interface::IActor>> people;

    qDebug() <<"actors amount: "<<actors.size();

    for (unsigned int i= 0; i < actors.size(); ++i){
        if(typeid (*actors.at(i)) == typeid(CourseSide::Nysse)){
            nysses.push_back(actors.at(i));
        }else if(typeid (*actors.at(i)) == typeid(CourseSide::Passenger)){
            people.push_back(actors.at(i));
        }

    }

    for (unsigned int i= 0; i < nysses.size(); ++i){
        auto rectItem = new QGraphicsPixmapItem();
        int xCoord = nysses.at(i)->giveLocation().giveX();
        int yCoord = nysses.at(i)->giveLocation().giveY();

        rectItem->setPos(nysses.at(i)->giveLocation().giveX(), nysses.at(i)->giveLocation().giveY());
        rectItem->setPixmap(busPic.scaled(10, 20, Qt::IgnoreAspectRatio, Qt::FastTransformation));
        if(xCoord < screenWidth && xCoord >= 0 &&
                yCoord + 20 < screenHeight && yCoord > 0){
            _scene->addItem(rectItem);
        }
    }
    qDebug() << "nysse amount: "<<nysses.size();

    for (unsigned int i= 0; i < people.size(); ++i){
        auto rectItem = new QGraphicsPixmapItem();
        int xCoord = people.at(i)->giveLocation().giveX();
        int yCoord = people.at(i)->giveLocation().giveY();
        rectItem->setPos(people.at(i)->giveLocation().giveX(), people.at(i)->giveLocation().giveY());
        rectItem->setPixmap(passengerPic.scaled(10, 15,  Qt::IgnoreAspectRatio, Qt::FastTransformation));
        if(xCoord < screenWidth && xCoord >= 0 &&
                yCoord + 15 < screenHeight && yCoord > 0){
            _scene->addItem(rectItem);
        }

    }
    qDebug() << "people amount: "<<nysses.size();



}
std::shared_ptr<Interface::gameCity> GameWindow::createGame()
{
    std::shared_ptr<Interface::gameCity> newGameCity = std::make_shared<Interface::gameCity>();

    return newGameCity;
}*/






