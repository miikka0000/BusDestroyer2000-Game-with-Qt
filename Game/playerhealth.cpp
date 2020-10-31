#include "playerhealth.h"


playerHealth::playerHealth(QGraphicsItem *parent): QGraphicsTextItem(parent){

    _healthPoints = 3;

    setDefaultTextColor(Qt::red);
}
void playerHealth::decreaseHealth(){
    _healthPoints--;

}

int playerHealth::increaseHealth(){
    return _healthPoints;
}
