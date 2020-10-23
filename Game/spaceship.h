#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QSoundEffect>


class Spaceship:  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Spaceship(QGraphicsItem *parent= 0);
    ~Spaceship();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent * event);
    void moveSpaceship();
    void setDimensions();

    int spaceshipHeight_;
    int spaceshipWidth_;

    struct dimensions {
        int screenWidth_ = 800;
        int screenHeight_ = 600;

    };

    //bool keyLeft, keyRight, keySpace, keyUp, keyDown;


private:
    int spaceshipVelocity_ = 50;
    int projectileVelocity_ = 20;
    QSoundEffect *projectileSound;

    bool keyLeft=false;
    bool keyRight=false;
    bool keyUp=false;
    bool keyDown=false;
    bool keySpace=false;




};

#endif // PLAYER_H
