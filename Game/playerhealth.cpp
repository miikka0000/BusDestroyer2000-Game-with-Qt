#include "playerhealth.h"

playerHealth::playerHealth(QObject *parent) : QObject(parent)
{
    playerHealtPoints = 50;
}

playerHealth::~playerHealth()
{

}

void playerHealth::decreaseHealth()
{
    if(playerHealtPoints > 0){
        playerHealtPoints -= 1;
    }
}


