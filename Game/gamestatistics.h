#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

#include "../Course/CourseLib/interfaces/istatistics.hh"
#include "../Course/CourseLib/interfaces/istop.hh"
#include "../Course/CourseLib/interfaces/ipassenger.hh"
#include "../Course/CourseLib/interfaces/iactor.hh"

#include <map>
#include <memory>
#include <QObject>
#include <QDebug>

class gameStatistics : public Interface::IStatistics
{

public:

    gameStatistics();

    /**
     * @brief givePoints returns current score in the game.
     * @pre -
     * @return score
     * @post Exception guarantee: nothrow
     */
    virtual int givePoints() const;

    /**
     * @brief passengerDied notifies, that the passanger is dead.
     * @param num how many passangers eliminated.
     * @pre num > 0
     * @post Exception guarantee: strong
     */
    virtual void passengerDied(int num);

    /**
     * @brief morePassengers notifies, that more passangers are added to the game.
     * @param num how many new passangers are added.
     * @pre num > 0
     * @post Exception guarantee: strong
     */
    virtual void morePassengers(int num);

    /**
     * @brief nysseRemoved notifies, that the nysse is removed ingame.
     * @pre -
     * @post Exception guarantee: strong
     */
    virtual void nysseRemoved();

    /**
     * @brief newNysse notifies, that a new nysse is added to the game.
     * @pre -
     * @post Exception guarantee: strong
     */
    virtual void newNysse();

    /**
     * @brief nysseLeft notifies, that a nysse has left the game.
     * @pre -
     * @post Exception guarantee: strong
     */
    virtual void nysseLeft();

    void addPoints() {playerPoints += 10;};
    void addCollectedDiamond();
    void passengerLeft();
    void actorMoved();
    int giveCollectedDiamonds(){return collectedDiamonds;};
    int giveDestroyedNysses() {return removedNysses;};
    int giveDestroyedPassengers() {return passengersDead;};
    void initAllValues();

    int playerPoints = 0;
    int passengersDead = 0;
    int removedNysses = 0;
    int totalPassengers = 0;
    int totalNysses = 0;
    int leftNysses = 0;
    int leftPassengers = 0;
    int collectedDiamonds = 0;
    int movedActorsAmount = 0;

};

#endif // GAMESTATISTICS_H
