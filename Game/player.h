#ifndef PLAYER_H
#define PLAYER_H

#include "mainmenudialog.h"
#include "basicprojectile.h"

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QTimer>
#include <QPixmap>
#include <QUrl>
#include <QString>
#include <vector>
#include <QSettings>
#include <string>
#include <memory>

/**
 * @brief
 * All of the classes done by us are found in StudentSide namespace.
 */
namespace StudentSide {

/**
  * @brief Defines a class for the main player that the game's user controls in the game.
  * The player can be in interaction with bonusItems, Nysses and passengers shown on the game map.
  * Player movement happens via arrow key pressing, and shooting via space bar.
  */
class Player:  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor of the class. As a default, parent is set to a nullpointer to QGraphicsItem.
      * @post Player is at initialization state.
      */
    Player(QGraphicsItem *parent= 0);

    /**
      * @brief Player has a basic destructor.
      */
    ~Player();

    /**
     * @brief keyPressEvent checks which keys are being pressed during the game in MainWindow to enable smooth player transitions in the game map.
     * @param QKeyEvent when player presses arrow or space keys ingame.
     * @pre The game has started and gameWindow is active and responsive.
     * @post Keys that are pressed ingame are set to "true". Exception guarantee: nothrow.
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief keyReleaseEvent checks which keys are being released during the game in MainWindow to enable smooth player transitions in the game map.
     * @param QKeyEvent when player releases arrow or space keys ingame.
     * @pre The game has started and gameWindow is active and responsive.
     * @post Keys that are released ingame are set to "false". Exception guarantee: nothrow.
     */
    void keyReleaseEvent(QKeyEvent * event);

    /**
     * @brief movePlayer function is responsible for moving the player in the game map.
     * @pre -
     * @post Bullet has moved in the map and is deleted from the scene and the memory if it encounters a object in its way or exits the game screen. Exception guarantee: nothrow.
     */
    void movePlayer();

    /**
     * @brief setDimensions sets the width and the height of a chosen player type.
     * @pre Chosen player type is existent and therefore has some kind of dimensions.
     * @post Dimensions for the player projectile type are successfully set. Exception guarantee: nothrow.
     */
    void setDimensions();

    /**
     * @brief changePlayerSpeed increases (if "+"-key is pressed) or decreases (if "-"-key is pressed) player speed during the game within reasonable limits. Each increase or decrease is at 5 % delta.
     * @param QKeyEvent when player presses "+" or "-" key ingame.
     * @pre The game has started and gameWindow is active and responsive.
     * @post Player speed has been changed if certain keys have been pressed ingame. Exception guarantee: nothrow.
     */
    void changePlayerSpeed(QKeyEvent *speedEvent);

    /**
     * @brief addPlayerSprite sets the the chosen picture as the player icon in the game.
     * @pre Player pictures provided are valid and they exist.
     * @post Player picture for the chosen player type is set. Exception guarantee: nothrow.
     */
    void addPlayerSprite();

    /**
     * @brief initMusic initializes the QSoundEffect object according to the projectile type chosen by the player. Every porjectile tupe has an unique sound: fireball has a magic cast, missile an explosion and laser a blaster sound effect.
     * @pre -
     * @post QSoundEffect has been initialized according to the chosen projectile type. Exception guarantee: nothrow.
     */
    void initMusic();

    /**
     * @brief configureMusic checks is the sound is being played ingame at the time of the function call. It plays the music if needed to and also sets the music volume to a player-friendly level.
     * @pre Music has been opted in by the player.
     * @post Exception guarantee: nothrow.
     */
    void configureMusic();

    /**
     * @brief setMusicChoice checks the music setting and acts accordingly: if the music has been opted in, then it calls the configureMusic() -method or otherwise it does not do anything.
     * @pre -
     * @post Exception guarantee: nothrow.
     */
    void setMusicChoice();

    /**
     * @brief savePlayerName saves player name (in std::string format) chosen by the player into Player-class attribute.
     * @pre -
     * @post Player name has been saved correctly. Exception guarantee: nothrow.
     */
    void savePlayerName();

    /**
     * @brief removeCollidingItem is responsible for removing the bonus diamonds that are in contact with the player from the scene and memory. It also increases player points and updates the changes to the gameStatistics if a bonus diamond is collected by the player.
     * @pre Player comes in contact with a bonus diamond in the game map.
     * @post Collected diamond is deleted from the game map and memory or nothing happens. Exception guarantee: nothrow.
     */
    void removeCollidingItem();

    /**
     * @brief getPlayerOrigin gets chosen player type's center coordinates and returns them in a vector.
     * @param Player icon's width and height.
     * @pre -
     * @return Vector containing player icon's origin coordinates: x-coordinate is at index 0 and y-coordinate is at index 1.
     * @post Exception guarantee: nothrow.
     */
    std::vector<int> getPlayerOrigin(int width, int height);

    int playerHeight;
    int playerWidth;
    int screenWidth = 800;
    int screenHeight = 600;
    std::string playerName;

private:
    double _spaceshipVelocity = 23.0;
    QSoundEffect *_projectileSound;
    QTimer *_moveTimer;
    int _interval = 50;

    bool _keyLeft = false;
    bool _keyRight = false;
    bool _keyUp = false;
    bool _keyDown = false;
    bool _keySpace = false;

    bool _tankChosen = false;
    bool _spaceshipChosen = false;
    bool _ufoChosen = false;
    bool _fireballChosen = false;
    bool _missileChosen = false;
    bool _laserChosen = false;
    bool _musicsOn = false;

    std::shared_ptr<QSettings> _playerSettings = std::make_shared<QSettings>();

    const QPixmap _spaceshipPic = QPixmap(":/images/spaceship_45x31.png");
    const QPixmap _tankPic = QPixmap(":/images/tank_sprite_26x50.png");
    const QPixmap _ufoPic = QPixmap(":/images/ufo_sprite_50x50.png");

    const QUrl _blasterSound = QUrl("qrc:/sounds/blaster_sound.wav");
    const QUrl _fireballSound = QUrl("qrc:/sounds/fireballSound.wav");
    const QUrl _missileSound = QUrl("qrc:/sounds/missileSound.wav");

};
}
#endif // PLAYER_H
