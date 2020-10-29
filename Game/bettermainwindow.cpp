#include "player.h"
#include "basicprojectile.h"
#include "initgame.h"
#include "bettermainwindow.h"
#include "ui_bettermainwindow.h"
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



BetterMainWindow::BetterMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BetterMainWindow)
{
    ui->setupUi(this);

    //struct, joka sisältää peliruudun koon.
    dimensions size;

    scene_ = new QGraphicsScene();
    //scene_->setSceneRect(0,0, size.width_, size.height_);
    setPicture(bkgndBig);
    ui->graphicsView->setScene(scene_);
    scene_->setSceneRect(0,0, size.width_, size.height_);


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene_, &QGraphicsScene::advance);
    timer->start(interval_);


    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    player_ = new Player();

    qDebug() << player_->playerName;

    player_->setPos(size.width_ / 2, size.height_ - 100);


    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();

    scene_->addItem(player_);



}

BetterMainWindow::~BetterMainWindow()
{
    delete ui;
}

void BetterMainWindow::resizeEvent(QResizeEvent *event)
{
    if(largeMode){

        int newWidth = event->size().width();
        int newHeight = event->size().height();
        dimensions size;

        size.width_ = newWidth;
        size.height_ = newHeight;
        //player_->screenWidth_ = newWidth;
        //player_->screenHeight_ = newHeight;

        player_->x_ = player_->pos().x();
        player_->y_ = player_->pos().y();
        qDebug() << player_->x_;
        qDebug() << player_->y_;


        if(ui->graphicsView->width() > 800){
            std::vector<int> screen = getAvailableSize();
            player_->setPos(screen.at(0) / 5, screen.at(1) / 2 );}
        else{
            player_->setPos(400,500);
        }

        qDebug()<<"resize Window width: " << newWidth;
        qDebug()<<"resize Window width: " << newHeight;

        setPicture(bkgndBig);
        ui->graphicsView->fitInView(scene_->sceneRect(), Qt::IgnoreAspectRatio);


    }
    largeMode = true;

}

void BetterMainWindow::setPicture(QImage img)
{

    scene_->setBackgroundBrush(QBrush(img));
}

std::vector<int> BetterMainWindow::getAvailableSize()
{

    QRect rec = QApplication::desktop()->screenGeometry();
    int availableHeight = rec.height();
    int availableWidth = rec.width();

    qDebug() << "available w: " << availableWidth;
    qDebug() << "available h: " << availableHeight;
    return {availableWidth, availableHeight};

}






