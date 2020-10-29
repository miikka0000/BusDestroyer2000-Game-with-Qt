#ifndef PLAYER_H
#define PLAYER_H
#include "mainmenudialog.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QTimer>
#include <QPixmap>
#include <QUrl>
#include <QString>



class Player:  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent= 0);
    ~Player();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent * event);
    void movePlayer();
    void setDimensions();
    void changePlayerSpeed(int delta);
    void addPlayerSprite();
    void initMusic(QUrl blasterSoundEffect);



    int playerHeight;
    int playerWidth;

    int screenWidth_ = 800;
    int screenHeight_= 600;
    const QPixmap spaceshipPic = QPixmap(":/images/spaceship_45x31.png");
    const QPixmap tankPic = QPixmap(":/images/tank_sprite_26x50.png");
    const QPixmap ufoPic = QPixmap(":/images/ufo_sprite_50x50.png");

    const QUrl blasterSound = QUrl("qrc:/sounds/blaster_sound.wav");

    int interval = 25;

    int x_;
    int y_;

    QString playerName;
    bool tankChosen = false;
    bool spaceshipChosen = false;
    bool ufoChosen = false;

public slots:
    void setPlayerNick(QString name);
    void setPlayerIcon(int type);


private:

    double spaceshipVelocity_ = 20.0;
    double projectileVelocity_ = 8.0;
    QSoundEffect *projectileSound;
    QTimer *moveTimer;

    bool keyLeft=false;
    bool keyRight=false;
    bool keyUp=false;
    bool keyDown=false;
    bool keySpace=false;




};

#endif // PLAYER_H
