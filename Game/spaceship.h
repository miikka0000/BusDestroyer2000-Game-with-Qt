#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QTimer>
#include <QPixmap>
#include <QUrl>


class Spaceship:  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Spaceship(QGraphicsItem *parent= 0);
    ~Spaceship();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent * event);
    void moveSpaceship();
    void setDimensions();
    void changePlayerSpeed(int delta);


    int spaceshipHeight_;
    int spaceshipWidth_;

    int screenWidth_ = 800;
    int screenHeight_= 600;
    const QPixmap shipPic = QPixmap(":/images/spaceship.png");
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
