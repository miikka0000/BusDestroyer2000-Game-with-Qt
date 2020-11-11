#include "player.h"
#include "basicprojectile.h"
#include "initgame.h"
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "gamecity.h"
#include "bonusitem.h"
#include "gameoverdialog.h"

#include <QTimer>
#include <QTime>
#include <QImage>
#include <QtDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QDesktopWidget>
#include <vector>
#include <QString>
#include <QList>
#include <QScreen>
#include <QGraphicsRectItem>
#include <memory>

extern std::shared_ptr<gameStatistics> smartStats;
extern QTime _gameTime;

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    _mainTimer(new QTimer),
    _bonusTimer(new QTimer),
    _gameTimer(new QTimer),
    _labelTimer(new QTimer),
    _scene(new QGraphicsScene),
    _newGame(new initGame),
    _player(new Player)

{
    ui->setupUi(this);
    ui->centralwidget->layout()->setContentsMargins(0, 0, 0, this->height() * 0.03);

    setPicture(_bkgndBig);
    ui->graphicsView->setScene(_scene);
    _scene->setSceneRect(0,0, screenWidth, screenHeight);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setLCDStyle();

    connect(_mainTimer, &QTimer::timeout, this, &GameWindow::screenFrameUpdate);
    connect(_labelTimer, &QTimer::timeout, this, &GameWindow::addDataToLCD);
    connect(_bonusTimer,&QTimer::timeout, this, &GameWindow::spawnBonusItem);
    connect(_gameTimer, &QTimer::timeout, this, &GameWindow::updateCountDown);

    _mainTimer->start(_frameRate);
    _labelTimer->start(_interval);
    _bonusTimer->start(_spawnBonusInterval);
    _gameTimer->start(_countDownInterval);

    _player->setPos(screenWidth / 2, screenHeight - 100);
    _player->setFlag(QGraphicsItem::ItemIsFocusable);
    _player->setFocus();
    _scene->addItem(_player);

    addDataToLCD();
    setGameTime();
    _newGame->initLogic(_scene);

}

GameWindow::~GameWindow()
{
    delete ui;
    delete _player;
    delete _mainTimer;
    delete _bonusTimer;
    delete _gameTimer;
    delete _labelTimer;
    delete _scene;
    delete _player;
    delete _newGame;
}

void GameWindow::resizeEvent(QResizeEvent *event)
{
    if(_largeMode){

        int newWidth = event->size().width();
        int newHeight = event->size().height();
        screenWidth = newWidth;
        screenHeight = newHeight;
        _newGame->screenWidth = newWidth;
        _newGame->screenHeight = newHeight;

        if(ui->graphicsView->width() > 800){
            std::vector<int> screen = getAvailableSize();
            _player->setPos(screen.at(0) / 5, screen.at(1) / 2 );

        } else {
            _player->setPos(400,500);
        }
        ui->graphicsView->fitInView(_scene->sceneRect(), Qt::IgnoreAspectRatio);
    }
    _largeMode = true;
}

void GameWindow::setPicture(QImage img)
{
    _scene->addPixmap(QPixmap::fromImage(img.scaled(this->width(), this->height(),
                                                    Qt::IgnoreAspectRatio)));
}

std::vector<int> GameWindow::getAvailableSize()
{
    QList<QScreen *> rec = QGuiApplication::screens();
    QRect availableGeometry = rec.at(0)->geometry();
    int availableHeight = availableGeometry.height();
    int availableWidth = availableGeometry.width();
    return {availableWidth, availableHeight};
}

void GameWindow::setLCDStyle()
{
    ui->pointsLCD->setPalette(Qt::black);
    ui->clockLCD->setPalette(Qt::black);
}

void GameWindow::spawnBonusItem()
{
    bonusItem *bonusGem = new bonusItem;
    bonusGem->currentWidth = this->width();
    bonusGem->currentHeight = this->height();
    _scene->addItem(bonusGem);
}

void GameWindow::addDataToLCD()
{
    ui->pointsLCD->display(smartStats->givePoints());
    ui->clockLCD->display(_gameTime.toString("m:ss"));
}

void GameWindow::setGameTime()
{
    int timeOpt = _playerSettings->value("time setting").toInt();
    if(timeOpt == settingsDialog::gameTime1) {
        _gameDuration = 1; //min

    } else if(timeOpt == settingsDialog::gameTime2) {
        _gameDuration = 2;

    } else if(timeOpt == settingsDialog::gameTime3) {
        _gameDuration = 3;
    }
    _gameTime.setHMS(0,_gameDuration, 0);
    // testauksen ajaksi sekunnit 5
    //_gameTime.setHMS(0,0, 5);

}

void GameWindow::screenFrameUpdate()
{
    ui->graphicsView->update();
}

void GameWindow::stopTimers()
{
    _gameTimer->stop();
    _bonusTimer->stop();
    _mainTimer->stop();
    _labelTimer->stop();
}

void GameWindow::updateCountDown()
{
    if (_gameTime.second() > 0 || _gameTime.minute() > 0) {
        _gameTime = _gameTime.addSecs(-1);

    } else if (_gameTime.second() == 0 && _gameTime.minute() == 0) {
        GameOverDialog *gameOverDialog = new GameOverDialog();
        stopTimers();
        _newGame->endGame();
        gameOverDialog->show();
        this->close();
    }
}







