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
     //struct, joka kuvaa peliruudun kokoa.
    dimensions size;

    //ui->graphicsView->setFixedSize(size.width_, size.height_);
    //ui->centralwidget->setFixedSize(size.width_ + PADDING, size.height_ + PADDING);




    // create the scene
    QGraphicsScene *scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    scene->setSceneRect(0,0, size.width_, size.height_);

    //resize(minimumSizeHint());
    //ui->graphicsView->fitInView(0,0, width(), height(), Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(interval);
    QTimer *timer2 = new QTimer(this);
    timer2->start(100);
    connect(timer2, &QTimer::timeout, this, &BetterMainWindow::getCenter);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    player_ = new Spaceship();
    //player_->setDimensions();

    player_->setPos(viewWidth, viewHeight - player_->spaceshipHeight_);


    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();

    scene->addItem(player_);

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

void BetterMainWindow::getCenter()
{
    int w = ui->centralwidget->width() / 2;
    int h = ui->graphicsView->height() / 2;

    viewWidth = w;
    viewHeight = h;


}




