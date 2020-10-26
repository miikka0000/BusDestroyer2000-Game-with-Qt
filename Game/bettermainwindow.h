#ifndef BETTERMAINWINDOW_H
#define BETTERMAINWINDOW_H
#include "spaceship.h"
#include "basicprojectile.h"
#include "graphics/simplemainwindow.hh"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>


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

    void getCenter();

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

    int viewWidth = 400;
    int viewHeight = 300;

private:
    Ui::BetterMainWindow *ui;
    QTimer *timer;
};

#endif // BETTERMAINWINDOW_H
