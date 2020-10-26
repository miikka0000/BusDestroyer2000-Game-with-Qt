#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QTimer>


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

    int screenWidth_;
    int screenHeight_;



    //bool keyLeft, keyRight, keySpace, keyUp, keyDown;
public slots:
    void setLimits(int w, int h);


private:
    int spaceshipVelocity_ = 50;
    int projectileVelocity_ = 20;
    QSoundEffect *projectileSound;
    QTimer *moveTimer;



    bool keyLeft=false;
    bool keyRight=false;
    bool keyUp=false;
    bool keyDown=false;
    bool keySpace=false;




};

#endif // PLAYER_H
