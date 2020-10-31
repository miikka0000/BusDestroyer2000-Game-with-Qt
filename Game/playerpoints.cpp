#include "playerpoints.h"




playerPoints::playerPoints(QGraphicsItem *parent): QGraphicsTextItem(parent){

    playerScore = 0;



}

void playerPoints::increasePoints(){
    playerScore += 10;

}



