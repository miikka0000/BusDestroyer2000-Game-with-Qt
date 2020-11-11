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
#include <QResizeEvent>


/**
  * @brief Defines an interface that reperesents the gameWindow's User Interface (Ui).
  */
namespace Ui {
class gameWindow;
}

class gameWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor of the class. As a default, parent is set to a nullpointer to QWidget.
      * @post gameWindow is at initialization state.
      */
    explicit gameWindow(QWidget *parent = nullptr);

    /**
      * @brief gameWindow has a basic destructor.
      */
    ~gameWindow();

    /**
     * @brief resizeEvent is responsible for the resizing of the gameWindow and reacting to it appropriately.
     * @param Raw pointer to the QResizeEvent.
     * @pre gameWindow's size is is in initialization state (800x600 pixels).
     * @post The new window size has been set and all the gamemap items scaled accordingly. Exception guarantee: nothrow.
     */
    void resizeEvent(QResizeEvent * event);

    /**
     * @brief setPicture sets the background picture for the game and scales it to the right dimensions if needed.
     * @param QImage picture of the big gamemap which is a courtesy from the Course Side.
     * @pre -
     * @post The backround picture of Tampere City Center has been set. Exception guarantee: nothrow.
     */
    void setPicture(QImage img);

    /**
     * @brief setLCDStyle styles the gameWindows top-panel QLCDNumber widgets.
     * @pre The QLCDNumber widgets exist.
     * @post The desired styles have been set. Exception guarantee: nothrow.
     */
    void setLCDStyle();

    /**
     * @brief spawnBonusItem creates a new raw pointer to the bonusItem object and adds it to the QGraphicsScene.
     * @pre -
     * @post A new bonusItem has been created and added to the scene. Exception guarantee: nothrow.
     */
    void spawnBonusItem();

    /**
     * @brief addDataToLCD is responsible for showing and updating the time-left count-down clock and player points on the QLCDNumber widgets.
     * @pre The QLCDNumber widgets exist.
     * @post The correct values have been updated to the gameWindow so that the player sees them. Exception guarantee: nothrow.
     */
    void addDataToLCD();

    /**
     * @brief setGameTime checks the player's game duration setting set in the settingsDialog and sets the game duration according to that.
     * @pre -
     * @post The correct game duration has been set for the game according to the player's choices. Exception guarantee: nothrow.
     */
    void setGameTime();

    /**
     * @brief screenFrameUpdate update QGraphicsView's viewport in predertimed timeout intervals.
     * @pre QGraphicsView has been created.
     * @post Cumulated changes in the QGraphicsView's viewport have been updated. Exception guarantee: nothrow.
     */
    void screenFrameUpdate();

    /**
     * @brief stopTimers stops all the QTimers used in gameWindow class.
     * @pre -
     * @post All the QTimers have been stopped. Exception guarantee: nothrow.
     */
    void stopTimers();

    /**
     * @brief getAvailableSize returns player's current available screen size.
     * @pre The game has started and gameWindow is active.
     * @return Vector containing the width (index 0) and the height (index 1) of the available screen.
     * @post Exception guarantee: strong.
     */
    std::vector<int> getAvailableSize();

    int screenWidth = 800;
    int screenHeight = 600;

public slots:
    /**
     * @brief updateCountDown substracts seconds from the game clock in 1000 ms intervals. Furthermore, it keeps track of time and shows GameOverDialog when the clock is zero.
     * @pre -
     * @post One second has been substracted from game time and/or the game is stopped and GameOverDialog is created and shown to the player. Exception guarantee: nothrow.
     */
    void updateCountDown();

private:
    Ui::gameWindow *ui;
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
