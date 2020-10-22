#include "spaceship.h"
#include "initGame.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QScreen>
/*
//checking available screen size
QScreen* screen = QGuiApplication::primaryScreen();
QRect  screenGeometry = screen->geometry();
int height = screenGeometry.height();
int width = screenGeometry.width();

*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    initGame * game = new initGame();

    game->show();


    return a.exec();
}

