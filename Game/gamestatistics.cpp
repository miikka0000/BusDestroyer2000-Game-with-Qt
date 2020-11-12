#include "gamestatistics.h"
#include "errors/gameerror.hh"

namespace StudentSide {

gameStatistics::gameStatistics()
{
}

int gameStatistics::givePoints() const
{
    return playerPoints;
}

void gameStatistics::passengerDied(int num)
{
    if(num > 0){
        passengersDead += num;

    } else{
        throw Interface::GameError("Amount of dead passengers can't be negative.");
    }
}

void gameStatistics::morePassengers(int num)
{
    if(num > 0){
        totalPassengers += num;

    } else{
        throw Interface::GameError("Added passenger amount can't be negative");
    }
}

void gameStatistics::nysseRemoved()
{
    removedNysses += 1;
}

void gameStatistics::newNysse()
{
    totalNysses += 1;
}

void gameStatistics::nysseLeft()
{
    leftNysses += 1;
}

void gameStatistics::addCollectedDiamond()
{
    collectedDiamonds += 1;
}

void gameStatistics::passengerLeft()
{
    leftPassengers += 1;
}

void gameStatistics::actorMoved()
{
    movedActorsAmount += 1;
}

void gameStatistics::initAllValues()
{
    playerPoints = 0;
    passengersDead = 0;
    removedNysses = 0;
    totalPassengers = 0;
    totalNysses = 0;
    leftNysses = 0;
    collectedDiamonds = 0;
    leftPassengers = 0;
    movedActorsAmount = 0;
}
}
