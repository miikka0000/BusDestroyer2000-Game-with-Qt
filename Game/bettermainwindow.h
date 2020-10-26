#ifndef BETTERMAINWINDOW_H
#define BETTERMAINWINDOW_H
#include "spaceship.h"
#include "basicprojectile.h"
#include "graphics/simplemainwindow.hh"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>

namespace Ui {
class BetterMainWindow;
}

class BetterMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BetterMainWindow(QWidget *parent = nullptr);
    ~BetterMainWindow();

    QGraphicsScene * scene_;
    Spaceship * player_;
    basicProjectile *projectile_;
    //Score * score;
    //Health * health;

    struct dimensions {
        int screenWidth = 800;
        int screenHeight = 600;
    };

private:
    Ui::BetterMainWindow *ui;
};

#endif // BETTERMAINWINDOW_H
