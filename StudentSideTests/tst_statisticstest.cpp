#include "gamestatistics.h"
#include "../Course/CourseLib/interfaces/istatistics.hh"
#include "../Course/CourseLib/errors/gameerror.hh"

#include <QtTest>
#include <QObject>

// add necessary includes here

class statisticstest : public QObject
{
    Q_OBJECT

public:
    statisticstest();
    ~statisticstest();

private slots:
    void testGivePoints();
    void testPassengerDied();
    void testNysseRemoved();
    void testMorePassengers();
    void testNewNysse();
    void testNysseLeft();
    void addCollectedDiamond();
    void testActorMoved();
    void testPassengerLeft();
    void testAddPoints();

};

statisticstest::statisticstest()
{

}

statisticstest::~statisticstest()
{

}

void statisticstest::testGivePoints()
{
    gameStatistics test;
    QCOMPARE(test.givePoints(), 0);
}

void statisticstest::testPassengerDied()
{
    gameStatistics test;
    QVERIFY_EXCEPTION_THROWN(test.passengerDied(-1), Interface::GameError);
}

void statisticstest::testNysseRemoved()
{
    gameStatistics test;
    test.nysseRemoved();
    QCOMPARE(test.removedNysses, 1);

}

void statisticstest::testMorePassengers()
{
    gameStatistics test;
    QVERIFY_EXCEPTION_THROWN(test.morePassengers(-1), Interface::GameError);
}

void statisticstest::testNewNysse()
{
    gameStatistics test;
    test.newNysse();
    QCOMPARE(test.totalNysses, 1);
}

void statisticstest::testNysseLeft()
{
    gameStatistics test;
    test.nysseLeft();
    QCOMPARE(test.leftNysses, 1);
}

void statisticstest::addCollectedDiamond()
{
    gameStatistics test;
    test.addCollectedDiamond();
    QCOMPARE(test.giveCollectedDiamonds(), 1);
}

void statisticstest::testActorMoved()
{
    gameStatistics test;
    test.actorMoved();
    QCOMPARE(test.movedActorsAmount, 1);
}

void statisticstest::testPassengerLeft()
{
    gameStatistics test;
    test.passengerLeft();
    QCOMPARE(test.leftPassengers, 1);
}

void statisticstest::testAddPoints()
{
    gameStatistics test;
    test.addPoints();
    QCOMPARE(test.playerPoints, 10);
}

QTEST_APPLESS_MAIN(statisticstest)

#include "tst_statisticstest.moc"
