#include "player.h"
#include "initgame.h"
#include "gamewindow.h"
#include "mainmenudialog.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    //initGame * game = new initGame();

    //MainMenuDialog * menuUi = new MainMenuDialog();
    GameWindow mainWindow;
    mainWindow.show();
    //mainWindow.giveDialog()->setModal(true);
    mainWindow.giveDialog()->exec();

    //menuUi->show();

    return a.exec();
}

