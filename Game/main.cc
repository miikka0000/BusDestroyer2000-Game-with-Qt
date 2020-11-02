#include "player.h"
#include "playergamescore.h"
#include "playerhealth.h"
#include "gamewindow.h"
#include "mainmenudialog.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QScreen>
#include <QCoreApplication>
#include <QSettings>
#include <memory>


std::shared_ptr<playerGameScore> smartPlayerScore =
        std::make_shared<playerGameScore>();
std::shared_ptr<playerHealth> smartPlayerHealth =
        std::make_shared<playerHealth>();
QTime _gameTime;

int main(int argc, char *argv[])
{
    using std::shared_ptr;
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Tampere University");
    QCoreApplication::setApplicationName("BusDestroyer2000");
    QSettings mySettings;

    Q_INIT_RESOURCE(offlinedata);

    MainMenuDialog * menuUi = new MainMenuDialog();


    menuUi->exec();




    return a.exec();
}

