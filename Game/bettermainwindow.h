#ifndef BETTERMAINWINDOW_H
#define BETTERMAINWINDOW_H
#include "spaceship.h"
#include "basicprojectile.h"
#include "graphics/simplemainwindow.hh"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QPalette>
#include <QImage>
#include <QBrush>
#include <QPaintEvent>
#include <vector>


namespace Ui {
class BetterMainWindow;
}

class BetterMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BetterMainWindow(QWidget *parent = nullptr);
    ~BetterMainWindow();

    void resizeEvent(QResizeEvent * event);

    //void getWindowSize();
    void setPicture(QImage img);
    //void paintEvent(QPaintEvent *pe);
    std::vector<int> getAvailableSize();



    QGraphicsScene * scene_;
    Spaceship * player_;
    basicProjectile *projectile_;
    //Score * score;
    //Health * health;

    struct dimensions {
        int width_ = 800;
        int height_ = 600;
    };
    int interval_ = 500; //ms

    //int viewWidth_ = 800;
    //int viewHeight_ = 600;
     QImage bkgndSmall = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
     QImage bkgndBig = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");


/*signals:
    void emitDimensions(int w, int h);*/

private:
    Ui::BetterMainWindow *ui;
    QTimer *timer;

    QPixmap _pixmapBg = QPixmap(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    bool largeMode = false;

};

#endif // BETTERMAINWINDOW_H
