#ifndef GAMESETUPDATA_H
#define GAMESETUPDATA_H

#include <QObject>
#include <QString>
namespace setUp {

class gameSetUpData : public QObject
{
    Q_OBJECT
public:
    explicit gameSetUpData(QObject *parent = nullptr);    
    ~gameSetUpData();

    void setTrue(bool param) {param = true;};
    void setFalse(bool param) {param = false;};

    QString playerName;
    bool tankChosen = false;
    bool spaceshipChosen = false;
    bool ufoChosen = false;
    bool fireballChosen = false;
    bool missileChosen = false;
    bool laserChosen = false;

    bool musicsOn = false;

signals:

};
}

#endif // GAMESETUPDATA_H
