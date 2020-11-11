#include "gamestatistics.h"
#include "../Course/CourseLib/interfaces/istatistics.hh"
#include "../Course/CourseLib/errors/gameerror.hh"

#include <QtTest>
#include <QObject>

/**
  * @brief Unit tests for the gameStatistics class which inherits from Course Side's
  * iStatistics
  */
class statisticsTest : public QObject
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor for statisticsTest.
      * @post statisticsTest is at initialization state.
      */
    statisticsTest();

    /**
      * @brief statisticsTest has a basic destructor.
      */
    ~statisticsTest();

private slots:
    /**
      * @brief Testing give points -functionality.
      */
    void testGivePoints();

    /**
      * @brief Testing passenger died -functionality.
      */
    void testPassengerDied();

    /**
      * @brief Testing Nysse removed -functionality.
      */
    void testNysseRemoved();

    /**
      * @brief Testing more passengers -functionality.
      */
    void testMorePassengers();

    /**
      * @brief Testing new Nysse addition -functionality.
      */
    void testNewNysse();

    /**
      * @brief Testing Nysse left -functionality.
      */
    void testNysseLeft();

    /**
      * @brief Testing adding collected diamond -functionality.
      */
    void addCollectedDiamond();

    /**
      * @brief Testing actor removed -functionality.
      */
    void testActorMoved();

    /**
      * @brief Testing passenger left -functionality.
      */
    void testPassengerLeft();

    /**
      * @brief Testing adding points -functionality.
      */
    void testAddPoints();

};

statisticsTest::statisticsTest()
{
}

statisticsTest::~statisticsTest()
{
}

void statisticsTest::testGivePoints()
{
    gameStatistics test;
    QCOMPARE(test.givePoints(), 0);
}

void statisticsTest::testPassengerDied()
{
    gameStatistics test;
    QVERIFY_EXCEPTION_THROWN(test.passengerDied(-1), Interface::GameError);
}

void statisticsTest::testNysseRemoved()
{
    gameStatistics test;
    test.nysseRemoved();
    QCOMPARE(test.removedNysses, 1);
}

void statisticsTest::testMorePassengers()
{
    gameStatistics test;
    QVERIFY_EXCEPTION_THROWN(test.morePassengers(-1), Interface::GameError);
}

void statisticsTest::testNewNysse()
{
    gameStatistics test;
    test.newNysse();
    QCOMPARE(test.totalNysses, 1);
}

void statisticsTest::testNysseLeft()
{
    gameStatistics test;
    test.nysseLeft();
    QCOMPARE(test.leftNysses, 1);
}

void statisticsTest::addCollectedDiamond()
{
    gameStatistics test;
    test.addCollectedDiamond();
    QCOMPARE(test.giveCollectedDiamonds(), 1);
}

void statisticsTest::testActorMoved()
{
    gameStatistics test;
    test.actorMoved();
    QCOMPARE(test.movedActorsAmount, 1);
}

void statisticsTest::testPassengerLeft()
{
    gameStatistics test;
    test.passengerLeft();
    QCOMPARE(test.leftPassengers, 1);
}

void statisticsTest::testAddPoints()
{
    gameStatistics test;
    test.addPoints();
    QCOMPARE(test.playerPoints, 10);
}

QTEST_APPLESS_MAIN(statisticsTest)

#include "tst_statisticstest.moc"
