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
const int PADDING = 10;
BetterMainWindow::BetterMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BetterMainWindow)
{
    ui->setupUi(this);

    dimensions size;

    ui->graphicsView->setFixedSize(size.width_, size.height_);    //struct, joka kuvaa peliruudun kokoa.
    ui->centralwidget->setFixedSize(size.width_ + PADDING, size.height_ + PADDING);




    // create the scene
    QGraphicsScene *scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    scene->setSceneRect(0,0, size.width_, size.height_);

    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(interval);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    player_ = new Spaceship();
    //player_->setDimensions();

    player_->setPos(size.width_ / 2, size.height_ - player_->spaceshipHeight_);


    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();

    scene->addItem(player_);

}

BetterMainWindow::~BetterMainWindow()
{
    delete ui;
}
