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
    void setDimensions();

    int spaceshipHeight_;
    int spaceshipWidth_;

    struct dimensions {
        int screenWidth_ = 800;
        int screenHeight_ = 600;

    };
private:
    int spaceshipVelocity_ = 50;
    int projectileVelocity_ = 20;
    QSoundEffect *projectileSound;


};

#endif // PLAYER_H
