#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "basicprojectile.h"
#include "graphics/simplemainwindow.hh"

#include <QGraphicsView>
#include <QGraphicsScene>


class initGame: public QGraphicsView
{
public:
    initGame();
    ~initGame();

    QGraphicsScene * scene_;
    Player * player_;
    basicProjectile *projectile_;
    //Score * score;
    //Health * health;

    struct dimensions {
        int screenWidth = 800;
        int screenHeight = 600;
    };


};

#endif // GAME_H

