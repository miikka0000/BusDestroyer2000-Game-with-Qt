#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

#include "../Course/CourseLib/interfaces/istatistics.hh"
#include "../Course/CourseLib/interfaces/istop.hh"
#include "../Course/CourseLib/interfaces/ipassenger.hh"
#include "../Course/CourseLib/interfaces/iactor.hh"
#include "playergamescore.h"
#include "assert.h"



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

    void collectBonus();
    void addPoints() {playerPoints += 10;};
    void addCollectedDiamond() {collectedDiamonds += 1;};
    void passengerLeft();
    void actorMoved();
    int giveCollectedDiamonds(){return collectedDiamonds;};

    int playerPoints;
    int passengersDead;
    int removedNysses;
    int totalPassengers;
    int totalNysses;
    int leftNysses;
    int leftPassengers;
    int collectedDiamonds;
    int movedActorsAmount;

private:
     //std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*>::iterator _it;


};

#endif // GAMESTATISTICS_H
