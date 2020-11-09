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


class Player:  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent= 0);
    ~Player();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent * event);
    void movePlayer();
    void setDimensions();
    void changePlayerSpeed(QKeyEvent *speedEvent);
    void addPlayerSprite();
    void initMusic();
    void configureMusic();
    void setMusicChoice();
    void savePlayerName();
    void removeCollidingItem();
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

#endif // PLAYER_H
