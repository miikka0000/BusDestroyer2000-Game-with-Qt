#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QTimer>
#include <QPixmap>
#include <QUrl>


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
    void addPlayerSprite(QPixmap img);
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






    //bool keyLeft, keyRight, keySpace, keyUp, keyDown;
/*public slots:
    void setLimits(int w, int h);*/


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
