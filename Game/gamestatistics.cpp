#include "gamestatistics.h"
#include "errors/gameerror.hh"


gameStatistics::gameStatistics()
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

/**
 * @brief givePoints returns current score in the game.
 * @pre -
 * @return score
 * @post Exception guarantee: nothrow
 */

int gameStatistics::givePoints() const
{
    return playerPoints;
}

/**
 * @brief passengerDied notifies, that the passanger is dead.
 * @param num how many passangers eliminated.
 * @pre num > 0
 * @post Exception guarantee: strong
 */
void gameStatistics::passengerDied(int num)
{

    if(num > 0){
        passengersDead += num;
    } else{
        throw Interface::GameError("Amount of dead passengers can't be negative.");

    }
}

/**
 * @brief morePassengers notifies, that more passangers are added to the game.
 * @param num how many new passangers are added.
 * @pre num > 0
 * @post Exception guarantee: strong
 */
void gameStatistics::morePassengers(int num)
{

    if(num > 0){
        totalPassengers += num;
    } else{
        throw Interface::GameError("Added passenger amount can't be negative");
    }

}

/**
 * @brief nysseRemoved notifies, that the nysse is removed ingame.
 * @pre -
 * @post Exception guarantee: strong
 */
void gameStatistics::nysseRemoved()
{
    removedNysses += 1;
}

/**
 * @brief newNysse notifies, that a new nysse is added to the game.
 * @pre -
 * @post Exception guarantee: strong
 */
void gameStatistics::newNysse()
{
    totalNysses += 1;
}

/**
 * @brief nysseLeft notifies, that a nysse has left the game.
 * @pre -
 * @post Exception guarantee: strong
 */
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
