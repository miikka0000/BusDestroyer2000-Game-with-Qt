#include "gamestatistics.h"

extern std::shared_ptr<playerGameScore> smartPlayerScore;

gameStatistics::gameStatistics(QObject *parent) : QObject(parent)
{
    passengersDead = 0;
    destroyedNysses = 0;
    totalPassengers = 0;
    totalNysses = 0;
    leftNysses = 0;
    collectedDiamonds = 0;
}

gameStatistics::~gameStatistics()
{

}

/**
 * @brief givePoints returns current score in the game.
 * @pre -
 * @return score
 * @post Exception guarantee: nothrow
 */
int gameStatistics::givePoints() const
{
    return smartPlayerScore->getPlayerScore();
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
    }
}

/**
 * @brief nysseRemoved notifies, that the nysse is removed ingame.
 * @pre -
 * @post Exception guarantee: strong
 */
void gameStatistics::nysseRemoved()
{
    destroyedNysses += 1;
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

}

void gameStatistics::collectBonus()
{
    collectedDiamonds += 1;
}
