#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

#include "../Course/CourseLib/interfaces/istatistics.hh"
#include "../Course/CourseLib/interfaces/istop.hh"
#include "../Course/CourseLib/interfaces/ipassenger.hh"
#include "../Course/CourseLib/interfaces/iactor.hh"

#include <map>
#include <memory>
#include <QObject>

/**
 * @brief
 * All of the classes done by the student team are found in StudentSide namespace.
 */
namespace StudentSide {

/**
  * @brief Defines a class that inherits from IStatistics and implements its virtual functions. In addition class has some own functions and attributes.
  * Class is responsible for the statistical bookkeeping for all the relevant statistics that the player generates ingame.
  */
class gameStatistics : public Interface::IStatistics
{

public:
    /**
      * @brief Basic constructor for gameStatistics.
      * @post gameStatistics is at initialization state.
      */
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
     * @exception GameError number given as a paremeter is negative.
     */
    virtual void passengerDied(int num);

    /**
     * @brief morePassengers notifies, that more passangers are added to the game.
     * @param num how many new passangers are added.
     * @pre num > 0
     * @post Exception guarantee: strong
     * @exception GameError number given as a paremeter is negative.
     */
    virtual void morePassengers(int num);

    /**
     * @brief nysseRemoved notifies, that the nysse is removed ingame.
     * @pre -
     * @post Exception guarantee: nothrow.
     */
    virtual void nysseRemoved();

    /**
     * @brief newNysse notifies, that a new nysse is added to the game.
     * @pre -
     * @post Exception guarantee: nothrow.
     */
    virtual void newNysse();

    /**
     * @brief nysseLeft notifies, that a nysse has left the game.
     * @pre -
     * @post Exception guarantee: nothrow.
     */
    virtual void nysseLeft();

    /**
     * @brief addPoints function increases the player points by 10.
     * @pre -
     * @post Player's points have been increased by 10. Exception guarantee: nothrow.
     */
    void addPoints() {playerPoints += 10;};

    /**
     * @brief addCollectedDiamond function increases the collected diamonds by 1.
     * @pre -
     * @post Player's collected diamond count has been increased by 1. Exception guarantee: nothrow.
     */
    void addCollectedDiamond();

    /**
     * @brief passengerLeft function increases passengers that left ingame count by 1.
     * @pre -
     * @post Passenger left ingame count has been increased by 1. Exception guarantee: nothrow.
     */
    void passengerLeft();

    /**
     * @brief actorMoved function increases the actors moved ingame count by 1.
     * @pre -
     * @post Actors moved ingame count has been increased by 1. Exception guarantee: nothrow.
     */
    void actorMoved();

    /**
     * @brief initAllValues function initializes all the gameStatistics class public attributes to zero.
     * @pre -
     * @post gameStatistics class public attributes have all been set to zero. Exception guarantee: nothrow.
     */
    void initAllValues();

    /**
     * @brief giveCollectedDiamonds returns the amount of collected diamonds by the player at the time when the function is called.
     * @pre -
     * @return Integer amount of collected diamonds by the player.
     * @post The amount of collected diamonds has been returned. Exception guarantee: nothrow.
     */
    int giveCollectedDiamonds(){return collectedDiamonds;};

    /**
     * @brief giveDestroyedNysses returns the amount of destroyed Nysse-buses by the player at the time when the function is called.
     * @pre -
     * @return Integer amount of destroyed Nysses by the player.
     * @post The amount of destroyed Nysses has been returned. Exception guarantee: nothrow.
     */
    int giveDestroyedNysses() {return removedNysses;};

    /**
     * @brief giveDestroyedPassengers returns the amount of destroyed passengers by the player at the time when the function is called.
     * @pre -
     * @return Integer amount of destroyed passengers by the player.
     * @post The amount of destroyed passengers has been returned. Exception guarantee: nothrow.
     */
    int giveDestroyedPassengers() {return passengersDead;};

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
}
#endif // GAMESTATISTICS_H
