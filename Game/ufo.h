#ifndef UFO_H
#define UFO_H

#include "player.h"

class Ufo : public Player
{
public:
    Ufo();
    ~Ufo();


    const QPixmap ufoPic = QPixmap(":/images/ufo_sprite_50x50.png");
};

#endif // UFO_H
