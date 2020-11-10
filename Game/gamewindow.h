#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "player.h"
#include "basicprojectile.h"
#include "initgame.h"
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


/**
  * @brief Defines an interface that reperesents the gameWindow's User Interface (Ui).
  */
namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor of the class. As a default, parent is set to a nullpointer to QWidget.
      * @post basicProjectile is at initialization state.
      */
    explicit GameWindow(QWidget *parent = nullptr);

    /**
      * @brief GameOverDialog has a basic destructor.
      */
    ~GameWindow();

    void resizeEvent(QResizeEvent * event);
    void setPicture(QImage img);
    void setLCDStyle();
    void spawnBonusItem();
    void addDataToLCD();
    void setGameTime();
    void screenFrameUpdate();
    void stopTimers();
    std::vector<int> getAvailableSize();

    int screenWidth = 800;
    int screenHeight = 600;

public slots:
    void updateCountDown();

private:
    Ui::GameWindow *ui;
    QTimer *_mainTimer;
    QTimer *_bonusTimer;
    QTimer *_gameTimer;
    QTimer *_labelTimer;
    MainMenuDialog *_mainMenu;
    QGraphicsScene * _scene;
    initGame * _newGame;
    Player * _player;
    std::shared_ptr<QSettings> _playerSettings = std::make_shared<QSettings>();
    bool _largeMode = false;
    int _gameDuration;
    int _frameRate = 20;
    int _interval = 500;
    int _countDownInterval = 1000;
    int _spawnBonusInterval = 4000;
    const QImage _bkgndSmall = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    const QImage _bkgndBig = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");





};

#endif // GAMEWINDOW_H
