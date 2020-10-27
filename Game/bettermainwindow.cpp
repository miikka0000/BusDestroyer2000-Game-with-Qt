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
#include <QBrush>


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

    setPicture(bkgndSmall);


    //resize(minimumSizeHint());
    //ui->graphicsView->fitInView(0,0, width(), height(), Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene_, &QGraphicsScene::advance);
    timer->start(interval_);

    /*QTimer *timer2 = new QTimer(this);
    timer2->start(5000);
    connect(timer2, &QTimer::timeout, this, &BetterMainWindow::getWindowSize);*/

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    player_ = new Spaceship();
    //player_->setDimensions();

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

    //QMainWindow::resizeEvent(event);
    int newWidth = event->size().width();
    int newHeight = event->size().height();
    dimensions size;


    size.width_ = newWidth;
    size.height_ = newHeight;
    player_->screenWidth_ = newWidth;
    player_->screenHeight_ = newHeight;
    scene_->setSceneRect(0,0, size.width_, size.height_);

    player_->x_ = player_->pos().x();
     player_->y_ = player_->pos().y();
     qDebug() << player_->x_;
     qDebug() << player_->y_;


    int scalex = 800 / newWidth;
    int scaley = 600 / newHeight;


    if(ui->graphicsView->width() > 800){
   player_->setPos(960, 946);}
    else{player_->setPos(400,500);}
    largeMode=true;






    qDebug()<<"resize Window width: " << newWidth;
     qDebug()<<"resize Window width: " << newHeight;

     setPicture(bkgndSmall);

}
/*void BetterMainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

       ui->graphicsView->setFixedWidth(event->size().height());

       if(ui->graphicsView->scene()){
           ui->graphicsView->fitInView(ui->graphicsView->scene()->sceneRect(), Qt::KeepAspectRatio);
       }


}*/

/*void BetterMainWindow::getWindowSize()
{
    dimensions size;
    int w = ui->graphicsView->width();
    int h = ui->graphicsView->height();

    size.width_ = w;
    size.height_ = h;
    player_->screenWidth_ = w;
    player_->screenHeight_ = h;



    //emit emitDimensions(viewWidth, viewHeight);
    qDebug()<<"Window width: " << w;
    qDebug()<<"Window height: " << h;


}*/

void BetterMainWindow::setPicture(QImage img)
{


    dimensions size;

    //img.scaled(size.width_, size.height_, Qt::KeepAspectRatio);
    scene_->setBackgroundBrush(QBrush(img));
}




