#include "player.h"
#include "playergamescore.h"
#include "gamewindow.h"
#include "mainmenudialog.h"
#include "tophighscores.h"
#include "interfaces/iactor.hh"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QScreen>
#include <QCoreApplication>
#include <QSettings>
#include <memory>
#include <map>
#include <QGraphicsPixmapItem>


std::shared_ptr<playerGameScore> smartPlayerScore =
        std::make_shared<playerGameScore>();
std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*> smartActors;
QString playerAliasName;
QTime _gameTime;

int main(int argc, char *argv[])
{
    using std::shared_ptr;
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Tampere University");
    QCoreApplication::setApplicationName("BusDestroyer2000");
    QSettings mySettings;

    /*topHighScores *n = new topHighScores;
    n->writeFile();
    n->readFile();*/

    Q_INIT_RESOURCE(offlinedata);

    MainMenuDialog * menuUi = new MainMenuDialog();


    menuUi->exec();




    return a.exec();
}

