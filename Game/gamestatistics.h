#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

#include "../Course/CourseLib/interfaces/istatistics.hh"
#include "interfaces/istop.hh"
#include "interfaces/ipassenger.hh"
#include "interfaces/iactor.hh"
#include "playergamescore.h"
#include "assert.h"



#include <map>
#include <memory>
#include <QObject>
#include <QGraphicsPixmapItem>
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

    int passengersDead;
    int destroyedNysses;
    int totalPassengers;
    int totalNysses;
    int leftNysses;
    int collectedDiamonds;

private:
     std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*>::iterator _it;


};

#endif // GAMESTATISTICS_H
