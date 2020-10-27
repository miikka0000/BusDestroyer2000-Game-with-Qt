#include "spaceship.h"
#include "basicprojectile.h"
#include "initgame.h"

#include <QTimer>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QImage>
#include <QtDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "bettermainwindow.h"
#include "ui_bettermainwindow.h"
#include <QPalette>
#include <QPixmap>


//const int PADDING = 10;

BetterMainWindow::BetterMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BetterMainWindow)
{
    ui->setupUi(this);

   // bkgndSmall.scaled(this->size(), Qt::IgnoreAspectRatio);

    //ui->graphicsView->DrawWindowBackground();
    //struct, joka kuvaa peliruudun kokoa.
    dimensions size;

    //ui->graphicsView->setFixedSize(size.width_, size.height_);
    //ui->centralwidget->setFixedSize(size.width_ + PADDING, size.height_ + PADDING);




    // create the scene
    scene_ = new QGraphicsScene();
    ui->graphicsView->setScene(scene_);

    scene_->setSceneRect(0,0, size.width_, size.height_);


    //resize(minimumSizeHint());
    //ui->graphicsView->fitInView(0,0, width(), height(), Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene_, &QGraphicsScene::advance);
    timer->start(interval);
    QTimer *timer2 = new QTimer(this);
    timer2->start(100);
    connect(timer2, &QTimer::timeout, this, &BetterMainWindow::getWindowSize);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    player_ = new Spaceship();
    //player_->setDimensions();

    player_->setPos(size.width_ / 2, (size.height_ - player_->spaceshipHeight_) / 2);


    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();

    scene_->addItem(player_);

}

BetterMainWindow::~BetterMainWindow()
{
    delete ui;
}

/*void BetterMainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

       ui->graphicsView->setFixedWidth(event->size().height());

       if(ui->graphicsView->scene()){
           ui->graphicsView->fitInView(ui->graphicsView->scene()->sceneRect(), Qt::KeepAspectRatio);
       }


}*/

void BetterMainWindow::getWindowSize()
{
    dimensions size;
    int w = ui->centralwidget->width();
    int h = ui->centralwidget->height();

    size.width_ = w;
    size.height_ = h;
    player_->screenWidth_ = w;
    player_->screenHeight_ = h;
    scene_->setSceneRect(0,0, size.width_, size.height_);


    //emit emitDimensions(viewWidth, viewHeight);
    //qDebug()<<"Window width: " << w;
    //qDebug()<<"Window height: " << h;


}




