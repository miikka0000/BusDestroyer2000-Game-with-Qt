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


namespace Ui {
class BetterMainWindow;
}

class BetterMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BetterMainWindow(QWidget *parent = nullptr);
    ~BetterMainWindow();

    //void resizeEvent(QResizeEvent * event);

    void getWindowSize();



    QGraphicsScene * scene_;
    Spaceship * player_;
    basicProjectile *projectile_;
    //Score * score;
    //Health * health;

    struct dimensions {
        int width_ = 800;
        int height_ = 600;
    };
    int interval = 500; //ms

    //int viewWidth_ = 800;
    //int viewHeight_ = 600;
     const QPixmap bkgndSmall = QPixmap(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
     const QPixmap bkgndBig = QPixmap(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
     QPalette palette;

/*signals:
    void emitDimensions(int w, int h);*/

private:
    Ui::BetterMainWindow *ui;
    QTimer *timer;

};

#endif // BETTERMAINWINDOW_H
