#include "playerpoints.h"




playerPoints::playerPoints(QGraphicsItem *parent): QGraphicsTextItem(parent){

    _playerScore = 0;


    setDefaultTextColor(Qt::blue);

}

void playerPoints::increasePoints(){
    _playerScore++;

}

int playerPoints::getPlayerScore(){
    return _playerScore;
}

