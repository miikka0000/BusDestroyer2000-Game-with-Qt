#include "mainmenudialog.h"
#include "gamestatistics.h"

#include <QApplication>
#include <QCoreApplication>
#include <QSettings>
#include <memory>
#include <map>
#include <QGraphicsPixmapItem>

std::shared_ptr<StudentSide::gameStatistics> smartStats =
        std::make_shared<StudentSide::gameStatistics>();
std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*> smartActors;
QString playerAliasName;
QTime _gameTime;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Tampere University");
    QCoreApplication::setApplicationName("BusDestroyer2000");
    QSettings mySettings;

    Q_INIT_RESOURCE(offlinedata);

    StudentSide::MainMenuDialog * menuUi = new StudentSide::MainMenuDialog();
    menuUi->exec();

    return a.exec();
}

