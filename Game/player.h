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



class Player:  public QObject, public QGraphicsPixmapItem{
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
    void increasePoints() {playerScore += 10;};
    int getScore() {return playerScore;};
    int getHealthPoints() {return playerHealth;};
    std::vector<int> getPlayerOrigin(int width, int height);

    int playerHeight;
    int playerWidth;
    int screenWidth = 800;
    int screenHeight = 600;
    QPixmap spaceshipPic = QPixmap(":/images/spaceship_45x31.png");
    QPixmap tankPic = QPixmap(":/images/tank_sprite_26x50.png");
    QPixmap ufoPic = QPixmap(":/images/ufo_sprite_50x50.png");

    const QUrl blasterSound = QUrl("qrc:/sounds/blaster_sound.wav");
    const QUrl fireballSound = QUrl("qrc:/sounds/fireballSound.wav");
    const QUrl missileSound = QUrl("qrc:/sounds/missileSound.wav");

    std::string playerName;
    bool tankChosen;
    bool spaceshipChosen;
    bool ufoChosen;
    bool fireballChosen;
    bool missileChosen;
    bool laserChosen;

    bool musicsOn;

    int playerScore = 0;
    int playerHealth = 3;



private:


    double _spaceshipVelocity = 20.0;
    double _projectileVelocity = 8.0;
    QSoundEffect *_projectileSound;
    QTimer *_moveTimer;
    int _interval = 25;
    bool _keyLeft = false;
    bool _keyRight = false;
    bool _keyUp = false;
    bool _keyDown = false;
    bool _keySpace = false;

    std::shared_ptr<QSettings> _playerSettings = std::make_shared<QSettings>();

};

#endif // PLAYER_H
