#include "player.h"
#include "initgame.h"
#include "gamewindow.h"
#include "mainmenudialog.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QScreen>
#include <QCoreApplication>
#include <QSettings>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Tampere University");
    QCoreApplication::setApplicationName("BusDestroyer");
    QSettings mySettings;

    Q_INIT_RESOURCE(offlinedata);

    MainMenuDialog * menuUi = new MainMenuDialog();


    menuUi->exec();




    return a.exec();
}

