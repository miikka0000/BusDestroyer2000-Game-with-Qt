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
#include <QColor>
#include <QGraphicsRectItem>
#include <QBrush>


GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->centralwidget->layout()->setContentsMargins(0, this->height() * 0.1, 0, 0);

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

    _player->setPos(size.width / 2, size.height - 100);
    _player->setFlag(QGraphicsItem::ItemIsFocusable);
    _player->setFocus();
    _scene->addItem(_player);

    //drawPanel(0, 0, this->width(), 0.10 * this->height(), Qt::lightGray, 1);


}

GameWindow::~GameWindow()
{
    delete ui;
    _playerSettings.clear();
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

    qDebug() << "available w: " << availableWidth;
    qDebug() << "available h: " << availableHeight;
    return {availableWidth, availableHeight};

}

void GameWindow::drawPanel(int x, int y, int width, int height, QColor color, double opacity){

    QGraphicsRectItem* topPanel = new QGraphicsRectItem(x, y, width, height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    topPanel->setBrush(brush);
    topPanel->setOpacity(opacity);
    _scene->addItem(topPanel);
}








