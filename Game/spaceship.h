#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "player.h"

class Spaceship : public Player
{
public:
    Spaceship();
    ~Spaceship();

    const QPixmap spaceshipPic = QPixmap(":/images/spaceship_45x31.png");

};

#endif // SPACESHIP_H
