#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "player.h"
#include "basicprojectile.h"

#include "bonusitem.h"

#include "gamecity.h"
#include "interfaces/icity.hh"
#include "core/logic.hh"


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QPalette>
#include <QImage>
#include <QBrush>
#include <QPaintEvent>
#include <vector>
#include <QColor>
#include <QSettings>
#include <memory>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    void resizeEvent(QResizeEvent * event);
    void setPicture(QImage img);
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void setLCDStyle();
    void spawnBonusItem();
    void addDataToLCD();
    void setGameTime();



    std::shared_ptr<Interface::ICity> createGame();




    //void keyReleaseEvent(QKeyEvent * keyEvent);

    std::vector<int> getAvailableSize();
    MainMenuDialog *giveDialog() {return _mainMenu;};


    BonusItem *bonusObject;
    //QTime gameTime(0,0,0);

    int screenWidth = 800;
    int screenHeight = 600;

    int interval = 500;
    QImage bkgndSmall = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage bkgndBig = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

public slots:
    void updateCountDown();
private:
    Ui::GameWindow *ui;
    QTimer *mainTimer;
    QTimer *bonusTimer;
    QTimer *gameTimer;
    //QTime *gameTime;
    int _gameDuration;
    QGraphicsScene * _scene;
    Player * _player;
    QPixmap _pixmapBg = QPixmap(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    bool _largeMode = false;
    MainMenuDialog *_mainMenu;
    std::shared_ptr<QSettings> _playerSettings = std::make_shared<QSettings>();


};

#endif // GAMEWINDOW_H
