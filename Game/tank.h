#ifndef TANK_H
#define TANK_H

#include "player.h"

class Tank : public Player
{
public:
    Tank();
    ~Tank();

    const QPixmap tankPic = QPixmap(":/images/tank_sprite_26x50.png");

};

#endif // TANK_H
